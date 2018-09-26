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

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

static int slices = 16;
static int stacks = 16;
GLfloat dx = 0, dy=0, dz=0;
GLfloat theta = 0;
GLfloat sx=1, sy=1, sz=1;

/* GLUT callback Handlers */

void displayTringle()
{
    glBegin(GL_TRIANGLES);
        glVertex3f(0,0,0);
        glVertex3f(1,0,0);
        glVertex3f(0,1,0);

    glEnd();
}

void pyramid(){

    glBegin(GL_TRIANGLES);
    glColor3d(1,0,0);
        glVertex3d(0,2,0);
        glVertex3d(-1,0,1);
        glVertex3d(1,0,1);

    glColor3d(0,1,0.7);
        glVertex3d(0,2,0);
        glVertex3d(1,0,1);
        glVertex3d(1,0,-1);

    glColor3d(1,0,0);
        glVertex3d(0,2,0);
        glVertex3d(1,0,-1);
        glVertex3d(-1,0,-1);

    glColor3d(0,1,0.7);
        glVertex3d(0,2,0);
        glVertex3d(-1,0,-1);
        glVertex3d(-1,0,1);

    glEnd();

    glBegin(GL_QUADS);

    glColor3d(0,0,1);
        glVertex3d(1,0,1);
        glVertex3d(-1,0,1);
        glVertex3d(-1,0,-1);
        glVertex3d(1,0,-1);
    glEnd();



}


void displayPyramid()
{
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
        glVertex3d(0,2,0);
        glVertex3d(-1,0,1);
        glVertex3d(1,0,1);

    glColor3f(0,1,0);
        glVertex3d(0,2,0);
        glVertex3d(1,0,1);
        glVertex3d(1,0,-1);

    glColor3f(0,0,1);
        glVertex3d(0,2,0);
        glVertex3d(1,0,-1);
        glVertex3d(-1,0,-1);


    glColor3f(0,1,1);
        glVertex3d(0,2,0);
        glVertex3d(-1,0,-1);
        glVertex3d(-1,0,1);

    glEnd();

    glBegin(GL_QUADS);
    glColor3f(.5,.1,.5);
        glVertex3d(1,0,1);
        glVertex3d(-1,0,1);
        glVertex3d(-1,0,-1);
        glVertex3d(1,0,-1);
    glEnd();

}


void nationalMemorial()
{
    glBegin(GL_TRIANGLES);
    // First front block
        glVertex3d(0,3,0);
        glVertex3d(-0.3,0,0);
        glVertex3d(0.3,0,0);

        glVertex3d(0,3,0);
        glVertex3d(0.3,0,0);
        glVertex3d(-0.3,0,0);

    //Second block
    glColor3f(0,0,0);
        //left half
        glVertex3d(0,2.7,-.1);
        glVertex3d(-.6,0,0);
        glVertex3d(0,0,-.3);

        glVertex3d(0,2.7,-.1);
        glVertex3d(0,0,-.3);
        glVertex3d(-.6,0,0);

        //right half
        glVertex3d(0,2.7,-.1);
        glVertex3d(.6,0,0);
        glVertex3d(0,0,-.3);

        glVertex3d(0,2.7,-.1);
        glVertex3d(0,0,-.3);
        glVertex3d(.6,0,0);

    //Third block
    glColor3f(0,1,0);
        //left half
        glVertex3d(0,2.4,-.2);
        glVertex3d(-.9,0,0);
        glVertex3d(0,0,-.6);

        glVertex3d(0,2.4,-.2);
        glVertex3d(0,0,-.6);
        glVertex3d(-.9,0,0);

        //right half
        glVertex3d(0,2.4,-.2);
        glVertex3d(.9,0,0);
        glVertex3d(0,0,-.6);

        glVertex3d(0,2.4,-.2);
        glVertex3d(0,0,-.6);
        glVertex3d(.9,0,0);


    //Forth block
    glColor3f(0,1,1);
        //left half
        glVertex3d(0,2.1,-.3);
        glVertex3d(-1.2,0,0);
        glVertex3d(0,0,-.9);

        glVertex3d(0,2.1,-.3);
        glVertex3d(0,0,-.9);
        glVertex3d(-1.2,0,0);

        //right half
        glVertex3d(0,2.1,-.3);
        glVertex3d(1.2,0,0);
        glVertex3d(0,0,-.9);

        glVertex3d(0,2.1,-.3);
        glVertex3d(0,0,-.9);
        glVertex3d(1.2,0,0);

    //Fifth block
    glColor3f(0,.1,.8);
        //left half
        glVertex3d(0,1.8,-.4);
        glVertex3d(-1.5,0,0);
        glVertex3d(0,0,-1.2);

        glVertex3d(0,1.8,-.4);
        glVertex3d(0,0,-1.2);
        glVertex3d(-1.5,0,0);

        //right half
        glVertex3d(0,1.8,-.4);
        glVertex3d(1.5,0,0);
        glVertex3d(0,0,-1.2);

        glVertex3d(0,1.8,-.4);
        glVertex3d(0,0,-1.2);
        glVertex3d(1.5,0,0);


    glEnd();
}


