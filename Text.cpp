//
// Created by Lavinia Mihut on 28.02.2021.
//

#include "Text.h"

void drawChar(char c, float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x, y+8,z);
    glScalef(0.003f,0.003f,z);
    glutStrokeCharacter(GLUT_STROKE_ROMAN , c);
    glPopMatrix();
}

void drawText(char* str, int x, int y, int z)
{
    char *c;
    glPushMatrix();
    glTranslatef(x, y+8,z);
    glScalef(0.002f,0.002f,z);

    for (c=str; *c != '\0'; c++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
    }
    glPopMatrix();
}

void drawText2(char* str, int x, int y, int z)
{
    char *c;
    glPushMatrix();
    glTranslatef(x, y+8,z);
    glScalef(0.005f,0.005f,z);

    for (c=str; *c != '\0'; c++)
    {
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN , *c);
    }
    glPopMatrix();
}