/*#include <GL/glut.h>
#include <windows.h>
#include<stdio.h>
#include<GL\freeglut.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159265
float zoom = 500;
bool iszoom = false;
GLfloat rotx = 0;
GLfloat roty = 0;
static int angle = 0;
static int angle__IN_RANGE = 0.0;
static double radian__IN_RANGE = 0.0;
#define Cos(radian__IN_RANGE)
#define Sin(radian__IN_RANGE)
void init()
{
	glClearColor(0.5, 0.7, 0.9, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500, 500, -500, 500, -500, 500);
	glMatrixMode(GL_MODELVIEW);
}
void DrawCabin()
{
	//create four cube at four different position
	//use glSolidCube
	//translate and scale it properly
}
void DrawHorizontalStick() {
	//use either cylinder or cube to create this
	//translate and scale it properly
}

void DrawVerticalStick() {
	//use either cylinder or cube to create this
	//translate and scale it properly
}
void ground()
{
	glPushMatrix();
	glColor3f(0, 1, 0);
	glTranslatef(0, -120, 0);
	glScalef(1, .05, 1.5);
	glutSolidCube(500);
	glPopMatrix();
}
void fence()
{
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-235, -110, 350); //this is not (235,340,0) bcz u want it in the z-axis that is behind the pole and not above the pole
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(10, 45, 70, 70);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-235, -110, -350);// it take (x,y,z)
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(10, 45, 70, 70);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(235, -110, -350);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(10, 45, 70, 70);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(235, -110, 350);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(10, 45, 70, 70);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.52, 0.37, 0.26);
	glTranslatef(-235, -100, -350);
	glutSolidCylinder(2, 700, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.52, 0.37, 0.26);
	glTranslatef(235, -100, -350);
	glutSolidCylinder(2, 700, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.52, 0.37, 0.26);
	glTranslatef(-235, -100, -350);
	glRotatef(-90, 0, -1, 0);
	glutSolidCylinder(2, 470, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.52, 0.37, 0.26);
	glTranslatef(-230, -100, 350);
	glRotatef(-90, 0, -1, 0);
	glutSolidCylinder(2, 470, 50, 50);
	glPopMatrix();
}

void pole()
{
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, -100, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCylinder(8, 500, 50, 50);
	glPopMatrix();

	glPushMatrix();
	//glColor3f(0.52, 0.39, 0.39);
	glColor3f(0.55, 0.47, 0.14);
	glTranslatef(0, 395, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(10, 45, 70, 70);
	glPopMatrix();
}

float th = 0;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	th += .1;
	if (iszoom == true)
	{
		glMatrixMode(GL_PROJECTION); // Set projection parameters.
		glLoadIdentity();
		glOrtho(-zoom, zoom, -zoom, zoom, -zoom, zoom);
		glMatrixMode(GL_MODELVIEW);
		iszoom = false;
	}
	glRotatef(rotx, 1, 0, 0);
	glRotatef(roty, 0, 1, 0);
	pole();
	fence();
	ground();
	glPushMatrix();
	glRotatef(th, 0, 1, 0);
	DrawHorizontalStick();
	DrawVerticalStick();
	DrawCabin();
	glPopMatrix();
	//}
	glutPostRedisplay();
	glutSwapBuffers(); // Required to copy color buffer onto the screen.
	
}
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 't':
	case 'T':
		rotx += 2.0;
		break;
	case 'b':
	case 'B':
		rotx -= 2.0;
		break;
	case 'l':
	case 'L':
		roty += 2.0;
		break;
	case 'r':
	case 'R':
		roty -= 2.0;
		break;
	case '+':
		iszoom = true;
		zoom = zoom - 50;
		break;
	case '-':
		iszoom = true;
		zoom = zoom + 50;
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {  // Initialize GLUT and
	glutInit(&argc, argv);
	printf("\n****************************************************\n\n");
	printf("\n Top Movement               :t or T\n");
	printf("\n Bottom Movement            :b or B\n");
	printf("\n Rotate Right               :r or R\n");
	printf("\n Rotate Left                :l or L\n");
	printf("\n Zoom in     :+\n");
	printf("\n Zoom out   :-\n");
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Amusement Park");
	glEnable(GL_DEPTH_TEST);
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

/**/