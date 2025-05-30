#include <GL/glut.h>
#include <iostream>

int Xc, Yc, R;  // Center (Xc, Yc) and radius (R)

// Function to plot the symmetric points of the circle
void plot(int x, int y) {
    glBegin(GL_POINTS);
        glVertex2i(Xc + x, Yc + y);  // Top-right
        glVertex2i(Xc - x, Yc + y);  // Top-left
        glVertex2i(Xc + x, Yc - y);  // Bottom-right
        glVertex2i(Xc - x, Yc - y);  // Bottom-left
        glVertex2i(Xc + y, Yc + x);  // Right-top diagonal
        glVertex2i(Xc - y, Yc + x);  // Left-top diagonal
        glVertex2i(Xc + y, Yc - x);  // Right-bottom diagonal
        glVertex2i(Xc - y, Yc - x);  // Left-bottom diagonal
    glEnd();
}

// Midpoint Circle Algorithm to draw a circle
void MidpointCircle(void) {
    int x = 0;           // Starting x-coordinate
    int y = R;           // Starting y-coordinate (on the circle)
    int p = 1 - R;       // Initial decision parameter (1 - R)

    glClear(GL_COLOR_BUFFER_BIT);  // Clear the window

    while (x <= y) {  // Loop until x exceeds y (for the upper half circle)
        plot(x, y);   // Plot the 8 symmetric points for each iteration

        if (p < 0) {
            p += 2 * x + 3;  // Midpoint is inside the circle
        } else {
            p += 2 * (x - y) + 5;  // Midpoint is outside or on the circle
            y--;  // Move y down
        }
        x++;  // Always increment x
    }

    glFlush();  // Flush the OpenGL commands to the screen
}

// OpenGL initialization
void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);  // Set background color to white
    glColor3f(0.0, 0.0, 0.0);          // Set point color to black (for the circle)
    glPointSize(4.0);                  // Set point size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);  // Define orthogonal projection
}

// Main function
int main(int argc, char** argv) {
    std::cout << "Enter the center coordinates (Xc, Yc): ";
    std::cin >> Xc >> Yc;
    std::cout << "Enter the radius (R): ";
    std::cin >> R;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);         // Set window size
    glutInitWindowPosition(100, 150);     // Set window position
    glutCreateWindow("Midpoint Circle Drawing");

    glutDisplayFunc(MidpointCircle);  // Register the display function
    myInit();  // Call OpenGL initialization
    glutMainLoop();  // Enter the OpenGL event-processing loop

    return 0;
}
