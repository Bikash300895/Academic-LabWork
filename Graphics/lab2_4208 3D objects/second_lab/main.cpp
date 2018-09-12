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
#include<math.h>
#endif

#include <stdlib.h>


GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0;
GLboolean bRotate = false, uRotate = false;

static GLfloat v_pyramid[5][3] = {
    {0.0, 0.0, 0.0}, //point index 0
    {0.0, 0.0, 2.0}, //point index 1
    {2.0, 0.0, 2.0}, //point index 2
    {2.0, 0.0, 0.0}, //point index 3
    {1.0, 4.0, 1.0} //point index 4
};

static GLubyte p_Indices[4][3] = {
    {4, 1, 2}, // indices for drawing the triangle plane 1
    {4, 2, 3}, // indices for drawing the triangle plane 2
    {4, 3, 0}, // indices for drawing the triangle plane 3
    {4, 0, 1} // indices for drawing the triangle plane 4
};

static GLubyte quadIndices[1][4] ={
    {0, 3, 2, 1} };
static GLfloat colors[5][3] = {
    {0.0, 0.0, 1.0}, //color for point index 0
    {0.5, 0.0, 1.0}, //color for point index 1
    {0.0, 1.0, 0.0}, //color for point index 2
    {0.0, 1.0, 1.0}, //color for point index 3
    {0.8, 0.0, 0.0} //color for point index 4
};


void myKeyboardFunc( unsigned char key, int x, int y )
{
	switch ( key )
	{
		case 's':
		case 'S':
			bRotate = !bRotate;
			uRotate = false;
			axis_x=0.0;
			axis_y=1.0;
			break;

		case 'r':
		case 'R':
			uRotate = !uRotate;
			bRotate = false;
			axis_x=1.0;
			axis_y=0.0;
			break;

		case 27:	// Escape key
			exit(1);
	}
}


void animate()
{
	if (bRotate == true)
	{
		theta += 0.2;
		if(theta > 360.0)
			theta -= 360.0*floor(theta/360.0);
	}

	if (uRotate == true)
	{
		alpha += 0.2;
		if(alpha > 360.0)
			alpha -= 360.0*floor(alpha/360.0);
	}
	glutPostRedisplay();

}



static void getNormal3p
(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat
y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3){
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;
    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;
    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;
    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;
    glNormal3f(Nx,Ny,Nz);
}
void drawpyramid()
{
    glColor3f(0,0,1);
    glBegin(GL_TRIANGLES);
    for (GLint i = 0; i <4; i++) {
        getNormal3p(v_pyramid[p_Indices[i][0]][0],
        v_pyramid[p_Indices[i][0]][1], v_pyramid[p_Indices[i][0]][2],
        v_pyramid[p_Indices[i][1]][0], v_pyramid[p_Indices[i][1]][1],
        v_pyramid[p_Indices[i][1]][2], v_pyramid[p_Indices[i][2]][0],
        v_pyramid[p_Indices[i][2]][1], v_pyramid[p_Indices[i][2]][2]);
        glVertex3fv(&v_pyramid[p_Indices[i][0]][0]);
        glVertex3fv(&v_pyramid[p_Indices[i][1]][0]);
        glVertex3fv(&v_pyramid[p_Indices[i][2]][0]);
    }
    glEnd();

    glBegin(GL_QUADS);
    for (GLint i = 0; i <1; i++) {
        getNormal3p(v_pyramid[quadIndices[i][0]][0],
        v_pyramid[quadIndices[i][0]][1], v_pyramid[quadIndices[i][0]][2],
        v_pyramid[quadIndices[i][1]][0], v_pyramid[quadIndices[i][1]][1],
        v_pyramid[quadIndices[i][1]][2], v_pyramid[quadIndices[i][2]][0],
        v_pyramid[quadIndices[i][2]][1], v_pyramid[quadIndices[i][2]][2]);
        glVertex3fv(&v_pyramid[quadIndices[i][0]][0]);
        glVertex3fv(&v_pyramid[quadIndices[i][1]][0]);
        glVertex3fv(&v_pyramid[quadIndices[i][2]][0]);
        glVertex3fv(&v_pyramid[quadIndices[i][3]][0]);
    }
    glEnd();

}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
	//glFrustum(-5,5,-5,5, 4, 50);
    gluPerspective(60,1,5,100);
    //glOrtho(-5,5,-5,5, 4, 50);

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	gluLookAt(2,3,10, 2,0,0, 0,1,0);
    glViewport(0,0,400,400);
	glPushMatrix();
        glRotatef( alpha,axis_x , axis_y, 0.0 );
		glRotatef( theta, axis_x, axis_y, 0.0 );
	    drawpyramid();

    glPopMatrix();


    glPushMatrix();
        glTranslatef(3,0,2);
        glColor3f(1,0,1);

        //glutSolidSphere(2,30,10);
    glPopMatrix();




	glFlush();
	glutSwapBuffers();
}


int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("Pyramid-Demo");

	glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);

    glutKeyboardFunc(myKeyboardFunc);
	glutDisplayFunc(display);

    glutIdleFunc(animate);
	glutMainLoop();

	return 0;
}
