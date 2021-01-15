#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<GL/glut.h>
#include <math.h>
#include <string.h>
#include <graphics.h>

GLint Xsize = 1366;
GLint Ysize = 768;
float theta;
GLfloat xt = 0.0, yt = 0.0, zt = 0.0, xw = 0.0;
bool open = 0;
GLfloat xangle = 7, yangle = 20, zangle = 0.0;

static void onMouseButton(int Key, int state, int x, int y) {
    switch (Key) {
        case GLUT_LEFT_BUTTON :
            xt += 0.1;
            glutPostRedisplay();
            break;

        case GLUT_RIGHT_BUTTON :
            xt -= 0.1;
            glutPostRedisplay();
            break;
    }
}


GLvoid DrawGLScene() {
// initially
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();// reset the matrix

    glClearColor(0, 250, 250, 0); // COLOR OR BACKGROUND
    glViewport(0, 0, Xsize, Ysize);// Size of the edit of opengl screen
    glLoadIdentity();   // reset the matrix
    gluPerspective(100, Xsize / Ysize, 0.1, 150);  //control the diminution of the way we look to the scene


    glMatrixMode(GL_MODELVIEW); // back to view mode
    glLoadIdentity();

    glTranslatef(0, 0, -3.5);

    // associate the variable that we pass and the paramter who's values is 1 so any change in this varaible will cause a change on the value of
    glRotatef(xangle, 1.0, 0.0, 0.0);
    glRotatef(yangle, 0.0, 1.0, 0.0);
    glRotatef(zangle, 0.0, 0.0, 1.0);
    /**/  glTranslatef(xt, yt, zt);


////////////////////////front////////////
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.5);

    // up
    glVertex3f(0.2, 0.4, 0.6);
    glVertex3f(0.6, 0.5, 0.6);
    glVertex3f(0.6, 0.5, 0.2);
    glVertex3f(0.2, 0.4, 0.2);

    // front

    glVertex3f(0.2, 0.2, 0.6);
    glVertex3f(0.2, 0.4, 0.6);
    glVertex3f(0.2, 0.4, 0.2);
    glVertex3f(0.2, 0.2, 0.2);

//back
    glVertex3f(0.6, 0.2, 0.6);
    glVertex3f(0.6, 0.5, 0.6);
    glVertex3f(0.6, 0.5, 0.2);
    glVertex3f(0.6, 0.2, 0.2);

    //left
    glVertex3f(0.2, 0.2, 0.6);
    glVertex3f(0.6, 0.2, 0.6);
    glVertex3f(0.6, 0.5, 0.6);
    glVertex3f(0.2, 0.4, 0.6);

    // right
    glVertex3f(0.2, 0.2, 0.2);
    glVertex3f(0.6, 0.2, 0.2);
    glVertex3f(0.6, 0.5, 0.2);
    glVertex3f(0.2, 0.4, 0.2);

/////////////////////////////////////////////////////

    glVertex3f(0.7, 0.65, 0.6);
    glVertex3f(0.7, 0.65, 0.2);
    glVertex3f(1.7, 0.65, 0.2);        //cover
    glVertex3f(1.7, 0.65, 0.6);
//////////////////back//////////////////////
    // up
    glVertex3f(1.8, 0.5, 0.6);
    glVertex3f(1.8, 0.5, 0.2);
    glVertex3f(2.1, 0.4, 0.2);
    glVertex3f(2.1, 0.4, 0.6);

    // back
    glVertex3f(2.1, 0.4, 0.6);
    glVertex3f(2.1, 0.4, 0.2);
    glVertex3f(2.1, 0.2, 0.2);
    glVertex3f(2.1, 0.2, 0.6);

    // left
    glVertex3f(1.8, 0.2, 0.2);
    glVertex3f(1.8, 0.5, 0.2);
    glVertex3f(2.1, 0.4, 0.2);
    glVertex3f(2.1, 0.2, 0.2);

    // Right
    glVertex3f(1.8, 0.2, 0.6);
    glVertex3f(1.8, 0.5, 0.6);
    glVertex3f(2.1, 0.4, 0.6);
    glVertex3f(2.1, 0.2, 0.6);

