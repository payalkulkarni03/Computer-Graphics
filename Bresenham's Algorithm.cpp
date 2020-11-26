/*WRITE C++ PROGRAM TO DRAW CIRCLE USING BRESENHAM'S ALGORITHM. INHERIT PIXEL CLASS*/

#include<iostream>
#include <graphics.h>
#include <stdlib.h>
using namespace std;
class dcircle
{
	private: 
	int x0, y0;
	public:
	dcircle()
	{
	  x0=0;
	  y0=0;
	}
  void setoff(int xx, int yy)
  {
    x0=xx;
    y0=yy;
  }
  void drawc(int x1, int y1, int r)
  {
    float d;
    int x,y;
    x=0;
    y=r;
    d=3-2*r;

    do
     {
	putpixel(x1+x0+x, y0+y-y1, 15);
	putpixel(x1+x0+y, y0+x-y1,15);
	putpixel(x1+x0+y, y0-x-y1,15);
	putpixel(x1+x0+x, y0-y-y1,15);
	putpixel(x1+x0-x, y0-y-y1,15);
	putpixel(x1+x0-y, y0-x-y1,15);
	putpixel(x1+x0-y, y0+x-y1,15);
	putpixel(x1+x0-x, y0+y-y1,15);
	if (d<=0)
	{
	  d = d+4*x+6;
	}
	else
 	{
          d=d+4*(x-y)+10;
	  y=y-1;
	}

        x=x+1;
     }while(x<y); 
   }
};
int main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);
	int i,x,y,r,xmax,ymax,xmid,ymid;
	dcircle c;
	cout<<"\nenter coordinates of centre of circle";
	cout<<"\n enter the value of x";
	cin>>x;
	cout<<"\nenter the value of y";
	cin>>y;
	cout<<"\nenter the value of radius";
	cin>>r;
	
	xmax= getmaxx();
	ymax=getmaxy();
	xmid=xmax/2;
	ymid=ymax/2;
	setcolor(1);

	c.setoff(xmid,ymid);
	line(xmid, 0, xmid, ymax);
	line(0,ymid,xmax,ymid);
	setcolor(15);
	c.drawc(x,y,r);
	getch();
	delay(200);
	closegraph();
	return 0;
}
