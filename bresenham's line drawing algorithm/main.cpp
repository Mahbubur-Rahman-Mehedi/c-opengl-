#include <iostream>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;
double x11=0,xn1=0,y11=0,yn1=0,m=0,dx,dy,d;

void bla()
{
glBegin(GL_POINTS);

dx=xn1-x11;
dy=yn1-y11;

d=2*dy-dx;
cout << x11 << " " << y11 << endl;
glVertex2i(x11,y11);
if(x11==xn1)
{
    while(y11<yn1)
    {
    y11++;
    cout << x11 << " " << y11 << endl;
    glVertex2i(x11,y11);
    }
}
else{
while(x11<xn1)
{
    if(d<0) d+=(2*dy);
    else {
        d+=(2*(dy-dx));
        y11++;
    } x11++;
    cout << x11 << " " << y11 << endl;
    glVertex2i(x11,y11);
} }
glEnd();
 }

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT); // clear the display
glColor3ub (128, 0, 0);
//glPointSize(5.0);

bla();

glFlush ();
}

void myInit (void)
{
glClearColor(.0, 0.0, 0.0, 0.0); // Background color
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


int main(int argc, char** argv)
{
cout << "Please give initial points\n"; cin >> x11 >> y11; /// between 0-640 and 0-480
cout << "Please give final points\n"; cin >> xn1 >> yn1;

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // for setting up the display mode
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Bresenham's line drawing algorithm"); // title & make visibility
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
