#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <cmath>

#define PI 3.1416

void init(){
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION | GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(0, 100, 0, 100, -1, 1);
}
void road(){
    ///GreenBar
    glPushMatrix();
    glColor3ub(9, 158, 11);
    glBegin(GL_QUADS);
    glVertex2f(0, 100);
    glVertex2f(0, 0);
    glVertex2f(15, 0);
    glVertex2f(15, 100);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(9, 158, 11);
    glBegin(GL_QUADS);
    glVertex2f(100, 100);
    glVertex2f(100, 0);
    glVertex2f(85, 0);
    glVertex2f(85, 100);
    glEnd();
    glPopMatrix();

    ///WhiteBar
    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(15, 100);
    glVertex2f(15, 0);
    glVertex2f(20, 0);
    glVertex2f(20, 100);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(85, 100);
    glVertex2f(85, 0);
    glVertex2f(80, 0);
    glVertex2f(80, 100);
    glEnd();
    glPopMatrix();

    ///BlackBar
    glPushMatrix();
    glColor3ub(86, 86, 86);
    glBegin(GL_QUADS);
    glVertex2f(20, 100);
    glVertex2f(20, 0);
    glVertex2f(80, 0);
    glVertex2f(80, 100);
    glEnd();
    glPopMatrix();

    ///LaneDivider
    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(49, 90);
    glVertex2f(49, 80);
    glVertex2f(51, 80);
    glVertex2f(51, 90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(49, 75);
    glVertex2f(49, 65);
    glVertex2f(51, 65);
    glVertex2f(51, 75);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(49, 60);
    glVertex2f(49, 50);
    glVertex2f(51, 50);
    glVertex2f(51, 60);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(49, 45);
    glVertex2f(49, 35);
    glVertex2f(51, 35);
    glVertex2f(51, 45);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(49, 30);
    glVertex2f(49, 20);
    glVertex2f(51, 20);
    glVertex2f(51, 30);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(49, 15);
    glVertex2f(49, 5);
    glVertex2f(51, 5);
    glVertex2f(51, 15);
    glEnd();
    glPopMatrix();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    road();

    glutSwapBuffers();
    glutPostRedisplay();
    glFlush();
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(700, 700);
    glutCreateWindow("2D Car Racing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
