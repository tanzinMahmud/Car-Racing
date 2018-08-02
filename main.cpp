#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

#define PI 3.1416


//For Display TEXT
const auto font1 = GLUT_BITMAP_TIMES_ROMAN_24;
const auto font2 = GLUT_BITMAP_HELVETICA_18;
const auto font3 = GLUT_BITMAP_8_BY_13;

int gv = 0;
int score = 0;

//Game Speed
int FPS = 50;
//Game Track
int start=0;
int level = 0;

//Track Score

//Form move track
int roadDivTopMost = 0;
int roadDivTop = 0;
int roadDivMdl = 0;
int roadDivBtm = 0;

//For Card Left / RIGHT
int lrIndex = 0 ;

//Car Coming
int car1 = 0;
int lrIndex1=0;
int car2 = +35;
int lrIndex2=0;
int car3 = +70;
int lrIndex3=0;



void spe_key(int key, int x, int y){
        switch (key) {
        case GLUT_KEY_DOWN:
            if(FPS>(50+(level*2)))
            FPS=FPS-2;
            break;
        case GLUT_KEY_UP:
            FPS=FPS+2;
            break;

        case GLUT_KEY_LEFT:
            if(lrIndex>=0){
                lrIndex = lrIndex - (FPS/10);
                if(lrIndex<0){
                    lrIndex=-1;
                }
            }
            break;


        case GLUT_KEY_RIGHT:
            if(lrIndex<=44){
                lrIndex = lrIndex + (FPS/10);
                if(lrIndex>44){
                    lrIndex = 45;
                }
            }
            break;

        default:
                break;
        }

}

void processKeys(unsigned char key, int x, int y) {

      switch (key)
            {
                case ' ':
            if(start==0){
                start = 1;
                gv = 0;
                FPS = 50;
                roadDivTopMost = 0;
                roadDivTop = 0;
                roadDivMdl = 0;
                roadDivBtm = 0;
                lrIndex = 0 ;
                car1 = 0;
                lrIndex1=0;
                car2 = +35;
                lrIndex2=0;
                car3 = +70;
                lrIndex3=0;
                score=0;
                level=0;
            }
             break;

             case 27:
                 exit(0);
             break;
             default:
                break;
        }
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer,0);
}



void init(){
    glClearColor(0, 0, 0, 0);
    ///glMatrixMode(GL_PROJECTION | GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(0, 100, 0, 100, -1, 1);
}


void renderBitmapString(float x, float y, void* font, const char* string)
{
    const char* c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}

void tree(int x, int y)
{
    int newx = x;
    int newy = y;
    //Tree Left
    //Bottom
    glColor3f(0.871, 0.722, 0.529);
    glBegin(GL_TRIANGLES);
    glVertex2f(newx + 11, newy + 55);
    glVertex2f(newx + 12, newy + 55 - 10);
    glVertex2f(newx + 10, newy + 55 - 10);
    glEnd();
    //Up
    glColor3f(0.133, 0.545, 0.133);
    glBegin(GL_TRIANGLES);
    glVertex2f(newx + 11, newy + 55 + 3);
    glVertex2f(newx + 12 + 3, newy + 55 - 3);
    glVertex2f(newx + 10 - 3, newy + 55 - 3);
    glEnd();
}

