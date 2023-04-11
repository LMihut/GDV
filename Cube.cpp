/* ----------------------------------------------------------- */
/* Wuerfel_mit_Normalen.cpp  (inkl. Normalen)                  */
/* Autor: W.-D. Groch                                          */
/* letzte Aenderung:	Groch   02.07.2014                     */
/* ----------------------------------------------------------- */
#include <GL/freeglut.h>
#include "Cube.h"

void Wuerfel_mit_Normalen(GLfloat fSeitenL)
{
	glBegin(GL_POLYGON);   //Vorderseite
        glNormal3f(0.0f, 0.0f, 1.0f);
	    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
	    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
	    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
	    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Rechte Seite
        glNormal3f(1.0f, 0.0f, 0.0f);
	    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
	    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
	    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
	    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Rueckseite
        glNormal3f(0.0f, 0.0f, -1.0f);
	    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
	    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
	    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
	    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Linke Seite
        glNormal3f(-1.0f, 0.0f, 0.0f);
	    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
	    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
	    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
	    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Deckflaeche
        glNormal3f(0.0f, 1.0f, 0.0f);
	    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
	    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
	    glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
	    glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
	glEnd();

	glBegin(GL_POLYGON);   //Bodenflaeche
        glNormal3f(0.0f, -1.0f, 0.0f);
	    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
	    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
	    glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
	    glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
	glEnd();

	return;
}

