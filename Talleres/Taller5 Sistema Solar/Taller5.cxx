//MAC
//#include <GLUT/glut.h>
//#include <OpenGL/gl.h>
//g++ -o pruebaApp2 Taller5.cxx   -framework OpenGL -framework GLUT


#include <GL/glut.h>
#include <cmath>
#include <iostream>

#define _PI      3.14159265359
#define _2PI     6.28318530718
#define _SQRT3   1.73205080757
#define _SQRT3_2 0.86602540378
#define _SQRT3_3 0.57735026919
#define _SQRT3_4 0.43301270189

int giroSol = 0;

int giroPlaneta1 = 0;
int giroPlaneta2 = 0;
int giroPlaneta3 = 0;
int giroPlaneta4 = 0;

int giroLuna1 = 0;
int giroLuna2 = 0;
int giroLuna3 = 0;

int refreshMills = 15;

// -------------------------------------------------------------------------
void DrawUnitaryDiamond(){

  float colors[ 8 ][ 3 ] =
  {
    { 1, 0, 0 },
    { 0, 1, 0 },
    { 0, 0, 1 },
    { 1, 0, 1 },
    { 1, 1, 1 },
    { 1, 1, 0 },
    { 0.5, 0.5, 0.5 },
    { 1, 1, 1 }
  };

  float points[ 6 ][ 3 ] =
  {
    { 1, 0, 1 },
    { 1, 0, -1 },
    { 0, 1, 0 },
    { -1, 0, -1 },
    { -1, 0, 1 },
    { 0, -1, 0 }
  };

  unsigned int faces[8][3] =
  {
    {0,1,2},
    {1,3,2},
    {3,4,2},
    {4,0,2},

    {3,5,4},
    {4,5,0},
    {0,5,1},
    {1,5,3}
  };

  for( unsigned int i = 0; i < 8; ++i )
  {
    glBegin( GL_POLYGON );
    {
      for( unsigned int j = 0; j < 3; ++j )
      {
        glVertex3fv( points[ faces[ i ][ j ] ] );
      }
    }
    glEnd( );
  }
}

//LINEAS DEL SOL

void DrawDiamondLines(){

  float colors[ 8 ][ 3 ] =
  {
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 }
  };

  float points[ 6 ][ 3 ] =
  {
    { 1, 0, 1 },
    { 1, 0, -1 },
    { 0, 1, 0 },
    { -1, 0, -1 },
    { -1, 0, 1 },
    { 0, -1, 0 }
  };

  unsigned int faces[8][3] =
  {
    {0,1,2},
    {1,3,2},
    {3,4,2},
    {4,0,2},

    {3,5,4},
    {4,5,0},
    {0,5,1},
    {1,5,3}
  };

  for( unsigned int i = 0; i < 8; ++i )
  {
    glBegin( GL_LINE_LOOP);
    {
      for( unsigned int j = 0; j < 3; ++j )
      {
        glVertex3fv( points[ faces[ i ][ j ] ] );
      } // end for
    }
    glEnd( );
  } // end for
}
// FIN SOL -------------//


// PLANETAS --------------//

void DrawUnitaryCube( )
{
  float colors[ 8 ][ 3 ] =
  {
    { 1, 0, 0 },
    { 0, 1, 0 },
    { 0, 0, 1 },
    { 0, 1, 1 },
    { 1, 0, 1 },
    { 1, 1, 0 },
    { 0.5, 0.5, 0.5 },
    { 1, 1, 1 }
  };

  float points[ 8 ][ 3 ] =
  {
    { 0.5, -0.5, 0.5 },
    { 0.5, -0.5, -0.5 },
    { -0.5, -0.5, -0.5 },
    { -0.5, -0.5, 0.5 },
    { 0.5, 0.5, 0.5 },
    { 0.5, 0.5, -0.5 },
    { -0.5, 0.5, -0.5 },
    { -0.5, 0.5, 0.5 }
  };

  unsigned int faces[ 6 ][ 4 ] =
  {
    { 0, 3, 2, 1 },
    { 0, 4, 7, 3 },
    { 0, 1, 5, 4 },
    { 1, 2, 6, 5 },
    { 3, 7, 6, 2 },
    { 4, 5, 6, 7 }
  };

  for( unsigned int i = 0; i < 6; ++i )
  {
    glBegin( GL_POLYGON );
    {
      for( unsigned int j = 0; j < 4; ++j )
      {
        glVertex3fv( points[ faces[ i ][ j ] ] );
      } // end for
    }
    glEnd( );
  } // end for
}

