#include <GL/freeglut.h>
#include <GL/SOIL.h>

void Wuerfel_mit_Normalen ( GLfloat fSeitenL );
void Wuerfel_mit_Normalen ( GLfloat fSeitenLX, GLfloat fSeitenLY, GLfloat fSeitenLZ );
void Trapezoid(GLfloat fSeitenL);
void Wuerfel_TexturBuilding(GLfloat fSeitenL, GLuint tex_2d);
void Wuerfel_TexturStreet(GLfloat fSeitenL, GLuint tex_2d);
void Wuerfel_TexturSky(GLfloat fSeitenL, GLuint tex_2d);
