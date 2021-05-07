/// Concept of axis and points

#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT); // clear the display
glColor3ub (128, 0, 0);
glPointSize(10.0);
glBegin(GL_LINES);
glVertex2i(0, 240);
glVertex2i(640, 240);
glVertex2i(320,0);
glVertex2i(320,480);
//glVertex2i(250, 230);
glEnd();
glBegin(GL_LINES);
glColor3f (.50, .50, 0.50);
glVertex2i(400,285);
glVertex2i(400,435);
glVertex2i(500,285);
glVertex2i(500,435);
glVertex2i(400,360);
glVertex2i(500,360);

glEnd();

glBegin(GL_LINES);
glColor3f (.20, 1.0, 0.50);
glVertex2i (80,45);
glVertex2i (180,145);
glVertex2i (80,145);
glVertex2i (180,45);

glEnd();

glBegin(GL_TRIANGLES);
glColor3f (1.0, 0.0, 0.0);
glVertex2i (400,45);
glColor3f (0.0, 1.0, 0.0);
glVertex2i (600,45);
glColor3f (0.0, 0.0, 1.0);
glVertex2i (500,195);

glEnd();

glBegin(GL_LINES);
glColor3f (1.0, 1.0, 0.0);
glVertex2i (80,285);
glVertex2i (180,385);
glVertex2i (80,385);
glVertex2i (180,285);
glVertex2i (80,285);
glVertex2i (180,285);
glVertex2i (80,385);
glVertex2i (180,385);


glEnd();
glFlush (); // for showing the objects ( like refresh)
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
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // for setting up the display mode
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow (""); // title & make visibility
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop(); // run this project continiously after some timi ( mili second)
}