//Lineas PLANETAS
void DrawUnitaryCubeLines( )
{
  float colors[ 8 ][ 3 ] =
  {
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0},
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 }
  };

  float points[ 8 ][ 3 ] =
  {
    { 0.5, -0.5, 0.5 },
    { 0.5, -0.5, -0.5 },
    { -0.5, -0.5, -0.5 },
    { -0.5, -0.5, 0.5 },
    { 0.5, 0.5, 0.5 },
    { 0.5, 0.5, -0.5 },
    { -0.5, 0.5, -0.5 },
    { -0.5, 0.5, 0.5 }
  };

  unsigned int faces[ 6 ][ 4 ] =
  {
    { 0, 3, 2, 1 },
    { 0, 4, 7, 3 },
    { 0, 1, 5, 4 },
    { 1, 2, 6, 5 },
    { 3, 7, 6, 2 },
    { 4, 5, 6, 7 }
  };

  for( unsigned int i = 0; i < 6; ++i )
  {
    glBegin( GL_LINE_LOOP);
    {
      for( unsigned int j = 0; j < 4; ++j )
      {
        glVertex3fv( points[ faces[ i ][ j ] ] );
      } // end for
    }
    glEnd( );
  } // end for
}

// FIN PLANETAS -----------

void DrawUnitaryPyramid( )
{
  float colors[ 8 ][ 3 ] =
  {
    { 1, 0, 0 },
    { 0, 1, 0 },
    { 0, 0, 1 },
    { 0, 1, 1 },
    { 1, 0, 1 },
    { 1, 1, 0 },
    { 0.5, 0.5, 0.5 },
    { 1, 1, 1 }
  };

  float points[ 5 ][ 3 ] =
  {
    { -0.5, -0.5, 0.5 },
    { 0.5, -0.5, 0 },
    { -0.5, -0.5, -0.5 },
    { 0, 0.5, 0 }
  };

  unsigned int faces[ 4 ][ 3 ] =
  {
    { 0, 1, 3 },
    { 1, 2, 3 },
    { 2, 0, 3 },
    { 1, 0, 2 }
  };

  for( unsigned int i = 0; i < 4; ++i )
  {
    glBegin( GL_POLYGON );
    {
      for( unsigned int j = 0; j < 3; ++j )
      {
        glVertex3fv( points[ faces[ i ][ j ] ] );
      } // end for
    }
    glEnd( );
  } // end for
}

void DrawUnitaryPyramidLines( )
{
  float colors[ 8 ][ 3 ] =
  {
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 }
  };

  float points[ 5 ][ 3 ] =
  {
    { -0.5, -0.5, 0.5 },
    { 0.5, -0.5, 0 },
    { -0.5, -0.5, -0.5 },
    { 0, 0.5, 0 }
  };

  unsigned int faces[ 4 ][ 3 ] =
  {
    { 0, 1, 3 },
    { 1, 2, 3 },
    { 2, 0, 3 },
    { 1, 0, 2 }
  };

  for( unsigned int i = 0; i < 4; ++i )
  {
    glBegin( GL_LINE_LOOP );
    {
      for( unsigned int j = 0; j < 3; ++j )
      {
        glVertex3fv( points[ faces[ i ][ j ] ] );
      } // end for
    }
    glEnd( );
  } // end for
}

//ORBITAS ----------


//FIN ORBITAS

// -------------------------------------------------------------------------
void Init( )
{
  glClearColor( 1, 1, 1, 1 );
}

// -------------------------------------------------------------------------
void ResizeCbk( int width, int height )
{
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  glViewport( 0, 0, width, height );

  // Ortho
  //glOrtho( -2, 2, -2, 2, -2, 5 );

  // Prespective
  gluPerspective( 45, float( width ) / float( height ), 0.01, 2000 );
}

