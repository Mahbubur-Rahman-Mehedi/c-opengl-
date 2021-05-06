#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>

using namespace std;

bool white=true,row=true;
int cnt=0;

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);

for(int j=640;j>=80;j-=80)
{
for(int i=640;i>=80;i-=80)
{
    glBegin(GL_QUADS);
    if(row)
    {
    if(white)
    {glColor3f (1, 1,1); white=false;}
    else {glColor3f (0, 0, 0); white =true; }
    }
    else
    {
    if(white)
    {glColor3f (0, 0,0); white=false;}
    else {glColor3f (1, 1, 1); white =true; }
    }
    glVertex2i(i,j-80);
    glVertex2i(i,j);
    glVertex2i(i-80,j);
    glVertex2i(i-80,j-80);
    glEnd();

}
if(row) row=false;
else row=true;
}

glFlush ();
}

void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 640.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 640);
glutInitWindowPosition (100, 150);
glutCreateWindow ("chess board");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
