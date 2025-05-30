
#include <GL/glut.h>

void init() {
   glClearColor(0.0, 0.0, 0.0, 0.0); // Set background color to white
   glMatrixMode(GL_PROJECTION);
   gluOrtho2D(0.0, 80.0, 0.0, 80.0); // Define coordinate system
}

void drawBatmanImage() {

   glColor3f(0.0, 0.0, 0.5);
   glBegin(GL_POLYGON);
      glVertex2f(15.0, 7.0);
      glVertex2f(20.0, 7.0);
      glVertex2f(20.0, 55.0);
      glVertex2f(15.0, 55.0);

   glEnd();
   glColor3f(0.0, 0.0, 0.5);
   glBegin(GL_POLYGON);
      glVertex2f(12.0, 7.0);
      glVertex2f(15.0, 7.0);
      glVertex2f(15.0, 10.0);
      glVertex2f(12.0, 10.0);

   glEnd();

   glColor3f(0.0, 0.0, 0.5);
   glBegin(GL_POLYGON);
      glVertex2f(35.0, 7.0);
      glVertex2f(38.0, 7.0);
      glVertex2f(38.0, 10.0);
      glVertex2f(35.0, 10.0);

   glEnd();

      glColor3f(0.0, 0.0, 0.5);
   glBegin(GL_POLYGON);
      glVertex2f(30.0, 7.0);
      glVertex2f(35.0, 7.0);
      glVertex2f(35.0, 55.0);
      glVertex2f(30.0, 55.0);

   glEnd();

    glColor3f(0.0 , 1.0, 1.0);
   glBegin(GL_POLYGON);
      glVertex2f(15.0, 37.0);
      glVertex2f(35.0, 37.0);
      glVertex2f(35.0, 50.0);
      glVertex2f(15.0, 50.0);

   glEnd();

   glColor3f(1.0 , 1.0, 0.0);
   glBegin(GL_POLYGON);
      glVertex2f(15.0, 37.0);
      glVertex2f(35.0, 37.0);
      glVertex2f(35.0, 32.0);
      glVertex2f(15.0, 32.0);

   glEnd();

  glColor3f(169, 169, 169);
   glBegin(GL_QUADS);

        /*glVertex2f(10.0, 7.0);
       glVertex2f(20.0, 7.0);
       glVertex2f(20.0, 55.0);
       glVertex2f(15.0, 7.0);*/


   glEnd();
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);

   drawBatmanImage();


   glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(900,600);           // Set window size
   glutCreateWindow("Batman Image");
   init();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
