
#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <GL\glut.h>


GLfloat anguloCuboX = 0.0f;
GLfloat anguloCuboY = 0.0f;
GLfloat anguloEsfera = 0.0f;

GLint ancho=400;
GLint alto=400;
bool _translationMoveMode = false;
int hazPerspectiva = 0;
GLfloat upUnints=0.0f;
GLfloat rightUnits = 0.0f;
GLfloat _totalHeigth = 10.0f;
GLint _steps= 200;

GLint _rotationVerticalStep =0;
GLint _rotationHrizontalStep =0;

GLfloat VerticalSteps=0;
GLfloat LateralSteps=0;


GLfloat _cameraAngle =60.0f;
GLdouble _zoom=4.0f;



void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	if(hazPerspectiva)
	{

		gluPerspective(_cameraAngle, (GLfloat)width/(GLfloat)height, 1.0f, 20.0f);

	}
	else
	{
		glOrtho(-_zoom,_zoom, -_zoom, _zoom, -20, 20);
	}



	glMatrixMode(GL_MODELVIEW);

	ancho = width;
	alto = height;
}

void drawCube(void)
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);       //cara frontal
	glVertex3f(-1.0f, -1.0f,  1.0f);
	glVertex3f( 1.0f, -1.0f,  1.0f);
	glVertex3f( 1.0f,  1.0f,  1.0f);
	glVertex3f(-1.0f,  1.0f,  1.0f);

	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);       //cara trasera
	glVertex3f( 1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f,  1.0f, -1.0f);
	glVertex3f( 1.0f,  1.0f, -1.0f);

	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);       //cara lateral izq
	glVertex3f(-1.0f,-1.0f, -1.0f);
	glVertex3f(-1.0f,-1.0f,  1.0f);
	glVertex3f(-1.0f, 1.0f,  1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);       //cara lateral dcha
	glVertex3f(1.0f, -1.0f,  1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f,  1.0f, -1.0f);
	glVertex3f(1.0f,  1.0f,  1.0f);
	glEnd(); 

	glColor3f(0.0f,      1.0f, 1.0f);
	glBegin(GL_QUADS);       //cara arriba
	glVertex3f(-1.0f, 1.0f,  1.0f);
	glVertex3f( 1.0f, 1.0f,  1.0f);
	glVertex3f( 1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();

	glColor3f(1.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);       //cara abajo
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

	glTranslatef(0.0f, 0.0f, -5.0f);

	//rotation
	glLoadIdentity();

	float rotationVertical = 360.0f/(float)_steps;	
	rotationVertical *=(float)_rotationVerticalStep;

	glRotatef(rotationVertical, 1.0f, 0.0f, 0.0f);


	float rotationHorizontal = 360.0f/(float)_steps;
	rotationHorizontal *=(float)_rotationHrizontalStep;


	glRotatef(rotationHorizontal, 0.0f, 1.0f, 0.0f);


	glTranslatef(0.0f, VerticalSteps, 0.0f);


	drawPlane();


	//glRotatef(anguloCuboX, 1.0f, 0.0f, 0.0f);
	glRotatef(anguloCuboY, 0.0f, 1.0f, 0.0f);



	drawCube();

	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotationVertical, 1.0f, 0.0f, 0.0f);
	glRotatef(rotationHorizontal, 0.0f, 1.0f, 0.0f);

	glRotatef(anguloEsfera, 0.0f, 1.0f, 0.0f);
	glTranslatef(3.0f, 0.0f, 0.0f);
	glTranslatef( 0.0f,VerticalSteps, 0.0f);
	

	glColor3f(1.0f, 0.0f, 0.5f);
	glutWireSphere(0.5f, 8, 8);


	/*glRotatef(rotationVertical, 1.0f, 0.0f, 0.0f);
	glRotatef(rotationHorizontal, 0.0f, 1.0f, 0.0f);
	glTranslatef(VerticalSteps, 0.0f, 0.0f);*/
	//glTranslatef(0.0f, 1.0f, 0.0f);
	//glRotatef(rotation,1.0f,0.0f,0.0f);

	glFlush();
	glutSwapBuffers();

	anguloCuboX+=0.1f;
	anguloCuboY+=0.1f;
	anguloEsfera-=0.2f;
}

void init()
{
	glClearColor(0,0,0,0);
	glEnable(GL_DEPTH_TEST);
	ancho = 400;
	alto = 400;
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
		hazPerspectiva=1;
		reshape(ancho,alto);
		break;

	case 'o':
	case 'O':
		hazPerspectiva=0;
		reshape(ancho,alto);
		break;

	case 27:   // escape
		exit(0);
		break;


	case 8:
		_translationMoveMode =!_translationMoveMode;
		break;


	case 's': //Rotate down

		if (_translationMoveMode)
			VerticalSteps-=1;

		else
			_rotationVerticalStep+=1;
		//upUnints+=1.0f;
		reshape(ancho,alto);
		break;

	case 'w'://Rotate up
		if (_translationMoveMode)
			VerticalSteps+=1;
		else
			_rotationVerticalStep-=1;
		
		reshape(ancho,alto);
		break;




	case 'a': //Rotate Left
		_rotationHrizontalStep+=1;
		//upUnints+=1.0f;
		reshape(ancho,alto);
		break;

	case 'd'://Rotate right
		_rotationHrizontalStep-=1;
		reshape(ancho,alto);
		break;



	case 'm'://zoom out
		_cameraAngle+=1;
		_zoom+=1;
		reshape(ancho,alto);
		break;

	case 'k'://zoom in
		_cameraAngle-=1;
		_zoom-=1;
		reshape(ancho,alto);
		break;

	}


}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(ancho, alto);
	glutCreateWindow("Cubo 1");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}