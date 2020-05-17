/*#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include<GL/glut.h>
#include<GL/GLU.h>
#include<string.h>

void init(void)
{
	glClearColor(1,1,1,1); // Set display-window color to white.
	glMatrixMode(GL_PROJECTION); // Set projection parameters.
	glLoadIdentity();
	glOrtho(-500, 500, -500, 500, -500, 500);
	glMatrixMode(GL_MODELVIEW);
}

void WelcomeDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Clear display window.
	glColor3d(0, 0.3, 0);
	glRasterPos3f(-280,400,0);
	char heading[] = "WELCOME TO CARNIVAL PROJECT";
	for (int i=0;i<strlen(heading);i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,heading[i] );
	glRasterPos3f(-450, 300, 0);
	char submit[] = "Submitted by : ";
	for (int i = 0; i < strlen(submit); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, submit[i]);
	char names[] = "JOTHSNA MARIA DSOUZA - 4SO17CS048$KAVYA U - 4SO17CS054$LAHARI - 4SO17CS059";
	int k = 250;
	int j = 0;
	glRasterPos3f(-400, 200, 0);
	for (j = 0; j < strlen(names); j++)
	{
		if (names[j] == '$')
			break;
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, names[j]);
	}
	glRasterPos3f(-400, 150, 0);
	for (int i = j + 1; i < strlen(names); i++)
	{
		if (names[i] == '$')
		{
			j = i;
			break;
		}
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, names[i]);
	}
	glRasterPos3f(-400, 100, 0);
	for (int i = j + 1; i < strlen(names); i++)
	{
		if (names[i] == '$')
		{
			j = i;
			break;
		}
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, names[i]);
	}
	glutSwapBuffers();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Clear display window.

	glutSolidCube(200);

	glutPostRedisplay();
	
	glutSwapBuffers();

}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		glutDisplayFunc(display);
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // Initialize GLUT.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Set display mode.
	glutInitWindowPosition(100, 100); // Set top-left display-window position.
	glutInitWindowSize(700, 700); // Set display-window height and width
	glutCreateWindow("Welcome Screen"); // Create display window.
	init(); // Execute initialization procedure.
	glutDisplayFunc(WelcomeDisplay); // Send graphics to display window.
	glEnable(GL_DEPTH_TEST);
	glutMouseFunc(mouse);
	glutMainLoop(); // Display everything and wait.
	return 0;
}
*/