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
#include <string>
#include <chrono>

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
int acumVectorX = 0;
int acumVectorY = 0;
int acumVectorZ = 0;

int acumlong = 0;
int movX = 0, movY = 0, movZ = 0;
int numExt = 1;
int movimien = 1000;
float pelotaY = 0, pelotaX = 30, pelotaZ = 0;
double inicioPelota = 200;
bool arriva = false;

//Movimiento brazo
bool animacion = false;
float roteiting = 0;
float roteiting1 = 0;
float roteiting2 = 0;
float roteiting3 = 0;
float roteiting4 = 0;
float roteiting5 = 0;
float roteiting6 = 0;
float roteiting7 = 0;
float roteiting8 = 0;
float roteiting9 = 0;
float mActX = 0;
float mActY = 0;
float mActZ = 0;

std::chrono::time_point< std::chrono::high_resolution_clock > start;
std::chrono::time_point< std::chrono::high_resolution_clock > end;
double duration = 0;
std::chrono::time_point< std::chrono::high_resolution_clock > tiempoCaida;
std::chrono::time_point< std::chrono::high_resolution_clock > tiempoSubida;
double velocidad = 0;
double velocidadmoment=0;
double hMaxSubida = 0;
double tMax = 0;

bool agarrar = false;

float cambioColoX = 1;
float cambioColorY = 0.3;
float cambioColorZ = 0.3;
bool aumentodismi = false;
float gravedad;
float planeta;
bool correcto = false;


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
  glutCreateWindow( "Parcial Brazo" );
  archivo = argv[1];

  // Init world
  try
  {
    glEnable(GL_BLEND);
    myStar = initWorld( argc, argv );

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
  while(correcto == false){
    cout << "Seleccione el planeta en donde se encuentra: " << endl;
    cout << "1. Mercurio " << endl;
    cout << "2. Venus " << endl;
    cout << "3. Planeta Tierra " << endl;
    cout << "4. Marte " << endl;
    cout << "5. Jupiter " << endl;
    cout << "6. Saturno " << endl;
    cout << "7. Urano " << endl;
    cout << "8. Neptuno " << endl;
    cout << "9. Pluton " << endl;
    cout << "10. Planeta con una gravedad de 50m/s^2 " << endl;
    cin >> planeta;

    if(planeta == 1){
      gravedad = 3.7;
    }

    if(planeta == 2){
      gravedad = 8.87;
      correcto = true;
    }

    if(planeta == 3){
      gravedad = 9.8;
      correcto = true;
    }

    if(planeta == 4){
      gravedad = 3.7;
      correcto = true;
    }

    if(planeta == 5){
      gravedad = 24.7;
      correcto = true;
    }

    if(planeta == 6){
      gravedad = 10.44;
      correcto = true;
    }

    if(planeta == 7){
      gravedad = 8.87;
      correcto = true;
    }

    if(planeta == 8){
      gravedad = 11.15;
      correcto = true;
    }

    if(planeta == 9){
      gravedad = 0.62;
      correcto = true;
    }

    if(planeta == 10){
      gravedad = 50;
      correcto = true;
    }

    if(planeta > 10){
      cout << "No existe esa opcion " << endl;
      correcto = false;
    }

    if(planeta < 1){
      cout << "No existe esa opcion " << endl;
      correcto = false;
    }
  }

  // Initialize camera
  myCamera.setFOV( 45 );
  myCamera.setPlanes( 1e-2, 100000 );
  myCamera.move( Vector( 0, 0, 500 ) );
  myCamera.lookAt( Vector(0,0,0) );

  // OpenGL initialization
  glClearColor( 0, 0, 0, 0 );

  // Check input arguments
  if( argc < 2 )
    throw std::runtime_error(
      std::string( "Usage: " ) + argv[ 0 ] + " world_description"
      );

  ofstream file;

  file.open("archivo.txt", ios::out);
  string nombre = "archivo.txt";
  if(!file.fail()){



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


              file << "C" << " " << "1" << " " << "0" << " " << "0" << "\n";
              file << "X" << " " << to_string(vectorX) << "\n";
              file << "Y" << " " << to_string(vectorY) << "\n";
              file << "Z" << " " << to_string(vectorZ) << "\n";
              if(numExt != numeroExtremidades){
                file << "D" << " " <<"1" << "\n";
              }else{
                file << "D" << " " <<"0" << "\n";
              }
              file << "--" << "\n";
              int longitud = sqrt(((vectorX)*(vectorX))+((vectorY)*(vectorY))+((vectorZ)*(vectorZ)));
              acumlong = acumlong + longitud;
              acumVectorX = acumVectorX + vectorX;
              acumVectorY = acumVectorY + vectorX;
              acumVectorZ = acumVectorZ + vectorX;
            }
        }
        numExt = numExt + 1;
      }
    } else {
      cout << "¡Error! El archivo no pudo ser abierto." << endl;
    }
    read.close();



  }else{
    cout << "¡Error! El archivo no pudo ser creado." << endl;
  }
  file.close();


  // Read world and keep the star of this solar system
  return( new SpatialObject( nombre ));
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

  glLoadIdentity( );


  // Prepare model matrix
  myCamera.loadCameraMatrix( );

  //PATA
  glPushMatrix(); //Se guarda la matrix de camara
  glColor4f(0.46,0.33,0.28,1);
  glTranslatef(acumlong-30,-40,acumlong-30);
  glScalef(20,40,20);
  glRotatef(90,0,0,1);
  glutSolidCube(1.0);
  glPopMatrix(); //Se saca la matrix inicial

  glPushMatrix(); //Se guarda la matrix de camara
  glColor4f(0.46,0.33,0.28,1);
  glTranslatef(-acumlong+30,-40,-acumlong+30);
  glScalef(20,40,20);
  glRotatef(90,0,0,1);
  glutSolidCube(1.0);
  glPopMatrix(); //Se saca la matrix inicial

  glPushMatrix(); //Se guarda la matrix de camara
  glColor4f(0.46,0.33,0.28,1);
  glTranslatef(-acumlong+30,-40,acumlong-30);
  glScalef(20,40,20);
  glRotatef(90,0,0,1);
  glutSolidCube(1.0);
  glPopMatrix(); //Se saca la matrix inicial

  glPushMatrix(); //Se guarda la matrix de camara
  glColor4f(0.46,0.33,0.28,1);
  glTranslatef(acumlong-30,-40,-acumlong+30);
  glScalef(20,40,20);
  glRotatef(90,0,0,1);
  glutSolidCube(1.0);
  glPopMatrix(); //Se saca la matrix inicial

  //FIN PATA

  //MESA
  glPushMatrix(); //Se guarda la matrix de camara
  glColor4f(0.46,0.33,0.28,1);
  glTranslatef(0,-10,0);
  glScalef(acumlong*2,20,acumlong*2);
  glutSolidCube(1.0);
  glPopMatrix(); //Se saca la matrix inicial

  glPushMatrix(); //Se guarda la matrix de camara
  glColor4f(0,0,0,1);
  glTranslatef(0,-10,0);
  glScalef(acumlong*2,20,acumlong*2);
  glutWireCube(1.0);
  glPopMatrix(); //Se saca la matrix inicial
  //FIN MESA

  if(aumentodismi == false){
    cambioColoX = cambioColoX - 0.01;
    cambioColorY = cambioColorY + 0.01;
    if(cambioColoX < 0.3){
      aumentodismi = true;
    }
  }else{
    cambioColoX = cambioColoX + 0.01;
    cambioColorY = cambioColorY - 0.01;
    if(cambioColoX > 0.9){
      aumentodismi = false;
    }
  }


  myStar->drawInOpenGLContext(GL_POLYGON, agarrar);

  glPushMatrix();
  glColor3f(0,1,1);
  glTranslatef(acumlong*0.5,pelotaY,pelotaZ);
  glTranslatef(0,acumlong*0.05,0);
  glutSolidSphere(acumlong*0.05,10,10);

  glPopMatrix();

  glutSwapBuffers( );

}

