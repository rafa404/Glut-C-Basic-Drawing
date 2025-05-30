
#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void quad(float r, float g, float b, float x1, float x2, float y1, float y2) {
    glBegin(GL_QUADS);
    glColor3ub(r, g, b);
    glVertex2d(x1, y1);
    glVertex2d(x2, y1);
    glVertex2d(x2, y2);
    glVertex2d(x1, y2);
    glEnd();
}

void triangle(float r, float g, float b, float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glColor3ub(r, g, b);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glVertex2d(x3, y3);
    glEnd();
}

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Tree trunk
    quad(139, 69, 19, 18, 20, 0, 4);

    // Tree leaves
    triangle(0, 128, 0, 16, 4, 22, 4, 19, 9);
    triangle(0, 128, 0, 17, 6, 21, 6, 19, 11);
    triangle(0, 128, 0, 18, 8, 20, 8, 19, 12);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Tree Design");
    glutInitWindowSize(500, 500);
    glutDisplayFunc(display);
    gluOrtho2D(0, 25, 0, 15);
    glutMainLoop();
    return 0;
}
