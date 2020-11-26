/*WRITE A C++ PROGRAM TO IMPLEMENT TRANSLATION,SHEAR,ROTATION & SCALING TRANSFORMATION ON A 2-D OBJECT*/ 

#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
int main()
{
	int x1,y1,x2,y2,x3,y3,x4,y4,nx1,nx2,nx3,nx4,ny1,ny2,ny3,ny4;
	float shx,shy,sx,sy,ang,tx,ty;
	int ans;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	cout<<"Enter the shape:\n1.Traingle\n2.Rhombus\n"<<endl;
	cin>>ans;
	if(ans==1)
	{
		cout<<"Enter the co-ordinates of the triangle:"<<endl;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		line(x1,y1,x2,y2);
		line(x2,y2,x3,y3);
		line(x3,y3,x1,y1);
		cout<<"Enter the transformation to be performed:"<<endl;
		cout<<"1.Translation\n2.Scaling\n3.Rotation\n4.Sheer"<<endl;
		int ch;
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter the value of x-translation:"<<endl;
			cin>>tx;
			cout<<"Enter the value of y-translation:"<<endl;
			cin>>ty;
			nx1=x1+tx;
			ny1=y1+ty;
			nx2=x2+tx;
			ny2=y2+ty;
			nx3=x3+tx;
			ny3=y3+ty;
			line(nx1,ny1,nx2,ny2);
			line(nx2,ny2,nx3,ny3);
			line(nx3,ny3,nx1,ny1);
			getch();
		}
		else if(ch==2)
		{
			cout<<"Enter the value of x-scale:"<<endl;
			cin>>sx;
			cout<<"Enter the value of y-scale:"<<endl;
			cin>>sy;
			nx1=x1*sx;
			ny1=y1*sy;
			nx2=x2*sx;
			ny2=y2*sy;
			nx3=x3*sx;
			ny3=y3*sy;
			line(nx1,ny1,nx2,ny2);
			line(nx2,ny2,nx3,ny3);
			line(nx3,ny3,nx1,ny1);
			getch();
		}
		else if(ch==3)
		{
			cout<<"Enter the angle of rotation:"<<endl;
			cin>>ang;
			float t;
			t=(ang*3.14)/180;
			nx1=abs(x1*cos(t)-y1*sin(t));
			ny1=abs(x1*sin(t)+y1*cos(t));
			nx2=abs(x2*cos(t)-y2*sin(t));
			ny2=abs(x2*sin(t)+y2*cos(t));
			nx3=abs(x3*cos(t)-y3*sin(t));
			ny3=abs(x3*sin(t)+y3*cos(t));
			line(nx1,ny1,nx2,ny2);
			line(nx2,ny2,nx3,ny3);
			line(nx3,ny3,nx1,ny1);
			getch();
		}
		else
		{
			cout<<"Enter the value of x-shear:"<<endl;
			cin>>shx;
			cout<<"Enter the value of y-shear:"<<endl;
			cin>>shy;
			nx1=abs(x1+shx*y1);
			ny1=abs(y1+shy*x1);
			nx2=abs(x2+shx*y2);
			ny2=abs(y2+shy*x2);
			nx3=abs(x3+shx*y3);
			ny3=abs(y3+shy*x3);
			line(nx1,ny1,nx2,ny2);
			line(nx2,ny2,nx3,ny3);
			line(nx3,ny3,nx1,ny1);
			getch();
		}
	}
	getch();
	return 0;
}
