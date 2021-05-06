#include <GL/gl.h>
#include <iostream>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

GLfloat minX,minY,maxX,maxY,p1x,p1y,p2x,p2y;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3ub(255, 0, 0);
    glVertex2f(p1x-minX,p1y-minY);
    glVertex2f(p2x-minX,p2y-minY);
    glEnd();
    glFlush();
}

void myInit (void)
{
glClearColor(0.0, 0.0, 0.0, 0.0); // Background color
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,maxX-minX, 0.0, maxY-minY);
}

int check(int x,int y){
    int flag=0;

    if (x<minX) flag|=1;
    else if (x>maxX) flag|=2;

    if (y<minY) flag|=4;
    else if (y>maxY) flag|=8;

    return flag;
}
void lineClipping()
{
// checking where are the points
int point1 = check(p1x,p1y);
int point2 = check(p2x,p2y);

bool accept=false;

GLfloat m=(p2y-p1y)/(p2x-p1x); // slope

while(true){
    if(point1==0&&point2==0) { // If both points are inside window
        accept=true;
        break;
    }
    else if(point1&point2) break; // If both points are outside and also in the same side

    else{  // line has some points inside window
        int point;
        GLfloat x,y;
        //checking which point is outside
        if(point1!=0) point=point1;
        else point=point2;

      // cout << point1 << " " << point2 << "  " << point;

        if(point&1){ //checking if point is in left of the window
            y=m*(minX-p1x)+p1y;
            x=minX;
        }
        else if(point&2){ //checking if point is in right of the window
            y=m*(maxX-p1x)+p1y;
            x=maxX;
        }
        else if(point&8){  //checking if point is in top of the window
            x=m*(maxY-p1y)+p1x;
            y=maxY;
        }
        else if(point&4){ //checking if point is in bottom of the window
            x=m*(minY-p1y)+p1x;
            y= minY;
        }

        if(point==point1){
            p1x=x; p1y=y;
            point1=check(p1x,p1y); // need again if between two sides or a corner
        }
        else{
            p2x=x; p2y=y;
            point2=check(p2x,p2y); // need again if between two sides or a corner
        }
    }
}
//if(p1x==p2x&&p1y==p2y) accept=false; // it's a point not a line
    if(accept){
             cout << "accepted";
            cout << "first point: "  << p1x << " " << p1y << "\n second point: " << p2x << " " << p2y << endl;

    }
    else cout << "rejected" << endl;
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	cout << "Enter Minimum window co-ordinates:- ";
	cin >> minX >> minY ;
	cout << "Enter Maximum window co-ordinates:- ";
	cin >> maxX >> maxY;

	cout << "Enter co-ordinates of first point of line: - ";
	cin >> p1x >> p1y;
	cout << "Enter co-ordinates of second point of line: - ";
	cin >> p2x >> p2y;

	lineClipping();

	glutInitWindowSize(maxX-minX,maxY-minY);
	//glutInitWindowSize(500,300);
	glutInitWindowPosition(1200,500);
	glutCreateWindow("Line Clipping");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
	return 0;
}
