#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <cmath>

#define PI 3.1416

void init()
{
    glClearColor(1, 1, 1, 0.0);
    glMatrixMode(GL_PROJECTION | GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(0, 100,0 ,100 , -1 , 1);
}
void minarStairs()
{
    glColor3ub(235, 225, 163);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(100, 0);
    glVertex2f(100, 100);
    glVertex2f(0, 100);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    minarStairs();

    // cool
    glutSwapBuffers();
    glutPostRedisplay();
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Car Racing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
