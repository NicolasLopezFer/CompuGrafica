/* -------------------------------------------------------------------------
 * @brief Simulation of a simple solar system
 * @author Leonardo Fl�rez-Valencia (florez-l@javeriana.edu.co)
 * -------------------------------------------------------------------------
 */
 //MAC
 #include <GLUT/glut.h>
 #include <OpenGL/gl.h>
 //g++ -o pruebaApp2 BrazoRobotico.cxx   -framework OpenGL -framework GLUT

//#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <cmath>

#include "Camera.h"
#include "SpatialObject.h"


using namespace std;
int rotacion = 0;
string archivo;
bool validar = false;
int numeroExtremidades = 0;
int vectorX = 0;
int vectorY = 0;
int vectorZ = 0;
int coordActX = 0;
int coordActY = 0;
int coordActZ = 0;
int acumlong = 0;
int movX = 0, movY = 0, movZ = 0;
int numExt = 1;
int movimiento = 1000;
int pelotaY = 0, pelotaX = 30, pelotaZ = 0;
int inicioPelota = 100;
bool arriva = false;


// -------------------------------------------------------------------------
Camera myCamera;
SpatialObject* myStar = nullptr;

// -------------------------------------------------------------------------
SpatialObject* initWorld( int argc, char* argv[] );
void destroyWorld( SpatialObject* star );

// -------------------------------------------------------------------------
void displayCbk( );
void idleCbk( );
void resizeCbk( int w, int h );
void keyboardCbk( unsigned char key, int x, int y );
void SpecialKeyboardCbk(int key, int x, int y );
void mouseClickCbk( int button, int state, int x, int y );
void mouseMoveCbk( int x, int y );


// -------------------------------------------------------------------------
int main( int argc, char* argv[] )
{
  // Init OpenGL context
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
  glutInitWindowPosition( 50, 50 );
  glutInitWindowSize( 1024, 768 );
  glutCreateWindow( "A solar system..." );
  archivo = argv[1];

  // Init world
  try
  {
    //myStar = initWorld( argc, argv );

    glutDisplayFunc( displayCbk );
    glutIdleFunc( idleCbk );
    glutReshapeFunc( resizeCbk );
    glutKeyboardFunc( keyboardCbk );
    glutSpecialFunc(SpecialKeyboardCbk);
    glutMouseFunc( mouseClickCbk );
    glutMotionFunc( mouseMoveCbk );
    glutMainLoop( );

    destroyWorld( myStar );
    return( 0 );
  }
  catch( std::exception& err )
  {
    std::cerr << err.what( ) << std::endl;
    return( 1 );
  } // end if
}

// -------------------------------------------------------------------------
SpatialObject* initWorld( int argc, char* argv[] )
{
  // Initialize camera

  // OpenGL initialization
  glClearColor( 0, 0, 0, 0 );

  // Check input arguments
  if( argc < 2 )
    throw std::runtime_error(
      std::string( "Usage: " ) + argv[ 0 ] + " world_description"
      );

  // Read world and keep the star of this solar system
  return( new SpatialObject( argv[ 1 ] ) );
}

// -------------------------------------------------------------------------
void destroyWorld( SpatialObject* star )
{
  if( star != nullptr )
    delete star;
}

// -------------------------------------------------------------------------
void displayCbk( )
{
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
  glMatrixMode( GL_MODELVIEW );

  myCamera.setFOV( 45 );
  myCamera.setPlanes( 1e-2, 100000 );

  glLoadIdentity( );


  // Prepare model matrix
  myCamera.loadCameraMatrix( );

  glPushMatrix(); //Se guarda la matrix de camara
  glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(100,0,0);

    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(0,100,0);

    glColor3f(0,0,1);
    glVertex3f(0,0,0);
    glVertex3f(0,0,100);

  glEnd();
  glColor3f(1,1,0);
  glTranslatef(0,-10,0);
  glScalef(100,20,100);
  glutWireCube(1.0);
  glPopMatrix(); //Se saca la matrix inicial

  if(validar == false){
    char texto[500];
    ifstream read;
    char * vector;
    int cont = 0;
    acumlong = 0;
    numExt = 0;
    read.open(archivo,ios::out);
    if(read.is_open()){
      while(!read.eof()){
        read.getline(texto, 500);
        vector = strtok(texto," ");
        numExt = numExt+1;
        if(cont == 0){
          cont = cont + 1;
          numeroExtremidades = atoi(vector);
        }else{
            while(vector != NULL){
              vectorX = atoi(vector);
              vector = strtok(NULL," ");
              vectorY = atoi(vector);
              vector = strtok(NULL," ");
              vectorZ = atoi(vector);
              vector = strtok(NULL," ");

              int longitud = sqrt(((vectorX)*(vectorX))+((vectorY)*(vectorY))+((vectorZ)*(vectorZ)));
              acumlong = acumlong + longitud;
            }
            //LECTURA DEL BRAZO
        }

      }
    } else {
      cout << "¡Error! El archivo no pudo ser abierto." << endl;
    }
    read.close();


    //validar = true;
  }

  glPushMatrix();
  glColor3f(0,1,1);
  glTranslatef(pelotaX,pelotaY,pelotaZ);
  glutSolidSphere(acumlong*0.05,10,10);
  glPopMatrix();

  glutSwapBuffers( );

}

