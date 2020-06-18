#include <iostream>
#include <GL/freeglut.h>


float x_pos = 0.0f,  y_pos = 0.0f, deltaX = 0.030f, deltaY = 0.056f;
float delta = 0.095f;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.1);
	glPointSize(10);

	glBegin(GL_POINTS);
	glVertex2f(x_pos, sin(y_pos));
	glVertex2f(0.0, sin(y_pos));
	glVertex2f(x_pos, 0.0);
	glEnd();

	glColor3f(0.0, 0.0, 255.0);
	glBegin(GL_POLYGON);
	glVertex2f(x_pos, sin(y_pos));
	glVertex2f(0.0, sin(y_pos));
	glVertex2f(x_pos, 0.0);
	glEnd();

	glutSwapBuffers();
}

void timer(int) {
	glutPostRedisplay();

	glutTimerFunc(1000 / 30, timer, 0);

	if (x_pos >= 1.0f || x_pos <= -1.0f)
		deltaX = -deltaX;
		y_pos += deltaY;
		x_pos += deltaX;

}

void myinit() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, 0.0f, 0.0f, 0.0f);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("GrafkomH-672018152-Tugas4");

	glutDisplayFunc(display);

	myinit();

	glutTimerFunc(0, timer, 0);

	glutMainLoop();

	return 0;
}