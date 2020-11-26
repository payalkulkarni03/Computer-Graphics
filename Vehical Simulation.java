/*WRITE A JAVA PROGRAM TO SIMULATE VEHICLE/BOAT LOCOMOTION*/

/* <applet code = Vehical.java width = 1200 height = 200> "CSE GuyS"</applet> */
import java.applet.*;
import java.awt.*;
public class Vehical extends Applet implements Runnable
{
        Thread t;

	int x = 10,x1=110;

	int y = 110,y1=110;

public void start()
{

	t = new Thread(this);

	t.start();

}
public void paint(Graphics g)
{

	g.setColor(Color.BLACK);
        g.fillRect(10, 80, 1000, 70);
        g.setColor(Color.YELLOW);
        g.fillRect(x-10, y-80,140, 80);
        g.setColor(Color.BLUE);
        g.drawString("**CSE**", x+10,y-40 );
        g.drawString("**GUYS**", x+50,y-20 );
        g.setColor(Color.PINK);
        g.fillOval(x,y-2,20,20);
        g.fillOval(x1,y1-2,20,20);

}
public void run()
{

	try

	{

		for(;;)

		{

  			 for(;;)

  			 {

     				 if (x1 >= 900 )

      				 {

       					  break;

     				 }

     				 else

    				   {

					x = x +3;

					x1 = x1 +3;

					Thread.sleep(400);

					repaint();

				}

         			run();

				}

			}

	}

	catch(InterruptedException e)

	{

	}

}
}