void FrontPage()
{

    //Road Backgound
    glColor3f(0.000, 0.392, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(0, 55);
    glVertex2f(100, 55);
    glColor3f(0.604, 0.804, 0.196);
    glVertex2f(100, 50 - 50);
    glVertex2f(0, 50 - 50);
    glEnd();

    //Road Design In Front Page
    glColor3f(00, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(32 - 2 + 21, 55);
    glVertex2f(32 + 58, 50 - 50);
    glVertex2f(32 - 22, 50 - 50);
    glEnd();
    //Road Midle
    glColor3f(1, 1, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(32 - 2 + 21, 55);
    glVertex2f(50 + 2, 50 - 50);
    glVertex2f(50 - 2, 50 - 50);
    glEnd();

    //Road Sky
    glColor3f(0.000, 0.749, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(100, 100);
    glVertex2f(0, 100);
    glColor3f(0.686, 0.933, 0.933);
    glVertex2f(0, 55);
    glVertex2f(100, 55);
    glEnd();

    //Hill 1
    glColor3f(0.235, 0.702, 0.443);
    glBegin(GL_TRIANGLES);
    glVertex2f(20, 55 + 10);
    glVertex2f(20 + 7, 55);
    glVertex2f(0, 55);
    glEnd();

    //Hill 2
    glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_TRIANGLES);
    glVertex2f(20 + 15, 55 + 12);
    glVertex2f(20 + 20 + 10, 55);
    glVertex2f(0 + 10, 55);
    glEnd();

    //Hill 4
    glColor3f(0.235, 0.702, 0.443);
    glBegin(GL_TRIANGLES);
    glVertex2f(87, 55 + 10);
    glVertex2f(100, 55);
    glVertex2f(60, 55);
    glEnd();

    //Hill 3
    glColor3f(0.000, 0.502, 0.000);
    glBegin(GL_TRIANGLES);
    glVertex2f(70, 70);
    glVertex2f(90, 55);
    glVertex2f(50, 55);
    glEnd();

    //Tree Left
    //Bottom
    glColor3f(0.871, 0.722, 0.529);
    glBegin(GL_TRIANGLES);
    glVertex2f(11, 55);
    glVertex2f(12, 55 - 10);
    glVertex2f(10, 55 - 10);
    glEnd();
    //Up
    glColor3f(0.133, 0.545, 0.133);
    glBegin(GL_TRIANGLES);
    glVertex2f(11, 55 + 3);
    glVertex2f(12 + 3, 55 - 3);
    glVertex2f(10 - 3, 55 - 3);
    glEnd();

    tree(5, -15);
    tree(9, 5);
    tree(85, 9);
    tree(75, -5);

    //Menu Place Holder
    glColor3f(0.098, 0.098, 0.439);
    glBegin(GL_POLYGON);
    glVertex2f(32 - 4, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 - 15 + 10);
    glVertex2f(32 - 4, 50 - 15 + 10);
    glEnd();

    glColor3f(00, 0, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(32 - 4, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 + 4 + 10);
    glVertex2f(32 - 4, 50 + 4 + 10);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(32 + 45, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 + 5 + 10);
    glVertex2f(32 + 46, 50 - 15 + 10);
    glVertex2f(32 + 45, 50 - 15 + 10);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(32 - 4, 50 - 14 + 10);
    glVertex2f(32 + 46, 50 - 14 + 10);
    glVertex2f(32 + 46, 50 - 15 + 10);
    glVertex2f(32 - 4, 50 - 15 + 10);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(32 - 4, 50 + 5 + 10);
    glVertex2f(32 - 5, 50 + 5 + 10);
    glVertex2f(32 - 5, 50 - 15 + 10);
    glVertex2f(32 - 4, 50 - 15 + 10);
    glEnd();

    //Text Information in Frist Page
    if (gv == 1) {
        glColor3f(1.000, 0.000, 0.000);
        renderBitmapString(35, 60 + 10, (void*)font1, "GAME OVER");
        glColor3f(1.000, 0.000, 0.000);
        char buffer2[50];
        sprintf(buffer2, "Your Score is : %d", score);
        renderBitmapString(33, 60 - 4 + 10, (void*)font1, buffer2);
    }

    glColor3f(1.000, 1.000, 0.000);
    renderBitmapString(30, 80, (void*)font1, "2D Car Racing Game ");

    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(30, 50 + 10, (void*)font2, "Press SPACE to START");
    renderBitmapString(30, 50 - 3 + 10, (void*)font2, "Press ESC to Exit");

    glColor3f(1.000, 1.000, 1.000);
    renderBitmapString(30, 50 - 6 + 10, (void*)font3, "Press UP to increase Speed");
    renderBitmapString(30, 50 - 8 + 10, (void*)font3, "Press DWON to decrease Speed");
    renderBitmapString(30, 50 - 10 + 10, (void*)font3, "Press RIGHT to turn Right");
    renderBitmapString(30, 50 - 12 + 10, (void*)font3, "Press LEFT to turn Left");

    glColor3f(0.000, 1.000, 1.000);
    renderBitmapString(30 - 5, 50 - 40, (void*)font3, "Project By:");
    renderBitmapString(30 - 5, 50 - 43, (void*)font3, " Group");
}

void road(){
    ///GreenBar
    glColor3ub(9, 158, 11);
    glBegin(GL_QUADS);
    glVertex2f(0, 100);
    glVertex2f(0, 0);
    glVertex2f(10, 0);
    glVertex2f(10, 100);
    glEnd();

    glColor3ub(9, 158, 11);
    glBegin(GL_QUADS);
    glVertex2f(100, 100);
    glVertex2f(100, 0);
    glVertex2f(90, 0);
    glVertex2f(90, 100);
    glEnd();

    ///WhiteBar
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(10, 100);
    glVertex2f(10, 0);
    glVertex2f(12, 0);
    glVertex2f(12, 100);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(90, 100);
    glVertex2f(90, 0);
    glVertex2f(88, 0);
    glVertex2f(88, 100);
    glEnd();

    ///BlackBar
    glColor3ub(86, 86, 86);
    glBegin(GL_QUADS);
    glVertex2f(12, 100);
    glVertex2f(12, 0);
    glVertex2f(88, 0);
    glVertex2f(88, 100);
    glEnd();

    ///LaneDivider1
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(35, 90);
    glVertex2f(35, 80);
    glVertex2f(37, 80);
    glVertex2f(37, 90);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(35, 75);
    glVertex2f(35, 65);
    glVertex2f(37, 65);
    glVertex2f(37, 75);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(35, 60);
    glVertex2f(35, 50);
    glVertex2f(37, 50);
    glVertex2f(37, 60);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(35, 45);
    glVertex2f(35, 35);
    glVertex2f(37, 35);
    glVertex2f(37, 45);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(35, 30);
    glVertex2f(35, 20);
    glVertex2f(37, 20);
    glVertex2f(37, 30);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(35, 15);
    glVertex2f(35, 5);
    glVertex2f(37, 5);
    glVertex2f(37, 15);
    glEnd();

    ///LaneDivider2
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(63, 90);
    glVertex2f(63, 80);
    glVertex2f(65, 80);
    glVertex2f(65, 90);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(63, 75);
    glVertex2f(63, 65);
    glVertex2f(65, 65);
    glVertex2f(65, 75);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(63, 60);
    glVertex2f(63, 50);
    glVertex2f(65, 50);
    glVertex2f(65, 60);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(63, 45);
    glVertex2f(63, 35);
    glVertex2f(65, 35);
    glVertex2f(65, 45);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(63, 30);
    glVertex2f(63, 20);
    glVertex2f(65, 20);
    glVertex2f(65, 30);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(63, 15);
    glVertex2f(63, 5);
    glVertex2f(65, 5);
    glVertex2f(65, 15);
    glEnd();
}
void car(){
    ///car1
    glColor3ub(206, 206, 206);
    glBegin(GL_QUADS);
    glVertex2f(20, 30);
    glVertex2f(20, 24);
    glVertex2f(25, 24);
    glVertex2f(25, 30);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(20, 35);
    glVertex2f(20, 30);
    glVertex2f(25, 30);
    glVertex2f(25, 35);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(20, 37);
    glVertex2f(20, 35);
    glVertex2f(25, 35);
    glVertex2f(25, 37);
    glEnd();

        ///Glass1
        glColor3ub(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2f(20, 37);
        glVertex2f(19, 37);
        glVertex2f(18.5, 36.5);
        glVertex2f(20, 36.7);
        glEnd();

        ///Glass2
        glColor3ub(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2f(25, 37);
        glVertex2f(26, 37);
        glVertex2f(26.5, 36.5);
        glVertex2f(25, 36.7);
        glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(21, 40);
    glVertex2f(20, 37);
    glVertex2f(25, 37);
    glVertex2f(24, 40);
    glEnd();

    ///car2
    glColor3ub(206, 206, 206);
    glBegin(GL_QUADS);
    glVertex2f(20, 30);
    glVertex2f(20, 24);
    glVertex2f(25, 24);
    glVertex2f(25, 30);
    glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(20, 35);
    glVertex2f(20, 30);
    glVertex2f(25, 30);
    glVertex2f(25, 35);
    glEnd();

    glColor3ub(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2f(20, 37);
    glVertex2f(20, 35);
    glVertex2f(25, 35);
    glVertex2f(25, 37);
    glEnd();

        ///Glass1
        glColor3ub(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2f(20, 37);
        glVertex2f(19, 37);
        glVertex2f(18.5, 36.5);
        glVertex2f(20, 36.7);
        glEnd();

        ///Glass2
        glColor3ub(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2f(25, 37);
        glVertex2f(26, 37);
        glVertex2f(26.5, 36.5);
        glVertex2f(25, 36.7);
        glEnd();

    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2f(21, 40);
    glVertex2f(20, 37);
    glVertex2f(25, 37);
    glVertex2f(24, 40);
    glEnd();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);

    // road();
    // car();
    //

    FrontPage();
    if (start == 1) {
        road();
        car();
    }
    else {
        FrontPage();
    }

    glutSwapBuffers();
    glutPostRedisplay();
    glFlush();
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(700, 700);
    glutCreateWindow("2D Car Racing");
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(processKeys );
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
