#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include<GL/glut.h>
#include<GL/GLU.h>
#include<stdio.h>

GLfloat rotx=0, roty=0;

bool start = false;
GLfloat zoom = 500;
bool full = false;

void init(void)
{
	glClearColor(.6, .8, .9, 1); // Set display-window color to white.
	glMatrixMode(GL_PROJECTION); // Set projection parameters.
	glLoadIdentity();
	glOrtho(-500, 500, -500, 500, -500, 500);
	glMatrixMode(GL_MODELVIEW);
}

void stand()
{

	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(-80, -175, 85);
	glRotatef(45, 0, 1, 0);
	glRotatef(60, 0, 0, 1);
	glScalef(5, .3, .2);
	glutSolidCube(100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(80, -175, 85);
	glRotatef(315, 0, 1, 0);
	glRotatef(120, 0, 0, 1);
	glScalef(5, .3, .2);
	glutSolidCube(100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(-80, -175, -85);
	glRotatef(-45, 0, 1, 0);
	glRotatef(60, 0, 0, 1);
	glScalef(5, .3, .2);
	glutSolidCube(100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(80, -175, -85);
	glColor3f(0.3, 0.3, 0.3);
	//glColor3f(.65, .65, .65);
	glRotatef(-315, 0, 1, 0);
	glRotatef(120, 0, 0, 1);
	glScalef(5, .3, .2);
	glutSolidCube(100);
	glPopMatrix();

}

float th[] = { 0,0 };
void seat(float val)
{
	th[0] = val*0.05;
	
	glPushMatrix();
	glTranslatef(0, -310, 00);
	glRotatef(th[0], 0, 0, 1);
	glRotatef(th[1], 0, 1, 0);
//	glTranslatef(0, 160, 0);
	//glColor3f(.4,.6,.5); light gray
	glColor3f(.85,0,0);
	glRotatef(90, 1, 0, 0);
	glScalef(1.5, 1.35, 1);
	glutWireTorus(25, 35, 7, 20); //outside cabin
	glColor3f(1, 1, 1);
	glutSolidTorus(5, 48, 40, 50); //inside seat
	glPopMatrix();

}

void cylinder()
{
	glPushMatrix();
	glColor3f(0, 0.15, 0);
	glTranslatef(0, 40, 00);
	glRotatef(90, 1, 0, 0);
	glutSolidCylinder(17, 350, 50, 50);
	glPopMatrix();



}


float theta = 0;
float speed=.06;
static float direction = 1.0f;
void func()
{
	glPushMatrix();
	glLoadIdentity(); 
	glRotatef(rotx, 1, 0, 0);
	glRotatef(roty, 0, 1, 0);
	glTranslatef(0.0, 40,0);					//for rotation
	glRotatef(theta, 0.0, 0.0, 1.0);			//about
	glTranslatef(0.0, -40,0);				//fixed point
	cylinder();
	seat(theta);
	glPopMatrix();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Clear display window.
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-zoom, zoom, -zoom, zoom, -zoom, zoom);
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glRotatef(rotx, 1, 0, 0);
	glRotatef(roty, 0, 1, 0);
	stand();
	func();
	glPopMatrix();
	glutSwapBuffers();
}

void idle()
{
	if (start)
	{
		if (!full) {
			if (theta > 70.0f)
				direction = -1.0f;
			if (theta < -70.0f)
				direction = 1.0f;
		}
		theta += speed * direction;
		th[1] += .1;
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
	case 'W':
		rotx += 2.0;
		break;
	case 's':
	case 'S':
		rotx -= 2.0;
		break;
	case 'a':
	case 'A':
		roty += 2.0;
		break;
	case 'd':
	case 'D':
		roty -= 2.0;
		break;
	case 'c':
	case 'C':
		start = !start;
		break;
	case 'x':
	case 'X':
		if (speed > .06)
			speed = speed - .01;
		else
			speed = 0.06;
		break;
	case 'v':
	case 'V':
		if (speed < 1.8)
			speed = speed + .01;
		else
			speed = 1.8;
		break;
	case '+':
		zoom = zoom - 50;
		break;
	case '-':
		zoom = zoom + 50;
		break;
	case 'f':
	case 'F':
		full = !full;
		theta = fmod(theta,360);
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // Initialize GLUT.
	printf("\n****************************************************\n\n");
	printf("\n	Top Movement               :w or W\n");
	printf("\n	Bottom Movement            :s or S\n");
	printf("\n	Rotate Right               :a or A\n");
	printf("\n	Rotate Left                :d or D\n");
	printf("\n	Start/Stop				   :c or C\n");
	printf("\n	Full rotation			   :f or F\n");
	printf("\n	Increase Speed             :v or V\n");
	printf("\n	Decrease Speed             :x or X\n");
	printf("\n	Zoom in					   :+\n");
	printf("\n	Zoom out					   :-\n");
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Set display mode.
	glutInitWindowPosition(100, 10); // Set top-left display-window position.
	glutInitWindowSize(700,700); // Set display-window height and width
	glutCreateWindow("Frisbee"); // Create display window.
	init(); // Execute initialization procedure.
	glutDisplayFunc(display); // Send graphics to display window.
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LINE_SMOOTH);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);
	glutMainLoop(); // Display everything and wait.
	return 0;
}