///////////////////MIDDLE //////////////////

    if (!open) {

        // front
        glVertex3f(0.6, 0.5, 0.6);
        glVertex3f(0.6, 0.2, 0.6);
        glVertex3f(1.8, 0.2, 0.6);
        glVertex3f(1.8, 0.5, 0.6);

    } else {
//middle with diffrent color
        glColor3f(0, 0, 0);
        glVertex3f(0.6, 0.5, 0.3);
        glVertex3f(0.6, 0.2, 0.3);
        glVertex3f(1.8, 0.2, 0.3);
        glVertex3f(1.8, 0.5, 0.3);
//door 1 blue
        glColor3f(0.1, 0.1, 0.5);
        glVertex3f(1.2, 0.5, 0.5);
        glVertex3f(1.2, 0.2, 0.5);
        glVertex3f(1.22, 0.2, 1);
        glVertex3f(1.22, 0.5, 1);
// door 1 black
        glColor3f(0, 0, 0);
        glVertex3f(1.22, 0.5, 0.5);
        glVertex3f(1.22, 0.2, 0.5);
        glVertex3f(1.222, 0.2, 1);
        glVertex3f(1.222, 0.5, 1);
// door 2 blue
        glColor3f(0.1, 0.1, 0.5);
        glVertex3f(0.7, 0.5, 0.5);
        glVertex3f(0.7, 0.2, 0.5);
        glVertex3f(0.7, 0.2, 1);
        glVertex3f(0.7, 0.5, 1);

        // door 2 black
        glColor3f(0, 0, 0);
        glVertex3f(0.71, 0.5, 0.5);
        glVertex3f(0.71, 0.2, 0.5);
        glVertex3f(0.71, 0.2, 1);
        glVertex3f(0.71, 0.5, 1);


    }
    glColor3f(0.1, 0.1, 0.5);

    //bottom
    glVertex3f(0.6, 0.2, 0.6);
    glVertex3f(0.6, 0.2, 0.2);
    glVertex3f(1.8, 0.2, 0.2);
    glVertex3f(1.8, 0.2, 0.6);
    //back
    glVertex3f(0.6, 0.5, 0.2);
    glVertex3f(0.6, 0.2, 0.2);
    glVertex3f(1.8, 0.2, 0.2);
    glVertex3f(1.8, 0.5, 0.2);
    
///////////////////////window///////////////////////

    glColor3f(0.3, 0.3, 0.3);
    glVertex3f(0.77, 0.63, 0.2);
    glVertex3f(0.75, 0.5, 0.2);        //front 1
    glVertex3f(1.2, 0.5, 0.2);
    glVertex3f(1.22, 0.63, 0.2);

    glVertex3f(1.27, 0.63, .2);
    glVertex3f(1.25, 0.5, 0.2);        //back1
    glVertex3f(1.65, 0.5, 0.2);
    glVertex3f(1.67, 0.63, 0.2);

    glVertex3f(0.77, 0.63, 0.6);
    glVertex3f(0.75, 0.5, 0.6);        //front 2
    glVertex3f(1.2, 0.5, 0.6);
    glVertex3f(1.22, 0.63, 0.6);

    glVertex3f(1.27, 0.63, .6);
    glVertex3f(1.25, 0.5, 0.6);        //back2
    glVertex3f(1.65, 0.5, 0.6);
    glVertex3f(1.67, 0.63, 0.6);


