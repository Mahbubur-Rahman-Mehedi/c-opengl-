#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>

using namespace std;

bool white=true,row=true;
int cnt=0;

void quads(int x,int y,int x1,int y1,int t)
{
    if(t==1)
        glColor3f (0, 0,0);
    else
         glColor3f (1, 1,0);
    glVertex2i(x,y);
    glVertex2i(x,y1);
    glVertex2i(x1,y1);
    glVertex2i(x1,y);
}
void ltlquads(int x,int y,int t)
{
    if(t==1)
        glColor3f (0, 0,0);
    else
         glColor3f (1, 1,0);
    glVertex2i(x,y);
    glVertex2i(x,y+20);
    glVertex2i(x-20,y+20);
    glVertex2i(x-20,y);
}

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);


glBegin(GL_QUADS);

quads(640,180,20,320,1);

quads(500,40,160,460,1);

quads(280,320,220,440,2);

quads(440,320,380,440,2);

quads(360,400,300,440,2);

ltlquads(300,420,2);

ltlquads(380,420,2);

quads(220,320,200,380,2);

quads(440,320,460,380,2);

quads(440,300,400,320,2);

quads(260,300,220,320,2);

quads(220,400,160,440,2);

quads(500,400,440,440,2);

quads(500,60,460,100,2);

quads(200,60,160,100,2);

ltlquads(220,60,2);

ltlquads(460,60,2);

quads(440,60,340,100,2);

quads(320,60,220,100,2);

quads(300,100,220,120,2);

quads(300,120,240,140,2);

ltlquads(280,140,2);

quads(440,100,360,120,2);
quads(420,120,360,140,2);
ltlquads(400,140,2);
ltlquads(340,60,2);

for(int c=380,a=520,b=60,j=0;j<6;j++)
{
    quads(a,b,a-20,b+c,1);
    a+=20; b+=20; c-=40;
}
for(int c=380,a=160,b=60,j=0;j<6;j++)
{
    quads(a,b,a-20,b+c,1);
    a-=20; b+=20; c-=40;
}

for(int c=40,a=80,b=300,j=0;j<5;j++)
{
    quads(a,b,a-20,b+c,2);
    a+=20; b+=20;
}
for(int c=40,a=80,b=160,j=0;j<5;j++)
{
    quads(a,b,a-20,b+c,2);
    a+=20; b-=20;
}
for(int c=40,a=520,b=80,j=0;j<5;j++)
{
    quads(a,b,a-20,b+c,2);
    a+=20; b+=20;
}
for(int c=40,a=520,b=380,j=0;j<5;j++)
{
    quads(a,b,a-20,b+c,2);
    a+=20; b-=20;
}
 quads(60,180,40,320,2);
 quads(620,180,600,320,2);

glEnd();

glFlush ();
}

void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 660.0, 0.0, 480.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (660, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Batman");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
