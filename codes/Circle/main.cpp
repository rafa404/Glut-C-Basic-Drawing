#include <windows.h>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

int Xc, Yc, R;

void plot(int x, int y) {
    glBegin(GL_POINTS);
        glVertex2i(Xc + x, Yc + y);
        glVertex2i(Xc - x, Yc + y);
        glVertex2i(Xc + x, Yc - y);
        glVertex2i(Xc - x, Yc - y);
        glVertex2i(Xc + y, Yc + x);
        glVertex2i(Xc - y, Yc + x);
        glVertex2i(Xc + y, Yc - x);
        glVertex2i(Xc - y, Yc - x);
    glEnd();
}

void MidpointCircle(void) {
    int x = 0;
    int y = R;
    int p = 1 - R;

    glClear(GL_COLOR_BUFFER_BIT);

    while (x <= y) {
        plot(x, y);
        if (p < 0) {
            p += 2 * x + 3;
        } else {
            p += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }

    glFlush();
}

void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv) {
    cout << "Enter the center coordinates:\t";
    cin >> Xc >> Yc;
    cout << "Enter the radius:\t";
    cin >> R;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Midpoint Circle Drawing Algorithm");

    glutDisplayFunc(MidpointCircle);
    myInit();
    glutMainLoop();
}
