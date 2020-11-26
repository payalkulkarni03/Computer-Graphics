/*WRITE A C++ PROGRAM TO DRAW INSCRIBED AND CIRCUMSCRIBED CIRCLE IN A TRIANGLE*/

#include<iostream>
#include<graphics.h>
#include<math.h>
#define ROUND(a)(int(a+0.5))
using namespace std;
class pattern{
private:
	int x1,y1,x2,y2,x3,y3;
public:
	void read();
	void draw_triangle();
	void dda(int xa,int ya,int xb,int yb);
	void circle(int x,int y,int rad);
	void display(int x1,int x2,int xa,int xb);
	void incircle();
	void excircle();
	void normal();
};
void pattern::read(){
	cout<<"Enter the co-ordinates of the triangle : "<<endl;
	cout<<"\nEnter X1 : ";
	cin>>x1;
	cout<<"\nEnter Y1 : ";
	cin>>y1;
	cout<<"\nEnter X2 : ";
	cin>>x2;
	cout<<"\nEnter Y2 : ";
	cin>>y2;
	cout<<"\nEnter X3 : ";
	cin>>x3;
	cout<<"\nEnter Y3 : ";
	cin>>y3;
}

void pattern::draw_triangle(){
	dda(x1,y1,x2,y2);
	dda(x2,y2,x3,y3);
	dda(x3,y3,x1,y1);
}


void pattern::dda(int xa,int ya,int xb,int yb){
	int dx,dy,steps;
	dx=xb-xa;
	dy=yb-ya;
	if(abs(dx)>=abs(dy))
		steps=abs(dx);
	else
		steps=abs(dy);
	float x=xa;
	float y=ya;
	float xinc,yinc;
		xinc=dx/float(steps);
		yinc=dy/float(steps);
		putpixel(ROUND(x),ROUND(y),3);
	for(int i=0;i<steps;i++){
		x=x+xinc;
		y=y+yinc;
		putpixel(ROUND(x),ROUND(y),3);
		delay(10);
		}
}

void pattern::circle(int x,int y,int rad){
	int x1=0;
	int y1=rad;
	putpixel(x1,y1,6);
	int S=3-2*rad;
	while(x1<=y1){
	if(S<=0){
	S=S+(4*x1)+6;
	}
	else{
	S=S+4*(x1-y1)+10;
	y1--;
	}
	x1++;
	putpixel(x+x1,y+y1,1);
	putpixel(x-x1,y+y1,2);
	putpixel(x+x1,y-y1,3);
	putpixel(x-x1,y-y1,4);
	putpixel(x+y1,y+x1,5);
	putpixel(x-y1,y+x1,6);
	putpixel(x+y1,y-x1,7);
	putpixel(x-y1,y-x1,8);
	delay(10);
	}

}

void pattern::incircle(){
	float a,b,c,area,rad,p;
	int xc,yc,mul;
	a=sqrt(pow((y2-y1),2)+pow((x2-x1),2));
	b=sqrt(pow((y3-y1),2)+pow((x3-x1),2));
	c=sqrt(pow((y3-y2),2)+pow((x3-x2),2));
	p=(a+b+c)/2;
	mul=p*(p-a)*(p-b)*(p-c);
	area=sqrt(mul);
	rad=area/p;
	xc=((c*x1)+(b*x2)+(a*x3))/(2*p);
	yc=((c*y1)+(b*y2)+(a*y3))/(2*p);
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	cout<<"c="<<c<<endl;
	cout<<"p="<<p<<endl;
	cout<<"area="<<area<<endl;
	cout<<"rad="<<rad<<endl;
	cout<<"xc="<<xc<<endl;
	cout<<"yc="<<yc<<endl;
  	circle(xc,yc,abs(rad));


}

void pattern::excircle(){
	float a,b,c;
	int xec,yec,exrad,A,B,C,D,E,F,G;
	a=sqrt(pow((y2-y1),2)+pow((x2-x1),2));
	b=sqrt(pow((y3-y1),2)+pow((x3-x1),2));
	c=sqrt(pow((y3-y2),2)+pow((x3-x2),2));
	exrad=(a*b*c)/(sqrt(a+b+c)*sqrt(a+b-c)*sqrt(a+c-b)*sqrt(b+c-a));
	A=x2-x1;
	B=y2-y1;
	C=x3-x1;
	D=y3-y1;
	E=(A*(x1+x2))+(B*(y1+y2));
	F=(C*(x3+x1))+(D*(y1+y3));
	G=2*((A*D)-(B*C));
	if(G==0)
	return;
	else
	{
	xec=(D*E-B*F)/G;
	yec=(A*F-C*E)/G;
	cout<<xec<<endl;
	cout<<yec;
	}
	circle(xec,yec,exrad);
}

void pattern::normal(){
	draw_triangle();
	incircle();
	excircle();
}


int main(){
	pattern p;
	p.read();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	p.normal();
	getch();
	closegraph();
	return 0;
}
