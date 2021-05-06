#include <iostream>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;
double x11=0,xn1=0,y11=0,yn1=0,m=0,dx,dy,cc;

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT); // clear the display
glColor3ub (128, 0, 0);
glPointSize(5.0);

glBegin(GL_POINTS);
glVertex2i(x11,y11);
while(cc)
{
    //cout << "ok";
    if(m<1)
    {
        //cout << "m<1";
    x11++;
    y11+=m;
    }
     else if(m>1)
    {
          //cout << "m>1";
    y11++;
    x11+=(1/m);
    }
    else
    {
          //cout << "m==1";
        x11++;
        y11++;
    } cc--;

    glVertex2i(floor(x11+0.5),floor(y11+0.5));
     //cout << x11 << " " << y11 << endl;
     //cout << floor(x11+0.5) << " " << floor(y11+0.5) << endl;
}
glEnd();
//cout << m;
glFlush ();
}

void myInit (void)
{
glClearColor(0.0, 0.0, 0.0, 0.0); // Background color
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


int main(int argc, char** argv)
{
    cin >> x11 >> y11;
    cin >> xn1 >> yn1;


    dx=abs(xn1-x11);
    dy=abs(yn1-y11);
     m=dy/dx;
      cout << m << " " << dx << " " << dy << endl;
     if(dy>dx) { cc=dy; }
     else { cc=dx; }

//get();
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // for setting up the display mode
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Assignment 3"); // title & make visibility
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
