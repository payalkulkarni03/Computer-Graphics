/*WRITE A C++ PROGRAM TO IMPLEMENT REFLECTION OF 2D OBJECT ABOUT X-AXIS,Y-AXIS AND X=Y AXIS. ALSO ROTATE OBJECT ABOUT ARBITRARY POINT GIVEN BY USER*/

#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
int main()
{
	int x1,y1,x2,y2,x3,y3,ang,ch,nx1,ny1,nx2,ny2,nx3,ny3,xmid,ymid,x,y;
	cout<<"Enter your choice:\n1.Reflection about x-axis\n2.Reflection about y-axis\n3.Reflection about y=x\n4.Rotation"<<endl;
	cin>>ch;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	cout<<"Enter the co-ordinates of the triangle:"<<endl;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	xmid=getmaxx()/2;
	ymid=getmaxy()/2;
	line(xmid,0,xmid,ymid*2);
	line(0,ymid,xmid*2,ymid);
	line(xmid+x1,ymid-y1,xmid+x2,ymid-y2);
	line(xmid+x2,ymid-y2,xmid+x3,ymid-y3);
	line(xmid+x3,ymid-y3,xmid+x1,ymid-y1);
	if(ch==1)
	{
		ny1=-y1;
		ny2=-y2;
		ny3=-y3;
		line(xmid+x1,ymid-ny1,xmid+x2,ymid-ny2);
		line(xmid+x2,ymid-ny2,xmid+x3,ymid-ny3);
		line(xmid+x3,ymid-ny3,xmid+x1,ymid-ny1);
		getch();
	}
	else if(ch==2)
	{
		nx1=-x1;
		nx2=-x2;
		nx3=-x3;
		line(xmid+nx1,ymid-y1,xmid+nx2,ymid-y2);
		line(xmid+nx2,ymid-y2,xmid+nx3,ymid-y3);
		line(xmid+nx3,ymid-y3,xmid+nx1,ymid-y1);
		getch();
	}
	else if(ch==3)
	{
		nx1=y1;
		ny1=x1;
		nx2=y2;
		ny2=x2;
		nx3=y3;
		ny3=x3;
		line(xmid+nx1,ymid-ny1,xmid+nx2,ymid-ny2);
		line(xmid+nx2,ymid-ny2,xmid+nx3,ymid-ny3);
		line(xmid+nx3,ymid-ny3,xmid+nx1,ymid-ny1);
		getch();
	}
	else
	{
		cout<<"Enter the angle of rotation:"<<endl;
		cin>>ang;
		cout<<"Enter the arbitrary point of rotation:"<<endl;
		cin>>x>>y;
		float t;
		t=(ang*3.142)/180;
		nx1=x1*cos(t)-y1*sin(t)-x1*cos(t)-y1*sin(t)+x1;
		ny1=x1*sin(t)+y1*cos(t)+x1*sin(t)-y1*cos(t)+y1;
		nx2=x2*cos(t)-y2*sin(t)-x2*cos(t)-y2*sin(t)+x2;
		ny2=x2*sin(t)+y2*cos(t)+x2*sin(t)-y2*cos(t)+y2;
		nx3=x3*cos(t)-y3*sin(t)-x3*cos(t)-y3*sin(t)+x3;
		ny3=x3*sin(t)+y3*cos(t)+x3*sin(t)-y3*cos(t)+y3;
		line(xmid+nx1,ymid-ny1,xmid+nx2,ymid-ny2);
		line(xmid+nx2,ymid-ny2,xmid+nx3,ymid-ny3);
		line(xmid+nx3,ymid-ny3,xmid+nx1,ymid-ny1);
		getch();
	}
	getch();
	closegraph();
	return 0;
}
