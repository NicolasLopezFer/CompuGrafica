// -------------------------------------------------------------------------
// @author Leonardo Florez-Valencia (florez-l@javeriana.edu.co)
// -------------------------------------------------------------------------
#ifndef __SpatialObject__h__
#define __SpatialObject__h__

#include "Vector.h"
#include "Mesh.h"
#include <chrono>


/**
 */
class SpatialObject
{
public:
  //! Streaming methods
  //@{
  friend std::istream& operator>>( std::istream& i, SpatialObject& s )
    {
      s._strIn( i );
      return( i );
    }

  friend std::istream& operator>>( std::istream& i, SpatialObject* s )
    {
      s->_strIn( i );
      return( i );
    }

  friend std::ostream& operator<<( std::ostream& o, const SpatialObject& s )
    {
      s._strOut( o );
      return( o );
    }

  friend std::ostream& operator<<( std::ostream& o, const SpatialObject* s )
    {
      s->_strOut( o );
      return( o );
    }
  //@}

public:
  //! Memory management
  //@{
  SpatialObject( );
  SpatialObject( const std::string& fname );
  virtual ~SpatialObject( );
  //@}

  //! Mesh-related methods
  //@{
  Mesh* getMesh( );
  const Mesh* getMesh( ) const;
  //@}

  //! All the magic happens here
  //@{
  void addChild( SpatialObject* o );
  unsigned long getNumberOfChildren( ) const;
  void getChild( float i , float r, float rx, float ry, float rz);
  //@}

  //! Other methods
  //@{
  const std::string& getName( ) const;
  const float& getScale( ) const;
  const float& getRed() const;
  const float& getGreen() const;
  const float& getBlue() const;
  const float& getVerX() const;
  const float& getVerY() const;
  const float& getVerZ() const;

  const float& getRotacion() const;
  const float& getMovActX() const;
  const float& getMovActY() const;
  const float& getMovActZ() const;
  //@}

  void setPath( float r1, float r2, float nx, float ny, float nz );
  void setRotacion( float rot );
  void setMovActX( float x );
  void setMovActY( float y );
  void setMovActZ( float z );

  //! All the magic happens here
  virtual void startAnimation( );
  virtual void stopAnimation( );
  virtual void drawInOpenGLContext( GLenum mode , bool agarrar);

protected:
  void _createPath( );

  //! Here's where the real streaming is done
  //@{
  void _strIn( std::istream& in );
  void _strOut( std::ostream& out ) const;
  //@}

protected:
  std::string m_Name;
  float       m_Scale;
  float       red;
  float       green;
  float       blue;
  float       verX;
  float       verY;
  float       verZ;
  float       rotacion;
  float       movActX;
  float       movActZ;
  float       movActY;
  bool        agarrar;
  Mesh*       m_Mesh;
  Mesh*       m_Path;

  float m_Radius1;
  float m_Radius2;
  Vector m_Normal;

  float m_Frequency;
  float m_CurrentAngle;
  bool m_Animating;
  std::chrono::time_point< std::chrono::high_resolution_clock > m_StartAnimation;

  std::vector< SpatialObject* > m_Children;
};

#endif // __SpatialObject__h__

// eof - SpatialObject.h
