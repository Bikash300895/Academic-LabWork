#include <GL/glut.h>
#include <math.h>
/*  Create checkerboard texture  */
#define checkImageWidth 64
#define checkImageHeight 64
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];
static GLuint texName;
void makeCheckImage(void)
{
   int i, j, c;

   for (i = 0; i < checkImageHeight; i++) {
      for (j = 0; j < checkImageWidth; j++) {
		 c = ((((i&0x8)==0)^((j&0x8))==0))*255;
         checkImage[i][j][0] = (GLubyte) c;
         checkImage[i][j][1] = (GLubyte) c;
         checkImage[i][j][2] = (GLubyte) c;
         checkImage[i][j][3] = (GLubyte) 255;
      }
   }
}
void init(void)
{
	// all the texture-mapping initialization occurs in this routine
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   glEnable(GL_DEPTH_TEST);

   makeCheckImage();
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
   //This function controls how pixels are stored with glReadPixels and read for glDrawPixels, glTexImage1D, and glTexImage2D. It does not affect the operation of glCopyPixels.
   //1: set the parameter
   //2: set the value of the parameter

   glGenTextures(1, &texName);
   //This function fills an array with the requested number of texture objects.
   //Texture object names are unsigned integers, parameters are:
   /* 1:The number of texture object names to generate.
      2:An array containing the list of newly generated texture object names.
   */
   glBindTexture(GL_TEXTURE_2D, texName);
   //This function enables you to create or switch to a named texture state.
   //On first use, this function creates a new texture state identified by the texture name,
   //which is an unsigned integer.
   /* 1:The texture target to bind to. It must be GL_TEXTURE_1D, GL_TEXTURE_2D, or GL_TEXTURE_3D.
      2:The name or handle of the texture object.
   */
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   //This function sets several texture mapping parameters.
   //These parameters are bound to the current texture state that can be made current with glBindTexture.
   /*  1:The texture target for which this parameter applies. Must be one of GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_3D, or GL_TEXTURE_CUBE_MAP.
       2:The texturing parameter to set
	   3:Value of the parameter specified by parameter 2
   */


   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,checkImage);
   //This function defines a one-, two-, or three-dimensional texture image.
   //The image data is subject to modes defined with glPixelMap, glPixelStore, and glPixelTransfer.
   /*  1:The texture target being specified. Must be GL_TEXTURE_2D or GL_PROXY_TEXTURE_2D for glTexImage2D
	   2:The level of detail. Usually, 0 unless mipmapping"is used.
	   3:The internal format of the image data.
	   4:The width of the one-, two-, or three-dimensional texture image. This must be a power of 2 but may include a border.
	   5:The height of the two- or three-dimensional texture image. This must be a power of 2 but may include a border.
	   6:The depth of a three-dimensional texture image. This must be a power of 2 but may include a border.
	   7:The format of the pixel data.
	   8:The data type of each texel value.
	   9:The pixel data.
   */
}
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_TEXTURE_2D);
   gluLookAt(0,0,1,0,0,0,0,1,0);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
   //These functions set texture mapping environment parameters.
   //The texture environment is set per texture unit
   /* 1:The texture environment to define. It must be GL_TEXTURE_ENV or GL_TEXTURE_FILTER_CONTROL.
      2:When the target is GL_TEXTURE_ENV, the parameter name may be GL_TEXTURE_ENV_MODE, GL_TEXTURE_ENV_COLOR, GL_COMBINE_RGB, or GL_COMBINE_ALPHA.
	  3:The parameter value. It must be one of the values above (GL_REPLACE, GL_DECAL, GL_MODULATE, GL_BLEND, GL_ADD, or GL_COMBINE),
   */
   glBegin(GL_QUADS);
   glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, -1.0, 0.0);
   glTexCoord2f(0.0, 3.0); glVertex3f(-2.0, 1.0, 0.0);
   glTexCoord2f(3.0, 3.0); glVertex3f(0.0, 1.0, 0.0);
   glTexCoord2f(3.0, 0.0); glVertex3f(0.0, -1.0, 0.0);

   glTexCoord2f(0.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
   glTexCoord2f(0.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
   glTexCoord2f(1.0, 1.0); glVertex3f(2.41421, 1.0, -1.41421);
   glTexCoord2f(1.0, 0.0); glVertex3f(2.41421, -1.0, -1.41421);
   glEnd();
   glFlush();
   glDisable(GL_TEXTURE_2D);
}
void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0, 0.0, -3.6);
}
void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(1);
         break;
      default:
         break;
   }
}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(250, 250);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