void nationalMemorialLoop()
{
    float y_values[] = {3, 2.6, 2.2, 1.75, 1.5, 1.2, .8};
    float x_values[] = {.3, .6, .9, 1.2, 1.5, 1.8, 2.1};
    float z_values[] = {.15, .3, .6, .9, 1.2, 1.5, 1.6};
    float z_top[] = {.15, .3, .6, .9, 1.2, 1.5, 1.6};
    //float z_top[] = {.1,.2,.35,.5,.7,1};

    float color_x[] = {1,0,0,.5,1,.5,0};
    float color_y[] = {0,0,1,0,1,0,0};
    float color_z[] = {0,1,1,1,.0,.5,0};

    glBegin(GL_TRIANGLES);
    for(int i=0; i<7; i++){
        glColor3f(color_x[i],color_y[i],color_z[i]);
        //left half
        glVertex3d(0,y_values[i],-z_top[i]);
        glVertex3d(-x_values[i],0,0);
        glVertex3d(0,0,-z_values[i]);

        glVertex3d(0,y_values[i],-z_top[i]);
        glVertex3d(0,0,-z_values[i]);
        glVertex3d(-x_values[i],0,0);

        //right half
        glVertex3d(0,y_values[i],-z_top[i]);
        glVertex3d(x_values[i],0,0);
        glVertex3d(0,0,-z_values[i]);

        glVertex3d(0,y_values[i],-z_top[i]);
        glVertex3d(0,0,-z_values[i]);
        glVertex3d(x_values[i],0,0);

    }

    glEnd();

    //table
    glBegin(GL_QUADS);
    glColor3f(.37,.21,0.15);
        //base
        glVertex3d(2.5,0,-2.5);
        glVertex3d(-2.5,0,-2.5);
        glVertex3d(-2.5,0,2.5);
        glVertex3d(2.5,0,2.5);

        glVertex3d(2.5,-.1,2.5);
        glVertex3d(-2.5,-.1,2.5);
        glVertex3d(-2.5,-.1,-2.5);
        glVertex3d(2.5,-.1,-2.5);

        //side: thickness
        glVertex3d(-2.5,0,2.5);
        glVertex3d(-2.5,-.1,2.5);
        glVertex3d(2.5,-.1,2.5);
        glVertex3d(2.5,0,2.5);


        glVertex3d(2.5,0,2.5);
        glVertex3d(2.5,-.1,2.5);
        glVertex3d(2.5,-.1,-2.5);
        glVertex3d(2.5,0,-2.5);

        glVertex3d(2.5,0,-2.5);
        glVertex3d(2.5,-.1,-2.5);
        glVertex3d(-2.5,-.1,-2.5);
        glVertex3d(-2.5,0,-2.5);

        glVertex3d(-2.5,0,-2.5);
        glVertex3d(-2.5,-.1,-2.5);
        glVertex3d(-2.5,-.1,2.5);
        glVertex3d(-2.5,0,2.5);

        //leg1
        glVertex3d(2.3,0,2.4);
        glVertex3d(2.3,-2,2.4);
        glVertex3d(2.4,-2,2.4);
        glVertex3d(2.4,0,2.4);


        glVertex3d(2.4,0,2.4);
        glVertex3d(2.4,-2,2.4);
        glVertex3d(2.4,-2,2.3);
        glVertex3d(2.4,0,2.3);

        glVertex3d(2.4,0,2.3);
        glVertex3d(2.4,-2,2.3);
        glVertex3d(2.3,-2,2.3);
        glVertex3d(2.3,0,2.3);

        glVertex3d(2.3,0,2.3);
        glVertex3d(2.3,-2,2.3);
        glVertex3d(2.3,-2,2.4);
        glVertex3d(2.3,0,2.4);

        //bottom base of leg 1
        glVertex3d(2.3,-2,2.3);
        glVertex3d(2.4,-2,2.3);
        glVertex3d(2.4,-2,2.4);
        glVertex3d(2.3,-2,2.4);


        //leg2
        glVertex3d(-2.3,0,-2.4);
        glVertex3d(-2.3,-2,-2.4);
        glVertex3d(-2.4,-2,-2.4);
        glVertex3d(-2.4,0,-2.4);


        glVertex3d(-2.4,0,-2.4);
        glVertex3d(-2.4,-2,-2.4);
        glVertex3d(-2.4,-2,-2.3);
        glVertex3d(-2.4,0,-2.3);

        glVertex3d(-2.4,0,-2.3);
        glVertex3d(-2.4,-2,-2.3);
        glVertex3d(-2.3,-2,-2.3);
        glVertex3d(-2.3,0,-2.3);

        glVertex3d(-2.3,0,-2.3);
        glVertex3d(-2.3,-2,-2.3);
        glVertex3d(-2.3,-2,-2.4);
        glVertex3d(-2.3,0,-2.4);

        //bottom base of leg 1
        glVertex3d(-2.3,-2,-2.3);
        glVertex3d(-2.4,-2,-2.3);
        glVertex3d(-2.4,-2,-2.4);
        glVertex3d(-2.3,-2,-2.4);


        //leg3
        glVertex3d(2.3,0,-2.4);
        glVertex3d(2.3,-2,-2.4);
        glVertex3d(2.4,-2,-2.4);
        glVertex3d(2.4,0,-2.4);


        glVertex3d(2.4,0,-2.4);
        glVertex3d(2.4,-2,-2.4);
        glVertex3d(2.4,-2,-2.3);
        glVertex3d(2.4,0,-2.3);

        glVertex3d(2.4,0,-2.3);
        glVertex3d(2.4,-2,-2.3);
        glVertex3d(2.3,-2,-2.3);
        glVertex3d(2.3,0,-2.3);

        glVertex3d(2.3,0,-2.3);
        glVertex3d(2.3,-2,-2.3);
        glVertex3d(2.3,-2,-2.4);
        glVertex3d(2.3,0,-2.4);

        //bottom base of leg 1
        glVertex3d(2.3,-2,-2.3);
        glVertex3d(2.4,-2,-2.3);
        glVertex3d(2.4,-2,-2.4);
        glVertex3d(2.3,-2,-2.4);


        //leg4
        glVertex3d(-2.3,0,2.4);
        glVertex3d(-2.3,-2,2.4);
        glVertex3d(-2.4,-2,2.4);
        glVertex3d(-2.4,0,2.4);


        glVertex3d(-2.4,0,2.4);
        glVertex3d(-2.4,-2,2.4);
        glVertex3d(-2.4,-2,2.3);
        glVertex3d(-2.4,0,2.3);

        glVertex3d(-2.4,0,2.3);
        glVertex3d(-2.4,-2,2.3);
        glVertex3d(-2.3,-2,2.3);
        glVertex3d(-2.3,0,2.3);

        glVertex3d(-2.3,0,2.3);
        glVertex3d(-2.3,-2,2.3);
        glVertex3d(-2.3,-2,2.4);
        glVertex3d(-2.3,0,2.4);

        //bottom base of leg 1
        glVertex3d(-2.3,-2,2.3);
        glVertex3d(-2.4,-2,2.3);
        glVertex3d(-2.4,-2,2.4);
        glVertex3d(-2.3,-2,2.4);

glColor3f(0, 0, 0);
        //wall 1
        glVertex3d(-4,2,-3.9);
        glVertex3d(-4,-2,-3.9);
        glVertex3d(4,-2,-3.9);
        glVertex3d(4,2,-3.9);


        glVertex3d(4,2,-3.9);
        glVertex3d(4,-2,-3.9);
        glVertex3d(4,-2,-4);
        glVertex3d(4,2,-4);

        glVertex3d(4,2,-4);
        glVertex3d(4,-2,-4);
        glVertex3d(-4,-2,-4);
        glVertex3d(-4,2,-4);

        glVertex3d(-4,2,-4);
        glVertex3d(-4,-2,-4);
        glVertex3d(-4,-2,-3.9);
        glVertex3d(-4,2,-3.9);

        //bottom base of leg 1
        glVertex3d(-4,-2,-4);
        glVertex3d(4,-2,-4);
        glVertex3d(4,-2,-3.9);
        glVertex3d(-4,-2,-3.9);



        //wall 2
        glVertex3d(4,2,3.9);
        glVertex3d(4,-2,3.9);
        glVertex3d(4,-2,-3.9);
        glVertex3d(4,2,-3.9);


        glVertex3d(4,2,-3.9);
        glVertex3d(4,-2,-3.9);
        glVertex3d(4,-2,-4);
        glVertex3d(4,2,-4);

        glVertex3d(4,2,-4);
        glVertex3d(4,-2,-4);
        glVertex3d(4,-2,4);
        glVertex3d(4,2,4);

        glVertex3d(4,2,4);
        glVertex3d(4,-2,4);
        glVertex3d(4,-2,3.9);
        glVertex3d(4,2,3.9);

        //bottom base of leg 1
        glVertex3d(4,-2,4);
        glVertex3d(4,-2,-4);
        glVertex3d(4,-2,-3.9);
        glVertex3d(4,-2,3.9);

        //wall 3
        glVertex3d(-4,2,-3.9);
        glVertex3d(-4,-2,-3.9);
        glVertex3d(-4,-2,3.9);
        glVertex3d(-4,2,3.9);


        glVertex3d(-4,2,3.9);
        glVertex3d(-4,-2,3.9);
        glVertex3d(-4,-2,4);
        glVertex3d(-4,2,4);

        glVertex3d(-4,2,4);
        glVertex3d(-4,-2,4);
        glVertex3d(-4,-2,-4);
        glVertex3d(-4,2,-4);

        glVertex3d(-4,2,-4);
        glVertex3d(-4,-2,-4);
        glVertex3d(-4,-2,-3.9);
        glVertex3d(-4,2,-3.9);

        //bottom base of leg 1
        glVertex3d(-4,-2,-4);
        glVertex3d(-4,-2,4);
        glVertex3d(-4,-2,3.9);
        glVertex3d(-4,-2,-3.9);



    glEnd();

}