void Wuerfel_TexturBuilding(GLfloat fSeitenL, GLuint tex_2d)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex_2d);
    glPushMatrix();

    glBegin(GL_POLYGON);   //Vorderseite
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2d(0., 0.); glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
        glTexCoord2d(1., 0.);glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
        glTexCoord2d(1., 1.);glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
        glTexCoord2d(0., 1.);glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Rechte Seite
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2d(0., 0.); glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
        glTexCoord2d(1., 0.); glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
        glTexCoord2d(1., 1.); glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
        glTexCoord2d(0., 1.);glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Rueckseite
        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Linke Seite
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2d(0., 1.); glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
        glTexCoord2d(0., 0.); glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
        glTexCoord2d(1., 0.); glVertex3f(-fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
        glTexCoord2d(1., 1.); glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Deckflaeche
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
        glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
        glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
        glVertex3f(-fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
    glEnd();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    return;
}

void Wuerfel_TexturStreet(GLfloat fSeitenL, GLuint tex_2d)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex_2d);
    glPushMatrix();

    glBegin(GL_POLYGON);   //Vorderseite
        glNormal3f(0.0f, 0.0f, 1.0f);
        glTexCoord2d(0., 0.); glVertex3f(-fSeitenL/2.0f,-fSeitenL/150.0f,+fSeitenL/2.0f);
        glTexCoord2d(1., 0.);glVertex3f(+fSeitenL/2.0f,-fSeitenL/150.0f,+fSeitenL/2.0f);
        glTexCoord2d(1., 1.);glVertex3f(+fSeitenL/2.0f,+fSeitenL/150.0f,+fSeitenL/2.0f);
        glTexCoord2d(0., 1.);glVertex3f(-fSeitenL/2.0f,+fSeitenL/150.0f,+fSeitenL/2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Rechte Seite
        glNormal3f(1.0f, 0.0f, 0.0f);
        glTexCoord2d(0., 0.); glVertex3f(+fSeitenL/2.0f,-fSeitenL/150.0f,+fSeitenL/2.0f);
        glTexCoord2d(1., 0.); glVertex3f(+fSeitenL/2.0f,-fSeitenL/150.0f,-fSeitenL/2.0f);
        glTexCoord2d(1., 1.); glVertex3f(+fSeitenL/2.0f,+fSeitenL/150.0f,-fSeitenL/2.0f);
        glTexCoord2d(0., 1.);glVertex3f(+fSeitenL/2.0f,+fSeitenL/150.0f,+fSeitenL/2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Rueckseite
        glNormal3f(0.0f, 0.0f, -1.0f);
        glTexCoord3f(0.0f, 0.0f,0.0f); glVertex3f(+fSeitenL/2.0f,+fSeitenL/150.0f,-fSeitenL/2.0f);
        glTexCoord3f(1.0f, 0.0f,0.0f); glVertex3f(+fSeitenL/2.0f,-fSeitenL/150.0f,-fSeitenL/2.0f);
        glTexCoord3f(0.0f, 0.0f,0.0f); glVertex3f(-fSeitenL/2.0f,-fSeitenL/150.0f,-fSeitenL/2.0f);
        glTexCoord3f(0.0f, 1.0f,0.0f); glVertex3f(-fSeitenL/2.0f,+fSeitenL/150.0f,-fSeitenL/2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Linke Seite
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2d(0., 0.); glVertex3f(-fSeitenL/2.0f,+fSeitenL/150.0f,-fSeitenL/2.0f);
        glTexCoord2d(1., 0.); glVertex3f(-fSeitenL/2.0f,-fSeitenL/150.0f,-fSeitenL/2.0f);
        glTexCoord2d(1., 1.); glVertex3f(-fSeitenL/2.0f,-fSeitenL/150.0f,+fSeitenL/2.0f);
        glTexCoord2d(0., 1.); glVertex3f(-fSeitenL/2.0f,+fSeitenL/150.0f,+fSeitenL/2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Deckflaeche
        glNormal3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-fSeitenL/2.0f,+fSeitenL/150.0f,+fSeitenL/2.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(+fSeitenL/2.0f,+fSeitenL/150.0f,+fSeitenL/2.0f);
        glTexCoord2f(1.0f, 1.0f);  glVertex3f(+fSeitenL/2.0f,+fSeitenL/150.0f,-fSeitenL/2.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-fSeitenL/2.0f,+fSeitenL/150.0f,-fSeitenL/2.0f);
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    return;
}

// Würfel mit drei spezifizierten Seitenlängen
void Wuerfel_mit_Normalen( GLfloat fSeitenLX, GLfloat fSeitenLY, GLfloat fSeitenLZ )
{
    glPushMatrix();
    glScalef(fSeitenLX, fSeitenLY, fSeitenLZ);
    Wuerfel_mit_Normalen(fSeitenLX);
    glPopMatrix();
    return;
}

void Trapezoid(GLfloat fSeitenL)
{
    glBegin(GL_POLYGON);   //Vorderseite
        glNormal3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-fSeitenL/2.0f,-fSeitenL/4.0f,+fSeitenL/2.0f);
        glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
        glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
        glVertex3f(-fSeitenL/2.0f,+fSeitenL/4.0f,+fSeitenL/2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Rechte Seite
        glNormal3f(1.0f, 0.0f, 0.0f);
        glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
        glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
        glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
        glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Rueckseite
        glNormal3f(0.0f, 0.0f, -1.0f);
        glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
        glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
        glVertex3f(-fSeitenL/2.0f,-fSeitenL/4.0f,-fSeitenL/2.0f);
        glVertex3f(-fSeitenL/2.0f,+fSeitenL/4.0f,-fSeitenL/2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Linke Seite
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glVertex3f(-fSeitenL/2.0f,+fSeitenL/4.0f,-fSeitenL/2.0f);
        glVertex3f(-fSeitenL/2.0f,-fSeitenL/4.0f,-fSeitenL/2.0f);
        glVertex3f(-fSeitenL/2.0f,-fSeitenL/4.0f,+fSeitenL/2.0f);
        glVertex3f(-fSeitenL/2.0f,+fSeitenL/4.0f,+fSeitenL/2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Deckflaeche
        glNormal3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-fSeitenL/2.0f,+fSeitenL/4.0f,+fSeitenL/2.0f);
        glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,+fSeitenL/2.0f);
        glVertex3f(+fSeitenL/2.0f,+fSeitenL/2.0f,-fSeitenL/2.0f);
        glVertex3f(-fSeitenL/2.0f,+fSeitenL/4.0f,-fSeitenL/2.0f);
    glEnd();

    glBegin(GL_POLYGON);   //Bodenflaeche
        glNormal3f(0.0f, -1.0f, 0.0f);
        glVertex3f(-fSeitenL/2.0f,-fSeitenL/4.0f,-fSeitenL/2.0f);
        glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,-fSeitenL/2.0f);
        glVertex3f(+fSeitenL/2.0f,-fSeitenL/2.0f,+fSeitenL/2.0f);
        glVertex3f(-fSeitenL/2.0f,-fSeitenL/4.0f,+fSeitenL/2.0f);
    glEnd();

    return;
}