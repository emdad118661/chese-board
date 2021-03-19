/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */
#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;


 
void myDisplay(void)
{
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);
    bool f = false;

    for (int x=0; x<=800; x+=100)
    {
        for(int y=0; y<=800; y+=100)
        {

            if(f)
            {
                glColor3ub(0,0,0);
                f=!f;
            }

            else
            {
                glColor3ub(255, 255, 255);
                f=!f;
            }

            glBegin(GL_QUADS);
            glVertex2i(x, y);
            glVertex2i(x, y+100 );
            glVertex2i(x+100, y+100);
            glVertex2i(x+100, y);
            glEnd();
            glFlush();
        }
    }

}

void myInit (void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0.0, 800, 0.0, 800.0);
}

main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Chess");
    glutDisplayFunc(myDisplay);

    myInit();
    glutMainLoop();
}
