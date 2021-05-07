#include <iostream>
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;
double x11=0,y11=0,r=0,m=0,dx,dy,d;
double tx=0,ty=0,sx=0,sy=0;
void bca()
{
glBegin(GL_POINTS);
int x=0,y=r;
d=1-r;
//cout << x11+x << " " << y11+y << endl;
glVertex2i(x11+x,y11+y);
glVertex2i(x11+x,y11-y);
glVertex2i(x11+y,y11+x);
glVertex2i(x11-y,y11+x);
int xp=x,yp=y;
//bool flag=false;
while(x<y)
{
    //cout << d << " ";
    if(d<0) d+=(2*xp+3);
    else {
        d+=(2*(xp-yp)+5);
        y--;
    } x++;
     xp=x;yp=y;
    //cout << x11+x << " " << y11+y << " \n";
    //cout << xp << " " << yp << endl;

    glVertex2i(x11+x,y11+y);
    glVertex2i(x11-x,y11+y);
    glVertex2i(x11+x,y11-y);
    glVertex2i(x11-x,y11-y);

    glVertex2i(x11+y,y11+x);
    glVertex2i(x11+y,y11-x);
    glVertex2i(x11-y,y11+x);
    glVertex2i(x11-y,y11-x);

}
glEnd();
 }
void circletrfan()
{
     glBegin(GL_TRIANGLE_FAN);
     float i = 0.0f;
        glVertex2f(x11, y11); // Center
        for(i = 0.0f; i <= 360; i++)
                glVertex2f(r*cos(M_PI * i / 180.0) + x11, r*sin(M_PI * i / 180.0) + y11);

glEnd();
}

void BresenhamKrug() // best one
{

int x=0,y=r;
d=1-r;
//cout << x11+x << " " << y11+y << endl;
glBegin(GL_TRIANGLE_FAN);
glVertex2i(x11,y11);
glVertex2i(x11+x,y11+y);
glVertex2i(x11+x,y11-y);
glVertex2i(x11+y,y11+x);
glVertex2i(x11-y,y11+x);
int xp=x,yp=y;
//bool flag=false;
while(x<y)
{
    //cout << d << " ";
    if(d<0) d+=(2*xp+3);
    else {
        d+=(2*(xp-yp)+5);
        y--;
    } x++;
     xp=x;yp=y;
    //cout << x11+x << " " << y11+y << " \n";
    //cout << xp << " " << yp << endl;

    glVertex2i(x11+x,y11+y);
    glVertex2i(x11-x,y11+y);
    glVertex2i(x11+x,y11-y);
    glVertex2i(x11-x,y11-y);

    glVertex2i(x11+y,y11+x);
    glVertex2i(x11+y,y11-x);
    glVertex2i(x11-y,y11+x);
    glVertex2i(x11-y,y11-x);

}
glEnd();
}

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT); // clear the display
glColor3ub (128, 0, 0);
//glPointSize(5.0);

//bca();
BresenhamKrug();
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
cout << "Please give center points\n"; cin >> x11 >> y11;
cout << "Please give radius\n"; cin >> r;
//cout << "Please give translation points\n"; cin >> tx >> ty;
//cout << "Please give Scaling points\n"; cin >> sx >> sy;
//x11+=tx; y11+=ty;
//r+=sy;

glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // for setting up the display mode
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Bresenham's Circle drawing algorithm"); // title & make visibility
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
