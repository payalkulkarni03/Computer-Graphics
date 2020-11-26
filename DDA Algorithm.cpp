/*WRITE C++ PROGRAM TO DRAW LINE USING DDA AND BRESENHAM'S ALGORITHM*/
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class pixell
{
	protected:
		int x,y;
	public:
        void pixelprint();
};

void pixell::pixelprint()
{
	putpixel(x,y,2);
}

class line1:public pixell                         //class pixell is base class and line1 is Derived
{
  float dx,dy,s1,s2,temp,interchange,dx1,dy1,len;
  int x2,y2,x1,y1;
  public:
	void getdata();
	void line11(int);                         //Bresenham line draw
        void line11();                            //DDA line Draw ....Function overloading
	int sign(int,int);
};

void line1::getdata()
{
  cout<<"\nGive point 1 co-ordinate:";
  cout<<"\n\tGive point x co-ordinate = ";
  cin>>x1;
  cout<<"\n\tGive point y co-ordinate = ";
  cin>>y1;
  cout<<"\n\nGive point 2 co-ordinate = ";
  cout<<"\n\tGive point x co-ordinate = ";
  cin>>x2;
  cout<<"\n\tGive point y co-ordinate = ";
  cin>>y2;
}
void line1::line11()
{
  dx=x2-x1;
  dy=y2-y1;
      if(abs(dx)>=abs(dy))
      len=abs(dx);
      else
      len=abs(dy);
  dx1=dx/len;
  dy1=dy/len;
  x=x1+0.5;
  y=y1+0.5;
  int i=0;
	while(i<=len)
	{
  	  pixelprint();
	  x=x+dx1;
	  y=y+dy1;
	  i++;
	}
}
int line1::sign(int a,int b)
{
 if((a-b)<0)
 return -1;
 else if((a-b)>0)
 return 1;
 else
 return 0;
}
void line1::line11(int e)
{
  x=x1;
  y=y1;
  dx=abs(x2-x1);
  dy=abs(y2-y1);
  s1=sign(x2,x1);
  s2=sign(y2,y1);
  if(dy>dx)
   {
    temp=dx;
    dx=dy;
    dy=temp;
    interchange=1;
   }
  else
   interchange=0;
   e=2*dy-dx;
	for(int i=0;i<dx;i++)
	{
	    pixelprint();
	    while(e>=0)
	    {
	       if(interchange==1)
               x=x+s1;
               else
               y=y+s2;
               e=e-2*dx;
	    }
 	     if(interchange==1)
 	     y=y+s2;
 	     else
 	     x=x+s1;
   	   e=e+2*dy;
        }
}
int main()
{
  int choice;
  line1 a;
  char ans;
  do
  {
	cout<<"Line Drawing algorithm = \n\t1.DDA algorithm\n\t2.Bresenham algorithm\nGive the choice = ";
	cin>>choice;
	a.getdata();
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	switch(choice)
 		{
			case 1:
			a.line11();
			break;
			case 2:
			a.line11(0);
			break;
			
		}
	cin.ignore();
	getch();
	closegraph();
	cout<<"Do you want to continue (Y/N) = ";
	cin>>ans;
	cin.ignore();
  }while(ans=='Y' || ans=='y');
  return 0;
}