// -------------------------------------------------------------------------
void idleCbk( )
{

  if (inicioPelota != 0){
    if(pelotaY == 1){
      inicioPelota = inicioPelota*0.8;
      arriva = true;
    }

    if(pelotaY >= 1){
      if(arriva == false){
        pelotaY = pelotaY - 1;
      }else{
        if(pelotaY!= 0){
          pelotaY = pelotaY + 1;
        }
      }

      if(pelotaY == inicioPelota){
        arriva = false;
      }

      if(pelotaY == 1 && inicioPelota < 1){
        inicioPelota = 100;
        pelotaY == 0;
        arriva = false;
        cout << "Entra" << endl;
      }
    }
  }

  glutPostRedisplay( );
}

// -------------------------------------------------------------------------
void resizeCbk( int w, int h )
{
  glMatrixMode( GL_PROJECTION );
  glLoadIdentity( );
  myCamera.setWindow( w, h );
  myCamera.loadProjectionMatrix( );
}

void SpecialKeyboardCbk( int key, int x, int y ){

  switch( key )
  {
  case GLUT_KEY_UP:
  {
    myCamera.upward( 2 ) ;
    glutPostRedisplay( );
  }
    break;
  case GLUT_KEY_DOWN:
  {
    myCamera.upward( -2 ) ;
    glutPostRedisplay( );
  }
    break;
  case GLUT_KEY_LEFT:
  {
    myCamera.strafe( -2 ) ;
    glutPostRedisplay( );
  }
    break;
  case GLUT_KEY_RIGHT:
  {
    myCamera.strafe( 2 ) ;
    glutPostRedisplay( );
  }
    break;
  default:
    break;
  } // end switch
}

// -------------------------------------------------------------------------
void keyboardCbk( unsigned char key, int x, int y )
{
  switch( key )
  {
    case '1':
    {

    }
    break;

    case '2':
    {

    }
    break;

    case '3':
    {

    }
    break;

    case '4':
    {

    }
    break;

    case '5':
    {

    }
    break;

    case '6':
    {

    }
    break;

    case '7':
    {

    }
    break;

    case '8':
    {

    }
    break;

    case '9':
    {

    }
    break;

    case 'y':
    {

    }
    break;

    case 'Y':
    {

    }
    break;

    case 'x':
    {

    }
    break;

    case 'X':
    {

    }
    break;

    case 'z':
    {

    }
    break;

    case 'Z':
    {

    }
    break;

    case '+':
    {

    }
      break;
    case '-':
    {

    }
      break;

    case 'q':
    {
      myCamera.forward( 2 ) ;
      glutPostRedisplay( );
    }
      break;
    case 'e':
    {
      myCamera.forward( -2 ) ;
      glutPostRedisplay( );
    }
      break;

    case 'p': case 'P':
    {
      pelotaY = inicioPelota;
    }
      break;

    case 27: // ESC
        std::exit( 0 );
      break;

    default:
    break;
  } // end switch
}

void mouseClickCbk( int button, int state, int x, int y )
{
  if( state == GLUT_DOWN )
    myCamera.setReference( x, y );
  else
    myCamera.setReference( 0, 0 );
}

// -------------------------------------------------------------------------
void mouseMoveCbk( int x, int y )
{
  int dx, dy;
  myCamera.getReference( dx, dy, x, y );
  myCamera.setReference( x, y );

  // Apply rotations
  if( dx > 0 )      myCamera.rotY( -0.5 );
  else if( dx < 0 ) myCamera.rotY( 0.5 );
  if( dy > 0 )      myCamera.rotX( 0.5 );
  else if( dy < 0 ) myCamera.rotX( -0.5 );

  // Redraw
  glutPostRedisplay( );
}

// eof - SolarSystem.cxx
