#include <windows.h>
#include <GL/glut.h>

void mydisplay() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Roof
    glColor3f(0.3f, 0.5f, 0.8f);  // Light blue
    glBegin(GL_POLYGON);
        glVertex2i(200, 500);
        glVertex2i(600, 500);
        glVertex2i(700, 350);
        glVertex2i(300, 350);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2i(200, 500);
        glVertex2i(100, 350);
        glVertex2i(300, 350);
    glEnd();

    // Left Wall
    glColor3f(0.7f, 0.2f, 0.3f);  // Red
    glBegin(GL_POLYGON);
        glVertex2i(100, 350);
        glVertex2i(300, 350);
        glVertex2i(300, 100);
        glVertex2i(100, 100);
    glEnd();

    // Right Wall
    glColor3f(0.1f, 0.2f, 0.3f);  // Dark blue
    glBegin(GL_POLYGON);
        glVertex2i(300, 350);
        glVertex2i(700, 350);
        glVertex2i(700, 100);
        glVertex2i(300, 100);
    glEnd();

    // Door
    glColor3f(0.7f, 0.2f, 0.9f);  // Purple
    glBegin(GL_POLYGON);
        glVertex2i(450, 250);
        glVertex2i(550, 250);
        glVertex2i(550, 100);
        glVertex2i(450, 100);
    glEnd();

    // Left Window
    glColor3f(0.0f, 0.7f, 1.0f);  // Cyan for window glass
    glBegin(GL_POLYGON);
        glVertex2i(150, 250);
        glVertex2i(250, 250);
        glVertex2i(250, 200);
        glVertex2i(150, 200);
    glEnd();

    // Right Window
    glColor3f(0.0f, 0.7f, 1.0f);  // Cyan for window glass
    glBegin(GL_POLYGON);
        glVertex2i(400, 250);
        glVertex2i(500, 250);
        glVertex2i(500, 200);
        glVertex2i(400, 200);
    glEnd();

    // Window Borders for Left Window
    glColor3f(0.0f, 0.0f, 0.0f);  // Black borders
    glBegin(GL_LINES);
        glVertex2i(200, 250);
        glVertex2i(200, 200);
        glVertex2i(150, 225);
        glVertex2i(250, 225);
    glEnd();

    // Window Borders for Right Window
    glBegin(GL_LINES);
        glVertex2i(450, 250);
        glVertex2i(450, 200);
        glVertex2i(400, 225);
        glVertex2i(500, 225);
    glEnd();

    glFlush();
}

void myInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("House Drawing");
    glutDisplayFunc(mydisplay);
    myInit();
    glutMainLoop();
    return 0;
}
