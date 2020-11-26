/*WRITE A C++ PROGRAM FOR LINE DRAWING USING DDA OR BRESENHAM'S ALGORITHM WITH PATTERNS SUCH AS SOLID,DOTTED,DASHED,DASH-DOT,THICK*/
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class assn
{
public:
int x1,y1,x2,y2,w;

	void drawl(int,int,int,int);
	void thick(int,int,int,int,int);
	void dotted(int,int,int,int);
	void dashed(int,int,int,int);
};

void assn::thick(int x1,int y1,int x2,int y2, int w)
{
	int i,dx,dy,xinc,yinc,step;
	dx=x2-x1;
	dy=y2-y1;
	if(dy>=dx)
	{
		step=dy;
	}
	else
	{
		step=dx;
	}
		xinc=dx/step;
		yinc=dy/step;
		while(x1<=x2)
		{
			x1=x1+xinc+0.5;
			y1=y1+yinc+0.5;
			for(i=0;i<w;i++)
			{
				putpixel(x1+i,y1,5);
				delay(100);
			}
		}
}
void assn::drawl(int x1,int y1,int x2,int y2)
{

	int dx,dy,xinc,yinc,step;
	dx=x2-x1;
	dy=y2-y1;
	if(dy>dx)
	{
		step=dy;
	}
	else
	{
		step=dx;
	}
	xinc=dx/step;
	yinc=dy/step;
	putpixel(x1,y1,5);
	delay(100);
	while(x1<=x2)
	{
		x1=x1+xinc+0.5;
		y1=y1+yinc+0.5;
		putpixel(x1,y1,5);
		delay(100);
	}
}

void assn::dotted(int x1,int y1,int x2, int y2)
{
	int i,dx,dy,xinc,yinc,step;
	dx=x2-x1;
	dy=y2-y1;
	if(dy>dx)
	{
		step=dy;
	}
	else
	{
		step=dx;
	}
	xinc=dx/step;
	yinc=dy/step;
	putpixel(x1,y1,5);
	delay(100);
while(x1<=x2)
{
	if(i%2==0)
	{
		putpixel(x1,y1,5);delay(100);
	}
	x1=x1+xinc+0.5;
	y1=y1+yinc+0.5;
	i++;
}
}

void assn::dashed(int x1,int y1, int x2, int y2)
{
	int i,dx,dy,xinc,yinc,step;
	dx=x2-x1;
	dy=y2-y1;
	if(dy>dx)
	{
		step=dy;
	}
	else
	{
		step=dx;
	}
	xinc=dx/step;
	yinc=dy/step;
	putpixel(x1,y1,5);
	delay(100);
	while(x1<=x2)
	{
		if(i%8!=0)
		{
			cout<<" ";
			putpixel(x1,y1,5);
			delay(100);
		}
		x1=x1+xinc+0.5;
		y1=y1+yinc+0.5;
		i++;
	}
}
	int main()
	{
		assn p;
		int ch;
		cout<<"\nEnter the co-ordiantes of line: ";cin>>p.x1>>p.y1>>p.x2>>p.y2;
		cout<<"\nMENU \n1.Draw normal line \n2.Draw thick line \n3.Draw dotted line \n4.Draw dashed line \nEnter your choice: ";
		cin>>ch;
		if(ch==2)
		{
			cout<<"\nEnter width of the line: ";
			cin>>p.w;
		}
		int gd=DETECT,gm,n,i;
		initgraph(&gd,&gm,NULL);
		switch(ch)
		{
			case 1:
					p.drawl(p.x1,p.y1,p.x2,p.y2);
					getch();
					break;
			case 2:
					p.thick(p.x1,p.y1,p.x2,p.y2,p.w);
					getch();
					break;
			case 3: 
					p.dotted(p.x1,p.y1,p.x2,p.y2);
					getch();
					break;
			case 4:
					p.dashed(p.x1,p.y1,p.x2,p.y2);
					getch();
					break;
			default:
					cout<<"\nInvalid Choice! Enter proper choice! ";
		}
		closegraph();
		return 0;
	}
