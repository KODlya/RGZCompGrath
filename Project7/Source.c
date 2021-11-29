#include <stdio.h>
#include <glut.h>
#include <stdlib.h>

GLfloat xmove = 0, ymove = 0, zmove = 0;
int xspin = 0, yspin = 0;

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(xmove, ymove, 1);
    glRotatef(xspin, 1, 0, 0);
    glRotatef(yspin, 0, 1, 0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP); // front
    glColor3d(0.0, 1, 0.0);
    glVertex3f(30, -30, -30);
    glVertex3f(30, 30, -30);
    glVertex3f(-30, 30, -30);
    glVertex3f(-30, -30, -30);
    glEnd();

    glBegin(GL_LINE_LOOP); //back
    glColor3d(0.0, 1.0, 0.0);
    glVertex3f(30, -30, 30);
    glVertex3f(30, 30, 30);
    glVertex3f(-30, 30, 30);
    glVertex3f(-30, -30, 30);
    glEnd();

    glBegin(GL_LINE_LOOP); //right
    glColor3d(0, 1.0, 0);
    glVertex3f(30, -30, -30);
    glVertex3f(30, 30, -30);
    glVertex3f(30, 30, 30);
    glVertex3f(30, -30, 30);
    glEnd();

    glBegin(GL_LINE_LOOP); //left
    glColor3d(0.0, 1.0, 0.0);
    glVertex3f(-30, -30, 30);
    glVertex3f(-30, 30, 30);
    glVertex3f(-30, 30, -30);
    glVertex3f(-30, -30, -30);
    glEnd();

    glBegin(GL_LINE_LOOP); // top
    glColor3d(0.0, 1.0, 0.0);
    glVertex3f(30, 30, 30);
    glVertex3f(30, 30, -30);
    glVertex3f(-30, 30, -30);
    glVertex3f(-30, 30, 30);
    glEnd();

    glBegin(GL_LINE_LOOP); // bottom
    glColor3d(0.0, 1.0, 0.0);
    glVertex3f(30, -30, -30);
    glVertex3f(30, -30, 30);
    glVertex3f(-30, -30, 30);
    glVertex3f(-30, -30, -30);
    glEnd();

    glBegin(GL_TRIANGLES);
    
    glColor3f(0.94, 0.5, 0.7);
    glVertex3f(20, -20, -20);
    glVertex3f(20, -20, 20);
    glVertex3f(0, 20, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
      // Сделали боковую сторону желтой
    glColor3f(1.0, 0.84, 0.0);// Сделали боковую сторону фиолетовой
    glVertex3f(20, -20, 20);
    glVertex3f(-20, -20, 20);
    glVertex3f(0, 20, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.94, 0.5, 0.5);

    glVertex3f(-20, -20, 20);
    glVertex3f(-20, -20, -20);
    glVertex3f(0, 20, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.5, 1.0, 0.7);  

    glVertex3f(-20, -20, -20);
    glVertex3f(20, -20, -20);
    glVertex3f(0, 20, 0);
    glEnd();

    glBegin(GL_QUADS); // bottom
    glColor3d(0.3, 0.4, 0.9);
    glVertex3f(20, -20, -20);
    glVertex3f(20, -20, 20);
    glVertex3f(-20, -20, 20);    
    glVertex3f(-20, -20, -20);
    glEnd();
    
    glPopMatrix();
    glutSwapBuffers();
}

void timer() {
    glutPostRedisplay();
    glutTimerFunc(5, timer, 0);
}

void keyboardMove(unsigned char key, int x, int y, int z) {
    switch (key) {
    case 'w':
        ymove += 1;
        break;
    case 's':
        ymove -= 1;
        break;
    case 'a':
        xmove -= 1;
        break;
    case 'd':
        xmove += 1;
        break;
    case 'x':
        zmove += 1;
        break;
    case 'z':
        zmove -= 1;
        break;
    case 'q':
        exit(1);
    }
}

void keyboardRotate(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        yspin -= 2;
        yspin %= 360;
        break;
    case GLUT_KEY_RIGHT:
        yspin += 2;
        yspin %= 360;
        break;
    case GLUT_KEY_UP:
        xspin -= 2;
        xspin %= 360;
        break;
    case GLUT_KEY_DOWN:
        xspin += 2;
        xspin %= 360;
        break;
    case GLUT_KEY_F12:
        exit(1);
    }
}

void reshape(GLsizei Width, GLsizei Height) {

    GLfloat AspectRatio;
    if (Height == 0) Height = 1;
    AspectRatio = (GLfloat)Width / (GLfloat)Height;
    glViewport(0, 0, Width, Height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (Width <= Height) {
        glOrtho(-100, 100, -100 / AspectRatio, 100 / AspectRatio, -60, 60);
    }
    else {
        glOrtho(-60 * AspectRatio, 60 * AspectRatio, -60, 60, -60, 60);
    }
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(450, 60);
    glutCreateWindow("Kukartseva AVT-041");
    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0.2, 1);
    glutKeyboardFunc(keyboardMove);
    glutSpecialFunc(keyboardRotate);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(5, timer, 0);
    glutMainLoop();
}