void ownTranslatef(GLfloat dx, GLfloat dy, GLfloat dz){
    GLfloat m[16];

    m[0] = 1;  m[4]=0;  m[8]=0;  m[12] = dx;
    m[1] = 0;  m[5]=1;  m[9]=0;  m[13] = dy;
    m[2] = 0;  m[6]=0;  m[10]=1; m[14] = dz;
    m[3] = 0;  m[7]=0;  m[11]=0; m[15] = 1;

    glMatrixMode(GL_MODELVIEW);
    glMultMatrixf(m);
}

void ownRotatef(GLfloat theta){
    GLfloat m[16];

    theta = theta*3.1416/180;

    m[0] = cos(theta);  m[4]=-sin(theta);  m[8]=0;  m[12] = 0;
    m[1] = sin(theta);  m[5]=cos(theta);  m[9]=0;  m[13] = 0;
    m[2] = 0;  m[6]=0;  m[10]=1; m[14] = 0;
    m[3] = 0;  m[7]=0;  m[11]=0; m[15] = 1;

    glMatrixMode(GL_MODELVIEW);
    glMultMatrixf(m);
}


void ownScalef(GLfloat sx, GLfloat sy, GLfloat sz){
    GLfloat m[16];

    m[0] = sx;  m[4]=0;  m[8]=0;  m[12] = 0;
    m[1] = 0;  m[5]=sy;  m[9]=0;  m[13] = 0;
    m[2] = 0;  m[6]=0;  m[10]=sz; m[14] = 0;
    m[3] = 0;  m[7]=0;  m[11]=0;  m[15] = 1;

    glMatrixMode(GL_MODELVIEW);
    glMultMatrixf(m);
}


static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);


    //building the pyramid
    glPushMatrix();
        glTranslated(-0,-0.2,-10);
        //glRotated(60,0,1,1);
        glRotated(a,0,1,1);

        ownRotatef(theta);
        ownTranslatef(dx, dy, dz);
        ownScalef(sx, sy, sz);
        nationalMemorialLoop();
    glPopMatrix();

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;

        case 'x':
            dx+=.1;
            break;

        case 'y':
            dy+=.1;
            break;

        case 'z':
            dz+=.1;
            break;

        case 'X':
            dx-=.1;
            break;

        case 'Y':
            dy-=.1;
            break;

        case 'Z':
            dx-=.1;
            break;

        case 'r':
            theta+=5;
            break;

        case 'R':
            theta-=5;
            break;

        case 'a':
            sx+=.1;
            break;

        case 's':
            sy+=.1;
            break;

        case 'd':
            sz+=.1;
            break;

        case 'A':
            sx-=.1;
            break;

        case 'S':
            sy-=.1;
            break;

        case 'D':
            sz-=.1;
            break;
    }

    glutPostRedisplay();
}


static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1200,700);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    //glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
