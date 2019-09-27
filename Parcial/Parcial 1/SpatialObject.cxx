#include "SpatialObject.h"
#include <cmath>
#include <fstream>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>


using namespace std;
float q = 0;
float b = 0;
bool pintado = false;

// -------------------------------------------------------------------------
SpatialObject::
SpatialObject( )
  : m_Mesh( nullptr ),
    m_Path( nullptr ),
    m_CurrentAngle( 0 ),
    m_Animating( false )
{
  this->_createPath( );
}

SpatialObject::
SpatialObject( const std::string& fname )
  : m_Mesh( nullptr ),
    m_Path( nullptr ),
    m_CurrentAngle( 0 ),
    m_Animating( false )
{
  this->_createPath( );

  // Open file and put its contents into a string buffer
  std::ifstream in( fname.c_str( ) );
  if( !in )
  {
    in.close( );
    throw std::runtime_error(
      std::string( "Error: Could not open \"" ) + fname + "\""
      );
  } // end if
  std::istringstream buffer(
    std::string(
      ( std::istreambuf_iterator< char >( in ) ),
      std::istreambuf_iterator< char >( )
      )
    );
  in.close( );

  // Read file
  buffer >> this;
}

SpatialObject::
~SpatialObject( )
{
  if( this->m_Mesh != nullptr )
    delete this->m_Mesh;
  if( this->m_Path != nullptr )
    delete this->m_Path;
  for( SpatialObject* c: this->m_Children )
    delete c;
  this->m_Children.clear( );
}

Mesh* SpatialObject::
getMesh( )
{
  return( this->m_Mesh );
}

// -------------------------------------------------------------------------
const Mesh* SpatialObject::
getMesh( ) const
{
  return( this->m_Mesh );
}

// -------------------------------------------------------------------------
void SpatialObject::
addChild( SpatialObject* o )
{
  this->m_Children.push_back( o );
}

// -------------------------------------------------------------------------
unsigned long SpatialObject::
getNumberOfChildren( ) const
{
  return( this->m_Children.size( ) );
}

// -------------------------------------------------------------------------
void SpatialObject::
getChild( float i , float r, float rx, float ry, float rz)
{
  q = q + 1;
    if(q == i ){
      if(r == 1){
        if(rx == 1){
          this->setMovActX(this->getMovActX()+1);
        }
        if(ry == 1){
          this->setMovActY(this->getMovActY()+1);
        }

        if(rz == 1){
          this->setMovActZ(this->getMovActZ()+1);
        }
      }
      if(r == -1){
        if(rx == 1){
          this->setMovActX(this->getMovActX()-1);
        }
        if(ry == 1){
          this->setMovActY(this->getMovActY()-1);
        }

        if(rz == 1){
          this->setMovActZ(this->getMovActZ()-1);
        }
      }
    }else{
      for( SpatialObject* child: this->m_Children){
        child->getChild(i, r, rx, ry, rz);
    }
  }
}


// -------------------------------------------------------------------------
const std::string& SpatialObject::
getName( ) const
{

  return( this->m_Name );
}

// -------------------------------------------------------------------------
const float& SpatialObject::
getScale( ) const
{
  return( this->m_Scale );
}

const float& SpatialObject::
getRed( ) const
{
  return( this->red );
}

const float& SpatialObject::
getGreen( ) const
{
  return( this->green );
}

const float& SpatialObject::
getBlue( ) const
{
  return( this->blue );
}

const float& SpatialObject::
getVerX( ) const
{
  return( this->verX );
}

const float& SpatialObject::
getVerY( ) const
{
  return( this->verY );
}

const float& SpatialObject::
getVerZ( ) const
{
  return( this->verZ );
}

const float& SpatialObject::
getRotacion( ) const
{
  return( this->rotacion );
}

const float& SpatialObject::
getMovActX( ) const
{
  return( this->movActX );
}

const float& SpatialObject::
getMovActY( ) const
{
  return( this->movActY );
}

const float& SpatialObject::
getMovActZ( ) const
{
  return( this->movActZ );
}


// -------------------------------------------------------------------------
void SpatialObject::
setPath( float r1, float r2, float nx, float ny, float nz )
{
  this->m_Radius1 = r1;
  this->m_Radius2 = r2;
  this->m_Normal[ 0 ] = nx;
  this->m_Normal[ 1 ] = ny;
  this->m_Normal[ 2 ] = nz;
  this->m_Normal.normalize( );
}

