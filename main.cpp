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
    glVertex2f(10, 0);
    glVertex2f(10, 100);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(9, 158, 11);
    glBegin(GL_QUADS);
    glVertex2f(100, 100);
    glVertex2f(100, 0);
    glVertex2f(90, 0);
    glVertex2f(90, 100);
    glEnd();
    glPopMatrix();

    ///WhiteBar
    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(10, 100);
    glVertex2f(10, 0);
    glVertex2f(12, 0);
    glVertex2f(12, 100);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(90, 100);
    glVertex2f(90, 0);
    glVertex2f(88, 0);
    glVertex2f(88, 100);
    glEnd();
    glPopMatrix();

    ///BlackBar
    glPushMatrix();
    glColor3ub(86, 86, 86);
    glBegin(GL_QUADS);
    glVertex2f(12, 100);
    glVertex2f(12, 0);
    glVertex2f(88, 0);
    glVertex2f(88, 100);
    glEnd();
    glPopMatrix();

    ///LaneDivider1
    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(35, 90);
    glVertex2f(35, 80);
    glVertex2f(37, 80);
    glVertex2f(37, 90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(35, 75);
    glVertex2f(35, 65);
    glVertex2f(37, 65);
    glVertex2f(37, 75);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(35, 60);
    glVertex2f(35, 50);
    glVertex2f(37, 50);
    glVertex2f(37, 60);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(35, 45);
    glVertex2f(35, 35);
    glVertex2f(37, 35);
    glVertex2f(37, 45);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(35, 30);
    glVertex2f(35, 20);
    glVertex2f(37, 20);
    glVertex2f(37, 30);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(35, 15);
    glVertex2f(35, 5);
    glVertex2f(37, 5);
    glVertex2f(37, 15);
    glEnd();
    glPopMatrix();

    ///LaneDivider2
    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(63, 90);
    glVertex2f(63, 80);
    glVertex2f(65, 80);
    glVertex2f(65, 90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(63, 75);
    glVertex2f(63, 65);
    glVertex2f(65, 65);
    glVertex2f(65, 75);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(63, 60);
    glVertex2f(63, 50);
    glVertex2f(65, 50);
    glVertex2f(65, 60);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(63, 45);
    glVertex2f(63, 35);
    glVertex2f(65, 35);
    glVertex2f(65, 45);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(63, 30);
    glVertex2f(63, 20);
    glVertex2f(65, 20);
    glVertex2f(65, 30);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(63, 15);
    glVertex2f(63, 5);
    glVertex2f(65, 5);
    glVertex2f(65, 15);
    glEnd();
    glPopMatrix();
}
void car(){
    glPushMatrix();
    glColor3ub(206, 206, 206);
    glBegin(GL_QUADS);
    glVertex2f(20, 30);
    glVertex2f(20, 24);
    glVertex2f(25, 24);
    glVertex2f(25, 30);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(20, 35);
    glVertex2f(20, 30);
    glVertex2f(25, 30);
    glVertex2f(25, 35);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(20, 37);
    glVertex2f(20, 35);
    glVertex2f(25, 35);
    glVertex2f(25, 37);
    glEnd();
    glPopMatrix();

        ///Glass1
        glPushMatrix();
        glColor3ub(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2f(20, 37);
        glVertex2f(19, 37);
        glVertex2f(18, 36.5);
        glVertex2f(20, 36.7);
        glEnd();
        glPopMatrix();

        ///Glass2
        glPushMatrix();
        glColor3ub(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2f(25, 37);
        glVertex2f(26, 37);
        glVertex2f(27, 36.5);
        glVertex2f(25, 36.7);
        glEnd();
        glPopMatrix();

    glPushMatrix();
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(21, 40);
    glVertex2f(20, 37);
    glVertex2f(25, 37);
    glVertex2f(24, 40);
    glEnd();
    glPopMatrix();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    road();
    car();

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
