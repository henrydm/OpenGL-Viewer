#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <GL\glut.h>


bool _translationMoveMode = false;
bool _prespective = 0;
GLint width=400;
GLint heigth=400;
GLfloat upUnints=0.0f;
GLfloat rightUnits = 0.0f;
GLfloat _totalHeigth = 10.0f;
GLfloat anguloCuboX = 0.0f;
GLfloat anguloCuboY = 0.0f;
GLfloat anguloEsfera = 0.0f;
GLint _steps= 200;
GLint _rotationVerticalStep =15;
GLint _rotationHrizontalStep =0;
GLfloat VerticalSteps=-1;
GLfloat HorizontalSteps=0;
GLfloat _cameraAngle =60.0f;
GLdouble _zoom=6.0f;



void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if(_prespective)
	{
		gluPerspective(_cameraAngle, (GLfloat)width/(GLfloat)height, 1.0f, 20.0f);
	}
	else
	{
		glOrtho(-_zoom,_zoom, -_zoom, _zoom, -20, 20);
	}

	glMatrixMode(GL_MODELVIEW);

}

void drawCube(void)
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);       //front side
	glVertex3f(-1.0f, -1.0f,  1.0f);
	glVertex3f( 1.0f, -1.0f,  1.0f);
	glVertex3f( 1.0f,  1.0f,  1.0f);
	glVertex3f(-1.0f,  1.0f,  1.0f);

	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);       //back side
	glVertex3f( 1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f,  1.0f, -1.0f);
	glVertex3f( 1.0f,  1.0f, -1.0f);

	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);       //up left side
	glVertex3f(-1.0f,-1.0f, -1.0f);
	glVertex3f(-1.0f,-1.0f,  1.0f);
	glVertex3f(-1.0f, 1.0f,  1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);       //up right side
	glVertex3f(1.0f, -1.0f,  1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f,  1.0f, -1.0f);
	glVertex3f(1.0f,  1.0f,  1.0f);
	glEnd(); 

	glColor3f(0.0f,      1.0f, 1.0f);
	glBegin(GL_QUADS);       //up side
	glVertex3f(-1.0f, 1.0f,  1.0f);
	glVertex3f( 1.0f, 1.0f,  1.0f);
	glVertex3f( 1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	glColor3f(1.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);       //back side
	glVertex3f( 1.0f,-1.0f, -1.0f);
	glVertex3f( 1.0f,-1.0f,  1.0f);
	glVertex3f(-1.0f,-1.0f,  1.0f);
	glVertex3f(-1.0f,-1.0f, -1.0f);
	glEnd();
}
void drawPlane(void)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);  
	glVertex3f( 4.0f,-2.0f, -4.0f); //back right
	glVertex3f( 4.0f,-2.0f,  4.0f); //front right
	glVertex3f(-4.0f,-2.0f,  4.0f); //front left
	glVertex3f(-4.0f,-2.0f, -4.0f); //back left
	glEnd();

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	float rotationVertical = 360.0f/(float)_steps;	
	rotationVertical *=(float)_rotationVerticalStep;
	float rotationHorizontal = 360.0f/(float)_steps;
	rotationHorizontal *=(float)_rotationHrizontalStep;

	//plane
	glLoadIdentity();
	glTranslatef(0.0f, VerticalSteps, 0.0f);
	glTranslatef(HorizontalSteps, 0.0f, 0.0f);

	glTranslatef(0.0f, 0.0f, -5.0f);

	glRotatef(rotationVertical, 1.0f, 0.0f, 0.0f);
	glRotatef(rotationHorizontal, 0.0f, 1.0f, 0.0f);

	drawPlane();


	//Cube same tranforms plus rotation
	//glRotatef(anguloCuboX, 1.0f, 0.0f, 0.0f);
	glRotatef(anguloCuboY, 0.0f, 1.0f, 0.0f);
	drawCube();

	//reset matrix and set sphere
	glLoadIdentity();

	glTranslatef( 0.0f,VerticalSteps, 0.0f);
	glTranslatef(HorizontalSteps, 0.0f, 0.0f);

	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotationVertical, 1.0f, 0.0f, 0.0f);
	glRotatef(rotationHorizontal, 0.0f, 1.0f, 0.0f);

	glRotatef(anguloEsfera, 0.0f, 1.0f, 0.0f);
	glTranslatef(3.0f, 0.0f, 0.0f);

	

	glColor3f(1.0f, 0.0f, 0.5f);
	glutWireSphere(0.5f, 8, 8);

	glFlush();
	glutSwapBuffers();

	anguloCuboX+=0.1f;
	anguloCuboY+=0.1f;
	anguloEsfera-=0.2f;

	glutPostRedisplay();
}

void init()
{
	glClearColor(0,0,0,0);
	glEnable(GL_DEPTH_TEST);
	width = 400;
	heigth = 400;
}


void idle()
{
	display();
}

void keyboard(unsigned char key, int x, int y)
{

	switch(key)
	{
	case 'p':
	case 'P':
		_prespective=!_prespective;
		reshape(width,heigth);
		break;

	case 27:   // escape
		exit(0);
		break;


	case 8:
		_translationMoveMode =!_translationMoveMode;
		break;


	case 's': //Rotate down

		if (_translationMoveMode)
			VerticalSteps+=0.25;
		else
			_rotationVerticalStep-=1;
		break;

	case 'w'://Rotate up
		if (_translationMoveMode)
			VerticalSteps-=0.25;
		else
			_rotationVerticalStep+=1;
		break;


	case 'a': //Rotate Left
		if (_translationMoveMode)
			HorizontalSteps+=0.25;
		else
			_rotationHrizontalStep+=1;
		break;

	case 'd'://Rotate right
		if (_translationMoveMode)
			HorizontalSteps-=0.25;
		else
			_rotationHrizontalStep-=1;
		break;



	case 'm'://zoom out
		_cameraAngle+=1;
		_zoom+=1;
		reshape(width,heigth);
		break;

	case 'k'://zoom in
		_cameraAngle-=1;
		_zoom-=1;
		reshape(width,heigth);
		break;

	}


}
void keyDown(unsigned char key, int x, int y)
{
}
void keyUp(unsigned char key, int x, int y)
{
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(width, heigth);
	glutCreateWindow("OpenGL");
	init();
	//glutIgnoreKeyRepeat(1);
	//glutKeyboardFunc(keyDown);
	//glutKeyboardUpFunc(keyUp);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}