void SpatialObject::
setRotacion( float rot )
{
  this->rotacion = rot;
}

void SpatialObject::
setMovActX( float x )
{
  this->movActX = x;
}

void SpatialObject::
setMovActY( float y )
{
  this->movActY = y;
}

void SpatialObject::
setMovActZ( float z )
{
  this->movActZ = z;
}

// -------------------------------------------------------------------------
void SpatialObject::
startAnimation( )
{
  this->m_Animating = true;
  this->m_StartAnimation = std::chrono::high_resolution_clock::now( );
  for( SpatialObject* child: this->m_Children )
    child->startAnimation( );
}

// -------------------------------------------------------------------------
void SpatialObject::
stopAnimation( )
{
  this->m_Animating = false;
  for( SpatialObject* child: this->m_Children )
    child->stopAnimation( );
}

void SpatialObject::
drawInOpenGLContext( GLenum mode , bool agarrar)
{
  pintado = false;
  glPushMatrix();

  glColor3f(0,0,1);
  glutSolidSphere(3.1,20,20);

    glColor3f( this->getRed(), this->getGreen(), this->getBlue() );

  glRotatef(this->getMovActX(), 1, 0, 0);
  glRotatef(this->getMovActY(), 0, 1, 0 );
  glRotatef(this->getMovActZ(), 0, 0, 1 );

  if(this->getVerX() == 0){
    if(this->getVerZ() == 0){
      glBegin(mode);
      glVertex3f (0+3,0,0+3);
      glVertex3f (0+3,0,0-3);
      glVertex3f (0-3,0,0-3);
      glVertex3f (0-3,0,0+3);
      glEnd();

      glBegin(mode);
      glVertex3f (0+3,0,0+3);
      glVertex3f (0-3,0,0+3);
      glVertex3f( this->getVerX()-3, this->getVerY(), this->getVerZ()+3);
      glVertex3f( this->getVerX()+3, this->getVerY(), this->getVerZ()+3);
      glEnd();

      glBegin(mode);
      glVertex3f (0+3,0,0-3);
      glVertex3f (0+3,0,0+3);
      glVertex3f( this->getVerX()+3, this->getVerY(), this->getVerZ()+3);
      glVertex3f( this->getVerX()+3, this->getVerY(), this->getVerZ()-3);
      glEnd();

      glBegin(mode);
      glVertex3f (0-3,0,0-3);
      glVertex3f (0+3,0,0-3);
      glVertex3f( this->getVerX()+3, this->getVerY(), this->getVerZ()-3);
      glVertex3f( this->getVerX()-3, this->getVerY(), this->getVerZ()-3);
      glEnd();

      glBegin(mode);
      glVertex3f (0-3,0,0+3);
      glVertex3f (0-3,0,0-3);
      glVertex3f( this->getVerX()-3, this->getVerY(), this->getVerZ()-3);
      glVertex3f( this->getVerX()-3, this->getVerY(), this->getVerZ()+3);
      glEnd();

      glBegin(mode);
      glVertex3f( this->getVerX()-3, this->getVerY(), this->getVerZ()-3);
      glVertex3f( this->getVerX()+3, this->getVerY(), this->getVerZ()-3);
      glVertex3f( this->getVerX()+3, this->getVerY(), this->getVerZ()+3);
      glVertex3f( this->getVerX()-3, this->getVerY(), this->getVerZ()+3);
      glEnd();

      pintado = true;
    }
  }

  if(this->getVerY() == 0){
    if(this->getVerZ() == 0){
      glBegin(mode);
      glVertex3f (0,0+3,0+3);
      glVertex3f (0,0+3,0-3);
      glVertex3f (0,0-3,0-3);
      glVertex3f (0,0-3,0+3);
      glEnd();

      glBegin(mode);
      glVertex3f (0,0+3,0+3);
      glVertex3f (0,0-3,0+3);
      glVertex3f( this->getVerX(), this->getVerY()-3, this->getVerZ()+3);
      glVertex3f( this->getVerX(), this->getVerY()+3, this->getVerZ()+3);
      glEnd();

      glBegin(mode);
      glVertex3f (0,0+3,0-3);
      glVertex3f (0,0+3,0+3);
      glVertex3f( this->getVerX(), this->getVerY()+3, this->getVerZ()+3);
      glVertex3f( this->getVerX(), this->getVerY()+3, this->getVerZ()-3);
      glEnd();

      glBegin(mode);
      glVertex3f (0,0-3,0-3);
      glVertex3f (0,0+3,0-3);
      glVertex3f( this->getVerX(), this->getVerY()+3, this->getVerZ()-3);
      glVertex3f( this->getVerX(), this->getVerY()-3, this->getVerZ()-3);
      glEnd();

      glBegin(mode);
      glVertex3f (0,0-3,0+3);
      glVertex3f (0,0-3,0-3);
      glVertex3f( this->getVerX(), this->getVerY()-3, this->getVerZ()-3);
      glVertex3f( this->getVerX(), this->getVerY()-3, this->getVerZ()+3);
      glEnd();

      glBegin(mode);
      glVertex3f( this->getVerX(), this->getVerY()-3, this->getVerZ()-3);
      glVertex3f( this->getVerX(), this->getVerY()+3, this->getVerZ()-3);
      glVertex3f( this->getVerX(), this->getVerY()+3, this->getVerZ()+3);
      glVertex3f( this->getVerX(), this->getVerY()-3, this->getVerZ()+3);
      glEnd();
      pintado = true;
    }
  }

  if(this->getVerX() == 0){
    if(this->getVerY() == 0){
      glBegin(mode);
      glVertex3f (0+3,0+3,0);
      glVertex3f (0+3,0-3,0);
      glVertex3f (0-3,0-3,0);
      glVertex3f (0-3,0+3,0);
      glEnd();

      glBegin(mode);
      glVertex3f (0+3,0+3,0+3);
      glVertex3f (0-3,0+3,0+3);
      glVertex3f( this->getVerX()-3, this->getVerY()+3, this->getVerZ());
      glVertex3f( this->getVerX()+3, this->getVerY()+3, this->getVerZ());
      glEnd();

      glBegin(mode);
      glVertex3f (0+3,0-3,0);
      glVertex3f (0+3,0+3,0);
      glVertex3f( this->getVerX()+3, this->getVerY()+3, this->getVerZ());
      glVertex3f( this->getVerX()+3, this->getVerY()-3, this->getVerZ());
      glEnd();

      glBegin(mode);
      glVertex3f (0-3,0-3,0);
      glVertex3f (0+3,0-3,0);
      glVertex3f( this->getVerX()+3, this->getVerY()-3, this->getVerZ());
      glVertex3f( this->getVerX()-3, this->getVerY()-3, this->getVerZ());
      glEnd();

      glBegin(mode);
      glVertex3f (0-3,0+3,0);
      glVertex3f (0-3,0-3,0);
      glVertex3f( this->getVerX()-3, this->getVerY()-3, this->getVerZ());
      glVertex3f( this->getVerX()-3, this->getVerY()+3, this->getVerZ());
      glEnd();

      glBegin(mode);
      glVertex3f( this->getVerX()-3, this->getVerY()-3, this->getVerZ());
      glVertex3f( this->getVerX()+3, this->getVerY()-3, this->getVerZ());
      glVertex3f( this->getVerX()+3, this->getVerY()+3, this->getVerZ());
      glVertex3f( this->getVerX()-3, this->getVerY()+3, this->getVerZ());
      glEnd();
      pintado = true;
    }
  }

  if(pintado == false){
    glBegin(mode);
    glVertex3f (0,0+3,0+3);
    glVertex3f (0,0+3,0-3);
    glVertex3f (0,0-3,0-3);
    glVertex3f (0,0-3,0+3);
    glEnd();

    glBegin(mode);
    glVertex3f (0,0+3,0+3);
    glVertex3f (0,0-3,0+3);
    glVertex3f( this->getVerX(), this->getVerY()-3, this->getVerZ()+3);
    glVertex3f( this->getVerX(), this->getVerY()+3, this->getVerZ()+3);
    glEnd();

    glBegin(mode);
    glVertex3f (0,0+3,0-3);
    glVertex3f (0,0+3,0+3);
    glVertex3f( this->getVerX(), this->getVerY()+3, this->getVerZ()+3);
    glVertex3f( this->getVerX(), this->getVerY()+3, this->getVerZ()-3);
    glEnd();

    glBegin(mode);
    glVertex3f (0,0-3,0-3);
    glVertex3f (0,0+3,0-3);
    glVertex3f( this->getVerX(), this->getVerY()+3, this->getVerZ()-3);
    glVertex3f( this->getVerX(), this->getVerY()-3, this->getVerZ()-3);
    glEnd();

    glBegin(mode);
    glVertex3f (0,0-3,0+3);
    glVertex3f (0,0-3,0-3);
    glVertex3f( this->getVerX(), this->getVerY()-3, this->getVerZ()-3);
    glVertex3f( this->getVerX(), this->getVerY()-3, this->getVerZ()+3);
    glEnd();

    glBegin(mode);
    glVertex3f( this->getVerX(), this->getVerY()-3, this->getVerZ()-3);
    glVertex3f( this->getVerX(), this->getVerY()+3, this->getVerZ()-3);
    glVertex3f( this->getVerX(), this->getVerY()+3, this->getVerZ()+3);
    glVertex3f( this->getVerX(), this->getVerY()-3, this->getVerZ()+3);
    glEnd();
  }

  glTranslatef( this->getVerX(), this->getVerY(), this->getVerZ() );
  b = b+1;
  glColor3f(0,0,1);
  glutSolidSphere(3.1,20,20);

  for( SpatialObject* child: this->m_Children ){
    //cout << " X: " << child->getVerX() << " Y: " << child->getVerY() << " Z: " << child->getVerZ() << endl;
    child->drawInOpenGLContext( mode , agarrar);
    //cout << "------------------------------" << endl;
  }
  glPopMatrix();

  q = 0;
}