//--------------------------

void DrawCircle( GLenum mode, unsigned int samples )
{
  glBegin( mode );
  for( unsigned int i = 0; i < samples; ++i )
  {
    float t = _2PI * float( i ) / float( samples );
    glVertex3f(std::cos( t ), std::sin( t ),0);
  } // end if
  glEnd( );
}

// -------------------------------------------------------------------------
void DisplayCbk( )
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glMatrixMode( GL_MODELVIEW );

  // Camara
  glLoadIdentity( );

  gluLookAt(200, 0,0, 0, 0, 0, 0, 1, 0 );

  // Sol
  glPushMatrix( );
  glScalef(10,20,10);
  //glRotatef(giroSol,0,1,0);
  glColor3f(1,1,0);
  DrawUnitaryDiamond( );
  // Lineas Sol
  glPopMatrix( );
  glPushMatrix( );
  glScalef(10,20,10);
  //glRotatef(giroSol,0,1,0);
  glColor3f(0,0,0);
  DrawDiamondLines( );

  //Planeta 1
  glPopMatrix();
  glPushMatrix();
  glTranslatef(30,30,-30);
  glRotatef(70,0,1,1);
  //glRotatef(giroPlaneta1,0,1,0);
  glScalef(7,7,7);
  glColor3f(1,0,0);
  DrawUnitaryDiamond();
  //Lineas Planeta 1
  glPopMatrix();
  glPushMatrix();
  glTranslatef(30,30,-30);
  glRotatef(70,0,1,1);
  //glRotatef(giroPlaneta1,0,1,0);
  glScalef(7,7,7);
  glColor3f(0,0,0);
  DrawDiamondLines();
  //Orbita Planeta 1
  glPopMatrix();
  glPushMatrix();
  glRotatef(135,1,0,0);
  glScalef(52,52,52);
  DrawCircle( GL_LINE_LOOP, 100 );

  //Luna 1 Planeta 1
  glPopMatrix();
  glPushMatrix();
  glTranslatef(30,30,-30);
  glTranslatef(10,10,-10);
  glRotatef(45,1,0,0);
  //glRotatef(giroLuna1,0,1,0);
  glScalef(4,4,4);
  glColor3f(0,1,1);
  DrawUnitaryPyramid();
  //Lineas Luna 1 Planeta 1
  glPopMatrix();
  glPushMatrix();
  glTranslatef(30,30,-30);
  glTranslatef(10,10,-10);
  glRotatef(45,1,0,0);
  //glRotatef(giroLuna1,0,1,0);
  glScalef(4,4,4);
  glColor3f(0,0,0);
  DrawUnitaryPyramidLines();
  //Orbita luna 1 Planeta 1
  glPopMatrix();
  glPushMatrix();
  glTranslatef(30,30,-30);
  glRotatef(41,0,1,0);
  glScalef(17,17,17);
  DrawCircle( GL_LINE_LOOP, 100 );

  //Luna 2 Planeta 1
  glPopMatrix();
  glPushMatrix();
  glTranslatef(30,30,-30);
  glTranslatef(0,-15,0);
  glRotatef(80,0,0,1);
  //glRotatef(giroLuna2,0,1,0);
  glScalef(4,4,4);
  glColor3f(1,0,1);
  DrawUnitaryPyramid();
  //Lineas Luna 2 Planeta 1
  glPopMatrix();
  glPushMatrix();
  glTranslatef(30,30,-30);
  glTranslatef(0,-15,0);
  glRotatef(80,0,0,1);
  //glRotatef(giroLuna2,0,1,0);
  glScalef(4,4,4);
  glColor3f(0,0,0);
  DrawUnitaryPyramidLines();
  //Orbita Luna 2 Planeta 1
  glPopMatrix();
  glPushMatrix();
  glTranslatef(30,30,-30);
  glRotatef(32,0,1,0);
  glScalef(15,15,15);
  DrawCircle( GL_LINE_LOOP, 100 );


  //Planeta 2
  glPopMatrix();
  glPushMatrix();
  glTranslatef(-20,-30,10);
  glRotatef(20,1,1,1);
  //glRotatef(giroPlaneta2,0,1,0);
  glScalef(10,10,10);
  glColor3f(1,0,0);
  DrawUnitaryPyramid();
  //Lineas Planeta 2
  glPopMatrix();
  glPushMatrix();
  glTranslatef(-20,-30,10);
  glRotatef(20,1,1,1);
  //glRotatef(giroPlaneta2,0,1,0);
  glScalef(10,10,10);
  glColor3f(0,0,0);
  DrawUnitaryPyramidLines();
  //Orbita Planeta 2
  glPopMatrix();
  glPushMatrix();
  glRotatef(29,0,1,0);
  glScalef(40,40,40);
  DrawCircle( GL_LINE_LOOP, 100 );

  //Planeta 3
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0,-40,50);
  //glRotatef(giroPlaneta3,0,1,0);
  glScalef(8,8,8);
  glColor3f(1,0,0);
  DrawUnitaryCube();
  //Lineas Planeta 3
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0,-40,50);
  //glRotatef(giroPlaneta3,0,1,0);
  glScalef(8,8,8);
  glColor3f(0,0,0);
  DrawUnitaryCubeLines();
  //Orbita Planeta 3
  glPopMatrix();
  glPushMatrix();
  glRotatef(127,1,0,0);
  glScalef(62,62,62);
  DrawCircle( GL_LINE_LOOP, 100 );

  //Luna 1 Planeta 3
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0,-40,50);
  glTranslatef(20,0,0);
  //glRotatef(giroLuna3,0,1,0);
  glScalef(4,4,4);
  glColor3f(0,1,0);
  DrawUnitaryPyramid();
  //Lineas Luna 1 Planeta 3
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0,-40,50);
  glTranslatef(20,0,0);
  //glRotatef(giroLuna3,0,1,0);
  glScalef(4,4,4);
  glColor3f(0,0,0);
  DrawUnitaryPyramidLines();
  //Orbita Luna 1 Planeta 3
  glPopMatrix( );
  glPushMatrix( );
  glTranslatef(0,-40,50);
  glRotatef(90,1,0,0);
  glScalef(20,20,20);
  DrawCircle(GL_LINE_LOOP,100);

  //Planeta 4
  glPopMatrix();
  glPushMatrix();
  glTranslatef(18,0,0);
  glRotatef(45,1,0,0);
  //glRotatef(giroPlaneta4,0,1,0);
  glScalef(5,5,5);
  glColor3f(1,0,0);
  DrawUnitaryPyramid();
  //Lineas Planeta 4
  glPopMatrix();
  glPushMatrix();
  glTranslatef(18,0,0);
  glRotatef(45,1,0,0);
  //glRotatef(giroPlaneta4,0,1,0);
  glScalef(5,5,5);
  glColor3f(0,0,0);
  DrawUnitaryPyramidLines();
  //Orbita Planeta 4
  glPopMatrix( );
  glPushMatrix( );
  glRotatef(90,1,0,0);
  glScalef(18,18,18);
  DrawCircle(GL_LINE_LOOP,100);

  // Finish
  glutSwapBuffers( );

  giroSol = giroSol + 1;

  giroPlaneta1 = giroPlaneta1 + 2;
  giroPlaneta2 = giroPlaneta2 + 1;
  giroPlaneta3 = giroPlaneta3 + 3;
  giroPlaneta4 = giroPlaneta4 + 1;

  giroLuna1 = giroLuna1 + 2;
  giroLuna2 = giroLuna2 + 2;
  giroLuna3 = giroLuna3 + 2;

}

void timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

// -------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
  glutInitWindowPosition( 50, 50 );
  glutInitWindowSize( 600, 600 );
  glutCreateWindow( "Sistema solar" );
  glutDisplayFunc( DisplayCbk );
  glutReshapeFunc( ResizeCbk );
  Init( );
  glutTimerFunc(0,timer,0);
  glutMainLoop( );

  return( 0 );
}

// eof
