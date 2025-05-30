#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>

// Function to draw a rectangle (quad)
void quad(float r, float g, float b, float x1, float x2, float y1, float y2) {
    glBegin(GL_QUADS);
    glColor3ub(r, g, b);
    glVertex2d(x1, y1);
    glVertex2d(x2, y1);
    glVertex2d(x2, y2);
    glVertex2d(x1, y2);
    glEnd();
}

// Function to draw the building
void building() {
    quad(169, 169, 169, 0, 15, 0, 20);

    quad(255, 255, 255, 2, 4, 5, 7);
    quad(255, 255, 255, 11, 13, 5, 7);
    quad(255, 255, 255, 2, 4, 10, 12);
    quad(255, 255, 255, 11, 13, 10, 12);
    quad(255, 255, 255, 2, 4, 15, 17);
    quad(255, 255, 255, 11, 13, 15, 17);

    quad(139, 69, 19, 6, 9, 0, 3);
}

// Updated Lamppost
void lamppost() {
    quad(169, 169, 169, 25, 27, 0, 12); // Pole
    quad(169, 169, 169, 24, 28, 12, 13); // Light Holder
    quad(255, 255, 0, 25, 27, 13, 14); // Lamp Light
}

// Updated Bench
void bench() {
    glBegin(GL_QUADS);
    glColor3ub(139, 69, 19);
    glVertex2f(30, 0);
    glVertex2f(34, 0);
    glVertex2f(34, 1);
    glVertex2f(30, 1);

    glVertex2f(34, 0);
    glVertex2f(38, 0);
    glVertex2f(38, 1);
    glVertex2f(34, 1);

    glVertex2f(31, 1);
    glVertex2f(34, 1);
    glVertex2f(34, 4);
    glVertex2f(31, 4);

    glVertex2f(34, 1);
    glVertex2f(37, 1);
    glVertex2f(37, 4);
    glVertex2f(34, 4);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(105, 105, 105);
    glVertex2f(30, 0); glVertex2f(31, 0);
    glVertex2f(31, 0); glVertex2f(31, -2);
    glVertex2f(31, -2); glVertex2f(30, -2);
    glVertex2f(30, -2); glVertex2f(30, 0);

    glVertex2f(37, 0); glVertex2f(38, 0);
    glVertex2f(38, 0); glVertex2f(38, -2);
    glVertex2f(38, -2); glVertex2f(37, -2);
    glVertex2f(37, -2); glVertex2f(37, 0);

    glColor3ub(0, 0, 0);
    glVertex2f(34, 0); glVertex2f(34, 4);
    glEnd();
}

// Function to draw the tree
void tree() {
    glColor3ub(99, 73, 18);
    glBegin(GL_QUADS);
    glVertex2f(18, -10);
    glVertex2f(19, -10);
    glVertex2f(19, -5);
    glVertex2f(18, -5);
    glEnd();

    glColor3ub(11, 138, 2);
    glBegin(GL_TRIANGLES);
    glVertex2f(16, -5);
    glVertex2f(20, -5);
    glVertex2f(18, 0);

    glVertex2f(15, -3);
    glVertex2f(21, -3);
    glVertex2f(18, 2);
    glEnd();
}

// Display function to render the scenario
void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    building();
    tree();
    lamppost();
    bench();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Building Scenario");
    glutInitWindowSize(800, 600);
    glutDisplayFunc(display);
    gluOrtho2D(0, 50, -15, 30);
    glutMainLoop();
    return 0;
}