// -------------------------------------------------------------------------
void SpatialObject::
_createPath( )
{
  if( this->m_Path != nullptr )
    delete this->m_Path;
  this->m_Path = new Mesh( );

  unsigned int nSamples = 100;
  std::vector< unsigned int > face;
  for( unsigned int i = 0; i < nSamples; ++i )
  {
    float a = 2.0 * _PI * float( i ) / float( nSamples );
    this->m_Path->addPoint( std::cos( a ), std::sin( a ), 0 );
    face.push_back( i + 1 );
  } // end for
    face.push_back( 1 );
  this->m_Path->addFace( face );
}

// -------------------------------------------------------------------------
void SpatialObject::
_strIn( std::istream& in )
{

  this->setMovActX(0);
  this->setMovActY(0);
  this->setMovActZ(0);
  this->setRotacion(0);

  typedef std::map< char, std::string > _TMap;

  // Read data for this spatial object
  std::string line;
  std::getline( in, line );
  _TMap data;
  while( line.substr( 0, 2 ) != "--" )
  {
    std::istringstream d( line );
    char data_type;
    d >> data_type;

    std::string data_value;
    std::string v;
    d >> data_value;
    while( !d.eof( ) )
    {
      std::string v;
      d >> v;
      data_value += " " + v;
    } // end while
    data[ data_type ] = data_value;
    std::getline( in, line );
  } // end while

  _TMap::const_iterator dIt;
  // Check color
  dIt = data.find( 'C' );
  float r = 1, g = 0, b = 0;
  if( dIt != data.end( ) )
  {
    std::istringstream d( dIt->second );
    d >> r >> g >> b;
  } // end if
  this->red = 1;
  this->green = 0;
  this->blue = 0;

  // Check scale
  dIt = data.find( 'X' );
  if( dIt != data.end( ) )
  {
    std::istringstream d( dIt->second );
    d >> this->verX;
  }

  dIt = data.find( 'Y' );
  if( dIt != data.end( ) )
  {
    std::istringstream d( dIt->second );
    d >> this->verY;
  }

  dIt = data.find( 'Z' );
  if( dIt != data.end( ) )
  {
    std::istringstream d( dIt->second );
    d >> this->verZ;
  }

  // Check recursion
  dIt = data.find( 'D' );
  if( dIt != data.end( ) )
  {
    std::istringstream d( dIt->second );
    unsigned int nRecs;
    d >> nRecs;
    for( unsigned int i = 0; i < nRecs; ++i )
    {
      SpatialObject* child = new SpatialObject( );
      in >> child;
      this->addChild( child );
    } // end for
  } // end if
}

// -------------------------------------------------------------------------
void SpatialObject::
_strOut( std::ostream& out ) const
{
}

// eof - SpatialObject.cxx
