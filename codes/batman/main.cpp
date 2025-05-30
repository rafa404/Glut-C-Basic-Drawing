#include <GL/glut.h>

// Screen dimensions
const int width = 800;
const int height = 800;

// Function to draw a single pixel with color
void drawPixel(int x, int y, float r, float g, float b) {
    glColor3f(r, g, b);  // Set the pixel color
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Function to render the batman pixel art
void renderBatman() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Example pixel data (replace with actual batman pixel data)
    int batmanPixels[][4] = {
        {10, 10, 0, 0},  // x, y, red, green, blue
        {10, 11, 0, 0},  // Add more pixels for the actual batman drawing
        // Add the entire structure here
    };

    // Draw each pixel from the pixel data
    for (int i = 0; i < sizeof(batmanPixels) / sizeof(batmanPixels[0]); ++i) {
        int x = batmanPixels[i][0];
        int y = batmanPixels[i][1];
        float r = batmanPixels[i][2] / 255.0f; // Normalize 0-255 color to 0-1
        float g = batmanPixels[i][3] / 255.0f;
        float b = batmanPixels[i][4] / 255.0f;
        drawPixel(x, y, r, g, b);
    }

    glFlush();
}

// OpenGL Initialization
void myInit() {
    glClearColor(1.0, 1.0, 1.0, 0.0);  // White background
    glColor3f(0.0, 0.0, 0.0);          // Black points by default
    glPointSize(5.0);                  // Increase point size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, width, 0.0, height);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Pixel Art - Batman");

    glutDisplayFunc(renderBatman);
    myInit();
    glutMainLoop();

    return 0;
}

