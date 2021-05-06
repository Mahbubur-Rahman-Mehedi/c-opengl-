#include<cstdio>
#include<iostream>
#include <GL/gl.h>
#include <GL/glut.h>


GLfloat positionr = 0.0f;
GLfloat positione = 0.0f;
GLfloat positionb = 0.0f;
GLfloat speed = 0.1f;

bool ap=false,dp=false,bfire=false;
bool e1=true,e2=true,e3=true;

void update(int value) {

    if(positionr > 0.9)
       { positionr = 0.9f; }
    else if(positionr < -0.9)
       { positionr = -0.8f; }
    else {
            if(dp)
            {
        positionr+=speed; dp=false;
            }
             if(ap)
            {
        positionr-=speed; ap=false;
            }
    }

    if(bfire)
    {
        if(positionb<1.4)
        positionb+=speed;
        else {
            positionb=0.0f;
            bfire=false;
        }
    }

     if(positione > -1.9 )
        positione-=speed;
    else
        positione=0.2f;

 if(positionb>=positione+1.0f&&positionb-.15f<=positione+1.0f)
    {
        float x1=positionr-0.08f;
        float x2=positionr-0.03f;
        if(x1>=-0.9&&x1<=-0.7) { e1=false; positionb=0.0f; bfire=false; }
        if(x1>=-0.3&&x1<=-0.1) { e2=false; positionb=0.0f; bfire=false; }
        if(x1>=0.7&&x1<=0.9) { e3=false; positionb=0.0f; bfire=false; }
        x1=positionr-0.08f;
        x2=positionr-0.03f;

    }


	glutPostRedisplay();


	glutTimerFunc(250, update, 0);
}
void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			 bfire=true;
		}
	}

	glutPostRedisplay();
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'r':
    dp=true;
    break;
case 'l':
    ap=true;
    break;


glutPostRedisplay();


	}
}

void enemy(){

glTranslatef(0.0f,positione, 0.0f);
 glBegin(GL_TRIANGLES);
    //E1
    if(e1){
   glColor3f(0.0f, 0.0f, 1.0f);
   glVertex2f(-0.9f,0.75f);
   glVertex2f(-0.7f, 0.75f);
   glVertex2f(-0.8f, 0.9f);
    }
   if(e2){
     //E2
   glColor3f(0.0f, 1.0f, 1.0f);
   glVertex2f(-0.3f,0.75f);
   glVertex2f(-0.1f, 0.75f);
   glVertex2f(-0.2f, 0.9f);
   }
   if(e3){
     //E2
   glColor3f(1.0f, 0.0f, 1.0f);
   glVertex2f(0.9f,0.75f);
   glVertex2f(0.7f, 0.75f);
   glVertex2f(0.8f, 0.9f);
   }
   glEnd();

}

void rocket(){
glTranslatef(positionr,0.0f, 0.0f);
 glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(-0.1f, -0.7f);
      glVertex2f( 0.0f, -0.7f);
      glVertex2f( 0.0f,  -0.4f);
      glVertex2f(-0.1f,  -0.4f);
   glEnd();

 glBegin(GL_TRIANGLES);

   glColor3f(1.0f, 1.0f, 1.0f);
   glVertex2f(-0.1f,-0.4f);
   glVertex2f( 0.0f, -0.4f);
   glVertex2f(-0.05f, -0.2f);


   glColor3f(1.0f, 0.0f, 0.3f);
   glVertex2f(0.0f,-0.47f);
   glVertex2f(0.07f, -0.47f);
   glVertex2f(0.0f, -0.4f);

    glColor3f(1.0f, 0.0f, 0.3f);
   glVertex2f(-0.1f,-0.47f);
   glVertex2f(-0.17f, -0.47f);
   glVertex2f(-0.1f, -0.4f);

   glColor3f(1.0f, 0.0f, 0.3f);
   glVertex2f(0.0f,-0.7f);
   glVertex2f(0.06f, -0.7f);
   glVertex2f(0.0f, -0.55f);

    glColor3f(1.0f, 0.0f, 0.3f);
   glVertex2f(-0.1f,-0.7f);
   glVertex2f(-0.16f, -0.7f);
   glVertex2f(-0.1f, -0.55f);

   glEnd();

   glBegin(GL_POLYGON);

    glColor3f(1.0f, 0.0f, 0.15f);
   glVertex2f(-0.1f,-0.7f);
   glVertex2f(-0.16f, -0.8f);
   glVertex2f(-0.05f, -0.97f);
   glVertex2f(0.06f, -0.8f);
   glVertex2f(0.0f,-0.7f);

   glEnd();

}

void bullet(){
glTranslatef(positionr,positionb, 0.0f);
glBegin(GL_QUADS);
      glColor3f(0.0f, 1.0f, 0.0f);
      glVertex2f(-0.08f, -0.2f);
      glVertex2f(-0.03f, -0.2f);
      glVertex2f(-0.03f, -0.15f);
      glVertex2f(-0.08f, -0.15f);
   glEnd();

}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();



glPushMatrix();

glPushMatrix();
enemy();
glPopMatrix();


glPushMatrix();
glPushMatrix();
rocket();
glPopMatrix();
bullet();
glPopMatrix();


glPopMatrix();



   glFlush();
}



int main(int argc, char** argv) {

    std::cout << "------ Press 'l' for moving Left ------\n";
    std::cout << "------ Press 'r' for moving Right ------\n";
    std::cout << "------ Click 'left mouse key' for shoot ------\n";
   glutInit(&argc, argv);
   glutInitWindowSize(600, 600);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Basic Animation");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(1000, update, 0);
   glutMainLoop();
   return 0;
}
