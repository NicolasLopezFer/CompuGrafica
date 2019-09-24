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
SpatialObject* SpatialObject::
getChild( unsigned long i )
{
  return( this->m_Children[ i ] );
}

// -------------------------------------------------------------------------
const SpatialObject* SpatialObject::
getChild( unsigned long i ) const
{
  return( this->m_Children[ i ] );
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
getVerXPad( ) const
{
  return( this->verXPad );
}

const float& SpatialObject::
getVerYPad( ) const
{
  return( this->verYPad );
}

const float& SpatialObject::
getVerZPad( ) const
{
  return( this->verZPad );
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
drawInOpenGLContext( GLenum mode )
{

  glPushMatrix();
  glPopMatrix();

  glColor3f( this->getRed(), this->getGreen()+0.5, this->getBlue() );
  glBegin(mode);
  glVertex3f (this->getVerXPad(),this->getVerYPad(),this->getVerZPad());
  glVertex3f( this->getVerX()+this->getVerXPad(), this->getVerY()+this->getVerYPad(), this->getVerZ()+this->getVerZPad() );
  glEnd();
  glPushMatrix();
  glPopMatrix();

  for( SpatialObject* child: this->m_Children ){
    child->drawInOpenGLContext( mode );
    cout << child->getVerXPad() << endl;
  }

  glPopMatrix();

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
    d >> this->verX;
  }

  dIt = data.find( 'B' );
  if( dIt != data.end( ) )
  {
    std::istringstream d( dIt->second );
    d >> this->verXPad;
  }

  dIt = data.find( 'N' );
  if( dIt != data.end( ) )
  {
    std::istringstream d( dIt->second );
    d >> this->verYPad;
  }

  dIt = data.find( 'M' );
  if( dIt != data.end( ) )
  {
    std::istringstream d( dIt->second );
    d >> this->verZPad;
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