////////////////////////////////road//////////////////////////

    glColor3f(0, 0.7, 0);
    glVertex3f(-1000, 0.1, -1000);
    glVertex3f(-100, 0.1, 0);         //a green
    glVertex3f(100, 0.1, 0);
    glVertex3f(1000, 0.1, -1000);

    glColor3f(0, 0, 0);
    glVertex3f(-100, 0.1, 0);
    glVertex3f(-100, 0.1, 0.45);         //a long road
    glVertex3f(100, 0.1, 0.45);
    glVertex3f(100, 0.1, 0);

    glColor3f(250, 250, 250);
    glVertex3f(-100, 0.1, 0.45);       //a median
    glVertex3f(-100, 0.1, 0.55);
    glVertex3f(100, 0.1, 0.55);
    glVertex3f(100, 0.1, 0.45);

    glColor3f(0, 0, 0);
    glVertex3f(-100, 0.1, 0.55);
    glVertex3f(-100, 0.1, 1);         //a long road
    glVertex3f(100, 0.1, 1);
    glVertex3f(100, 0.1, 0.55);

    glColor3f(0, 0.7, 0);;
    glVertex3f(-1000, 0.1, 1);
    glVertex3f(-1000, 0.1, 1000);         //a green
    glVertex3f(1000, 0.1, 1000);
    glVertex3f(1000, 0.1, 1);

    glEnd();
    /**/
    glPushMatrix();

    glColor3f(0, 0, 0);// color of wheel

    glTranslatef(0.6, 0.2, 0.6); //wheels coordinte
    glutSolidTorus(0.025, 0.07, 6, 25);

    glTranslatef(0, 0, -0.4); //wheels coordinte
    glutSolidTorus(0.025, 0.07, 10, 25);

    glTranslatef(1.1, 0, 0); //wheels coordinte
    glutSolidTorus(0.025, 0.07, 10, 25);

    glTranslatef(0, 0, 0.4);//wheels coordinte
    glutSolidTorus(0.025, 0.07, 10, 25);


    //////SUN/////////////////
    glColor3f(1, 1, 0);// sun color
    glTranslatef(-4, 1, 0.6); //sun coordinate
    glutSolidTorus(0.15, 0.01, 50, 25); // sun DIMANTIONS

    ///////////FLAT CLOUD/////////////

    glColor3f(1, 1, 1);//cloud color
    glTranslatef(1, 0, 0); // cloud coordinate
    glutSolidTorus(0.4, 0.07, 7, 2.8888888888); //// cloud DIMANTIONS

    glColor3f(1, 1, 1);//
    glTranslatef(-1, 0, 0);
    glutSolidTorus(0.4, 0.07, 7, 2.8888888888);


    glColor3f(1, 1, 1);//
    glTranslatef(3, 0, 0); //
    glutSolidTorus(0.4, 0.07, 7, 2.8888888888);

    glColor3f(1, 1, 1);//
    glTranslatef(3, 0, 0); //
    glutSolidTorus(0.4, 0.07, 7, 2.8888888888);

    glColor3f(1, 1, 1);//
    glTranslatef(1.5, 0, 0); //
    glutSolidTorus(0.4, 0.07, 7, 2.8888888888);


    glColor3f(1, 1, 1);//
    glTranslatef(1.5, 0, 0); //
    glutSolidTorus(0.4, 0.07, 7, 2.8888888888);


//*************************************************************

    glEnable(GL_DEPTH_TEST); // lma tgher depth el view el shkl msh byzhr
    glutPostRedisplay();   // btzbt el shkl
    glutSwapBuffers();
}


/*  The function called whenever a "normal" key is pressed. */
void NormalKey(GLubyte key, GLint x, GLint y) {
    DrawGLScene();
    switch (key) {
        case 'x':
            xangle += 5.0;
            glutPostRedisplay();
            break;

        case 'X':
            xangle -= 5.0;
            glutPostRedisplay();
            break;

        case 'y':
            yangle += 5.0;
            glutPostRedisplay();
            break;

        case 'Y':
            yangle -= 5.0;
            glutPostRedisplay();
            break;

        case 'z':
            zangle += 5.0;
            glutPostRedisplay();
            break;

        case 'Z':
            zangle -= 5.0;
            glutPostRedisplay();
            break;


        case '+':
            zt += 0.2;
            glutPostRedisplay();
            break;

        case '-':
            zt -= 0.2;
            glutPostRedisplay();
            break;
        case 'o':
            open = !open;
            glutPostRedisplay();
            break;
        default:
            break;
    }

}
//*************************** Main ***************************************************************
int main(int argc, char **argv) {
    
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGBA |
                        GLUT_DOUBLE |
                        GLUT_DEPTH);

    glutInitWindowSize(Xsize, Ysize);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("");
    glutDisplayFunc(DrawGLScene);
    glutKeyboardFunc(NormalKey);
    glutMouseFunc(onMouseButton);
    glutMainLoop();
    return 1;
}
