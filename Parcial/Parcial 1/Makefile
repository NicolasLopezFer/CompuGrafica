CXXFLAGS := -std=c++11 -g
LIBS := -framework OpenGL -framework GLUT
#LIBS := -lm -lGL -lGLU -lglut
HEADERS := Vector.h Camera.h Mesh.h SpatialObject.h
OBJS := BrazoRobotico.o Vector.o Camera.o Mesh.o SpatialObject.o

all: BrazoRobotico

BrazoRobotico: $(OBJS) $(HEADERS)
	g++ $(CXXFLAGS) $(OBJS) -o $@ $(LIBS)

%.o: %.cxx
	g++ $(CXXFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -r *.o BrazoRobotico

## eof - Makefile
