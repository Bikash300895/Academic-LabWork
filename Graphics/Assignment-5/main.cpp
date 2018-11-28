#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

static int slices = 16;
static int stacks = 16;
float point_x[]={0.79, 0.8, 0.65, 0.60, 0.75, 0.82, 0.90, 0.99, 1.08, 1.15, 1.2};
float point_y[]={0.0, 0.4, 0.8, 1.2, 1.6, 2.0, 2.4, 2.8, 3.2, 3.6, 4.0};

float point_x1[]={0.28, 0.9, 1.2, 1.3, 1.4, 1.5, 1.5, 1.4, 1.3, 1.05, 0.8};
float point_y1[]={0.8, 1.1, 1.4, 1.7, 2.0, 2.3, 2.6, 2.9, 3.2, 3.4, 3.6};

int number_of_points = 11;

/* GLUT callback Handlers */

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

void botol()
{
    // Loop for 9 rounds
    for(int i=0; i<number_of_points-1; i++){
        // Loop for 360 degree
        int total_point=20+1;
        int degre = int(360/(total_point-1));

        float round_x_points_1[total_point];
        float round_z_points_1[total_point];
        float round_x_points_2[total_point];
        float round_z_points_2[total_point];

        for(int d=0; d<total_point; d++){
            //storage for 20 x and z points
            round_x_points_1[d] = point_x[i] * cos(d*degre*3.1416/180);
            round_x_points_2[d] = point_x[i+1] * cos(d*degre*3.1416/180);

            round_z_points_1[d] = point_x[i] * sin(d*degre*3.1416/180);
            round_z_points_2[d] = point_x[i+1] * sin(d*degre*3.1416/180);


        }

        glBegin(GL_QUAD_STRIP);
            for(int d=0; d<total_point; d++){
                glVertex3d(round_x_points_2[d], point_y[i+1], round_z_points_2[d]);
                glVertex3d(round_x_points_1[d], point_y[i], round_z_points_1[d]);
            }
        glEnd();

    }
}


void handle()
{
    float r = 0.25;
    // Loop for 9 rounds
    for(int i=0; i<number_of_points-1; i++){
        // Loop for 360 degree
        int total_point=20+1;
        int degre = int(360/(total_point-1));

        float round_x_points_1[total_point];
        float round_z_points_1[total_point];
        float round_x_points_2[total_point];
        float round_z_points_2[total_point];

        for(int d=0; d<total_point; d++){
            //storage for 20 x and z points
            round_x_points_1[d] = point_x1[i] + ( r * cos(d*degre*3.1416/180));
            round_x_points_2[d] = point_x1[i+1] + (r* cos(d*degre*3.1416/180));

            round_z_points_1[d] = point_x1[i] + (r * sin(d*degre*3.1416/180));
            round_z_points_2[d] = point_x1[i+1] + (r* sin(d*degre*3.1416/180));


        }

        glBegin(GL_QUAD_STRIP);
            for(int d=0; d<total_point; d++){
                glVertex3d(round_x_points_2[d], point_y1[i+1], round_z_points_2[d]);
                glVertex3d(round_x_points_1[d], point_y1[i], round_z_points_1[d]);
            }
        glEnd();

    }
}

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);


    glPushMatrix();
        glTranslated(0,-1.9,-8);
        glRotated(30,1,0,0);
        glRotated(a,0,1,0);
        botol();
        handle();
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
    glutInitWindowSize(640,480);
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

    //glPolygonMode(GL_FRONT,GL_LINE);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

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