// -------------------------------------------------------------------------
void idleCbk( )
{

  if(animacion == true){
    if(arriva==false){
      duration =(std::chrono::duration_cast< std::chrono::milliseconds >(
      std::chrono::high_resolution_clock::now( ) - start ).count( ));
      duration = duration / 1000;

      pelotaY = ( (inicioPelota) - ((0.5)*(gravedad*100)*( (duration)*(duration) )) );


      if(pelotaY <=1){
        velocidad = ( (gravedad*100)*(duration) );
        velocidad = velocidad * 0.8;

        pelotaY = 0;

        start = std::chrono::high_resolution_clock::now( );

        tMax = velocidad/(gravedad*100);

        inicioPelota = ( ( (velocidad)*(tMax) ) - ( (0.5)*(gravedad*100)*( (tMax)*(tMax) ) ) );

        start = std::chrono::high_resolution_clock::now( );
        arriva = true;
        cout << inicioPelota << endl;
        if(inicioPelota < 0.5){
          animacion = false;
        }

      }
    }else{
      duration =(std::chrono::duration_cast< std::chrono::milliseconds >(
      std::chrono::high_resolution_clock::now( ) - start ).count( ));
      duration = duration / 1000;

      pelotaY = ( (velocidad)*(duration) ) - ( (0.5)*(gravedad*100)*((duration)*(duration)) );

      if(duration>=tMax){
        pelotaY = inicioPelota;
        start = std::chrono::high_resolution_clock::now( );
        arriva = false;
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
    myCamera.upward( 5 ) ;
    glutPostRedisplay( );
  }
    break;
  case GLUT_KEY_DOWN:
  {
    myCamera.upward( -5 ) ;
    glutPostRedisplay( );
  }
    break;
  case GLUT_KEY_LEFT:
  {
    myCamera.strafe( -5 ) ;
    glutPostRedisplay( );
  }
    break;
  case GLUT_KEY_RIGHT:
  {
    myCamera.strafe( 5 ) ;
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
  float contador = 0;
  switch( key )
  {
    case '1':
    {
      movimien = 1;
      mActX = 0;
      mActY = 0;
      mActZ = 0;

    }
    break;

    case '2':
    {
      movimien = 2;
      mActX = 0;
      mActY = 0;
      mActZ = 0;

    }
    break;

    case '3':
    {
      movimien = 3;
      mActX = 0;
      mActY = 0;
      mActZ = 0;

    }
    break;

    case '4':
    {
      movimien = 4;
      mActX = 0;
      mActY = 0;
      mActZ = 0;

    }
    break;

    case '5':
    {
      movimien = 5;
      mActX = 0;
      mActY = 0;
      mActZ = 0;

    }
    break;

    case '6':
    {
      movimien = 6;
      mActX = 0;
      mActY = 0;
      mActZ = 0;

    }
    break;

    case '7':
    {
      movimien = 7;
      mActX = 0;
      mActY = 0;
      mActZ = 0;

    }
    break;

    case '8':
    {
      movimien = 8;
      mActX = 0;
      mActY = 0;
      mActZ = 0;

    }
    break;

    case '9':
    {
      movimien = 9;
      mActX = 0;
      mActY = 0;
      mActZ = 0;

    }
    break;

    case 'y':
    {
      mActX = 0;
      mActY = 1;
      mActZ = 0;

    }
    break;

    case 'Y':
    {
      mActX = 0;
      mActY = 1;
      mActZ = 0;
    }
    break;

    case 'x':
    {
      mActX = 1;
      mActY = 0;
      mActZ = 0;

    }
    break;

    case 'X':
    {
      mActX = 1;
      mActY = 0;
      mActZ = 0;

    }
    break;

    case 'z':
    {
      mActX = 0;
      mActY = 0;
      mActZ = 1;

    }
    break;

    case 'Z':
    {
      mActX = 0;
      mActY = 0;
      mActZ = 1;

    }
    break;

    case '+':
    {

      myStar->getChild(movimien, 1, mActX, mActY, mActZ);

      glutPostRedisplay();
    }
      break;
    case '-':
    {
      myStar->getChild(movimien, -1, mActX, mActY, mActZ);

      glutPostRedisplay();

    }
      break;

    case 'q':
    {
      myCamera.forward( 3 ) ;
      glutPostRedisplay( );
    }
      break;
      case 'Q':
      {
        myCamera.forward( 3 ) ;
        glutPostRedisplay( );
      }
        break;
    case 'e':
    {
      myCamera.forward( -3 ) ;
      glutPostRedisplay( );
    }
      break;
      case 'E':
      {
        myCamera.forward( -3 ) ;
        glutPostRedisplay( );
      }
        break;

    case 'p': case 'P':
    {

      if(agarrar == true){

      }else{
        inicioPelota = 500;
        start = chrono::high_resolution_clock::now();
        animacion = true;
        pelotaY = inicioPelota;
      }
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
  if( dx > 0 )      myCamera.rotY( -1 );
  else if( dx < 0 ) myCamera.rotY( 1 );
  if( dy > 0 )      myCamera.rotX( 1 );
  else if( dy < 0 ) myCamera.rotX( -1 );

  // Redraw
  glutPostRedisplay( );
}

// eof - SolarSystem.cxx
