#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RGBpixmap.cpp"
#include <math.h>

static int score = 0;

int randNum(int min, int max)
{
    return min + (rand() % static_cast<int>(max - min + 1));
}

static int n = 5;
static int slices = 16;
static int stacks = 16;
static int x_limit = 5;
static int y_limit = 6;
static float busket_x_position = 0.0;
static float eggs_x_position[5];
static float eggs_y_position[5];
static int egg_color[5];

RGBpixmap pix[6];

float point_x[]={0.0, 0.1,  0.2, 0.25, 0.3, 0.3, 0.25, 0.2,0.15, 0.1, 0};
float point_y[]={0.05, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, .95};
int number_of_points = 11;

void egg()
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

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for(int i=0; i<n; i++)
    {

        eggs_y_position[i]-=0.05;

        if(eggs_y_position[i]<0.0 ){

                if((eggs_x_position[i]-busket_x_position) <0.05){
                    if(egg_color[i]==5)
                    {
                        score+=1;
                    }
                    else
                    {
                        score-=1;
                    }
                    std::cout<<"Score: "<<score<<std::endl;
                }



            eggs_x_position[i] = randNum(-x_limit,x_limit);
            eggs_y_position[i] = randNum(4,7);
            egg_color[i] = randNum(4,5);
        }

        if(eggs_y_position[i]<-1.0)
        {

        }

    }


    for(int i=0; i<n; i++)
    {
        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D,egg_color[i]);
        glEnable(GL_TEXTURE_2D);

        glTranslated(eggs_x_position[i],eggs_y_position[i],-9);
        //glRotated(60,1,0,0);
        glRotated(a,0,1,0);
        //glutSolidSphere(0.5,slices,stacks);
        egg();

        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }



    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D,5);
    glEnable(GL_TEXTURE_2D);

    glTranslated(busket_x_position,0,-9);
    glRotated(a,0,0,1);
    glutSolidTorus(0.2,0.7,slices,stacks);

    glDisable(GL_TEXTURE_2D);
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

    case 's':
        busket_x_position+=0.3;
        break;

    case 'a':
        busket_x_position-=0.3;
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

void Init()
{
    glEnable(GL_TEXTURE_2D);


    pix[0].makeCheckImage();
    pix[0].setTexture(1);	// create texture int parameter as TextureName


    //pix[0].readBMPFile("teapot.bmp");
//	pix[0].setTexture(1);

    pix[1].readBMPFile("D:\\Projects\\opengl\\test\\teapot.bmp");
    pix[1].setTexture(2);

    pix[2].readBMPFile("D:\\Projects\\opengl\\test\\jack.bmp");
    pix[2].setTexture(4);

    pix[3].readBMPFile("D:\\Projects\\opengl\\test\\table.bmp");
    pix[3].setTexture(3);

    pix[4].readBMPFile("D:\\Projects\\opengl\\test\\wood.bmp");
    pix[4].setTexture(5);



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
    for(int i=0; i<n; i++)
    {
        eggs_x_position[i] = randNum(-x_limit,x_limit);
        eggs_y_position[i] = randNum(4,7);
        egg_color[i] = randNum(4,5);
        std::cout<<eggs_x_position[i]<<" "<<eggs_y_position[i]<<std::endl;
    }

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


    Init();
    glutMainLoop();

    return EXIT_SUCCESS;
}
