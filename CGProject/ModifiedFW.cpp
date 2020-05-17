/*#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include<GL/glut.h>
#include<GL/GLU.h>

using namespace std;

bool anim = false;
bool inv_rot = false;
bool rotation = false;

float toRad(float deg)
{
	return (deg * 3.14) / 180;
}

int bars=45;

GLfloat rotx = 0;
GLfloat roty = 0;

float zoom = 500;
bool iszoom = false;

void seat()
{
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(0, 17.5, 0);
	glScalef(1, .75, .3);
	glutWireCube(35);
	glPopMatrix();

}
float sphere = 0;

void cabincolor(int i,int bars)
{
	if (bars == 45)
	{
		if(i%2==0)
			glColor3f(.7,.3,.4);
		else
			glColor3f(0.5,0,0.2);
	}
	else
	{
		if(i%20==0)
			glColor3f(.9, .6, 0);
		else
			glColor3f(0, 0, 0);
	}
}

void cabin(GLfloat revolve)
{
	for (int i = 0; i <= 360; i += bars) {
		glPushMatrix();
		if (rotation)
		{
			sphere += 0.01;
		}
		glLoadIdentity();
		glRotatef(rotx, 1, 0, 0);
		glRotatef(roty, 0, 1, 0);
		glTranslatef(0, 105, 0);
		glRotatef(revolve, 0, 0, 1);
		glTranslatef(0, -105, 0);
		glTranslatef(249 * cos(toRad(i)), 105 + 249 * sin(toRad(i)), 0);
		glRotatef(sphere, 0, 1, 0);
		glScalef(.7, .7, .7);
//		glColor3f(.9, .6, 0);
//		glColor3f(0.5,0.4,0);
		cabincolor(i, bars);
		glEnable(GL_LINE_SMOOTH);
		glutWireSphere(60, 10, 4);
		glutPostRedisplay();
	//	seat();
		glPopMatrix();
	}
}

void init(void)
{
	glClearColor(.6,.8,.9,1); // Set display-window color to white.
	glMatrixMode(GL_PROJECTION); // Set projection parameters.
	glLoadIdentity();
	glOrtho(-500, 500, -500, 500, -500, 500);
	glMatrixMode(GL_MODELVIEW);
}

void wheel(int z, int r)
{
	glPushMatrix();
	glTranslatef(0,150,z);
//	glColor3f(.9, 0.4, .0);
	glColor3f(0.8, 0, 0.0);
	glutSolidTorus(12,250,32,32);
	glPopMatrix();
}

void stand()
{
	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(-100,-25,85);
	glRotatef(60, 0, 0, 1);
	glScalef(5,.3,.2);
	glutSolidCube(100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(100, -25, 85);
	glRotatef(120, 0, 0, 1);
	glScalef(5, .3, .2);
	glutSolidCube(100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(-100, -25, -85);
	glRotatef(60, 0, 0, 1);
	glScalef(5, .3, .2);
	glutSolidCube(100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(100, -25, -85);
	glColor3f(0.3, 0.3, 0.3);
	//glColor3f(.65, .65, .65);
	glRotatef(120, 0, 0, 1);
	glScalef(5, .3, .2);
	glutSolidCube(100);
	glPopMatrix();
}

void cylinder()
{
	glPushMatrix();

	glTranslatef(0, 150, -100);
//	glColor3f(.9, 0.4, .0);
	glColor3f(0.8, 0, 0.0);
	glutSolidCylinder(50, 200, 30, 30);
	glPopMatrix();

}




void lines()
{
	for (int i = 0; i <= 360; i += bars)
	{
		// between the 2 wheels
		glPushMatrix();
		glTranslatef(249*cos(toRad(i)),150+ 249* sin(toRad(i)), 0);
		glRotatef(45, 0, 0, 1);
		glScalef(1, 1, 10);
		//glColor3f(.8, 0.4, .0);
		glColor3f(.6,0,0);
		//glColor3f(.9, 0.3, .0);
		glutSolidCube(10);
		glPopMatrix();

		//the one that goes towards the center
		glPushMatrix();
		glTranslatef(0,150, 53);
		glRotatef(i, 0, 0, 1);
		glRotatef(-51, 1, 0, 0);
		glScalef(50, 1.3, 1);
		glColor3f(.9, 0.5, .0);
		//glColor3f(.9, 0.3, .0);
		glutSolidCube(10);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 150, -53);
		glRotatef(i, 0, 0, 1);
		glScalef(50, 1.3, 1);
		glColor3f(.9, 0.5, .0);
		glutSolidCube(10);
		glPopMatrix();

	}
}
GLfloat theta[] = { 0 ,0.0f };

float inc=0.01;

void spin()
{
		glPushMatrix();
		glLoadIdentity();
		glRotatef(rotx, 1, 0, 0);
		glRotatef(roty, 0, 1, 0);
		glTranslatef(0, 150, 0);
		glRotatef(theta[0], 0, 0, 1);
		glTranslatef(0, -150, 0);

		wheel(57, 250);
		wheel(-57, 250);
		lines();
		cylinder();
		cabin(theta[1]);
		glPopMatrix();
}

void idle() {
	if (anim) {
		if (inv_rot)
		{
			theta[0] -= inc;
			theta[1] -= inc;
			rotation = true;
		}
		else
		{
			theta[0] += inc;
			theta[1] += inc;
			rotation = true;
		}

		glutPostRedisplay();
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Clear display window.
	if(iszoom==true)
	{
		glMatrixMode(GL_PROJECTION); // Set projection parameters.
		glLoadIdentity();
		glOrtho(-zoom, zoom, -zoom, zoom, -zoom, zoom);
		glMatrixMode(GL_MODELVIEW);
		iszoom = false;
	}
	glPushMatrix();
	glLoadIdentity();
	//glTranslatef(0, 0, -100);
	glRotatef(rotx, 1, 0, 0);
	glRotatef(roty, 0, 1, 0);
	spin();
	stand();
	glPopMatrix();

	glutSwapBuffers();

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
	case '1':
		if (bars==45)
			bars=30;
		break;
	case '0':
		if (bars ==30)
			bars=45;
		break;
	case 'x':
	case 'X':
		inc = inc - 0.05;
		break;
	case 'v':
	case 'V':
		inc = inc + 0.05;
		break;
	case 'c':
	case 'C':
		anim = !anim;
		if (anim == false)
			rotation = false;
		break;
	case 'i':
	case 'I':
		inv_rot = !inv_rot;
		break;
	case '+':
		iszoom = true;
		zoom = zoom -50;
		break;
	case '-':
		iszoom = true;
		zoom = zoom +50;
		break;
	case 'b':
	case 'B':
		rotation = !rotation;
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
	printf("\n	Wheel Rotation             :c or C\n");
	printf("\n	Cabin Rotation             :b or B\n");
	printf("\n	Clockwise & Anti-clockwise :i or I\n");
	printf("\n	Increase Speed             :v or V\n");
	printf("\n	Decrease Speed             :x or X\n");
	printf("\n	Increase No. of Cabin      :1\n");
	printf("\n	Decrease No. of Cabin      :0\n");
	printf("\n	Zoom in		  	   :+\n");
	printf("\n	Zoom out		   :-\n");
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Set display mode.
	glutInitWindowPosition(100, 10); // Set top-left display-window position.
	glutInitWindowSize(700, 700); // Set display-window height and width
	glutCreateWindow("Giant Wheel"); // Create display window.
	init(); // Execute initialization procedure.
	glutDisplayFunc(display); // Send graphics to display window.
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);
	glutMainLoop(); // Display everything and wait.
	return 0;
}
*/