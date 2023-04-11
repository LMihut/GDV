//
// Created by LaviniaMihut on 28.02.2021.
//

#include "Landscape.h"
#include <math.h>
#include "Cube.h"

extern GLuint treeTex;
extern GLuint grassTex;
extern GLuint groundTexture;

void drawGround(GLuint treeTex)
{
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBindTexture(GL_TEXTURE_2D, treeTex);
    glPushMatrix();
    drawQuad();
    glPopMatrix();
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D);
}

void drawQuad()
{
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 0.0f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 0.0f);
    glEnd();
}

void treeLandscape()
{
    // Ground
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(2.5,0.3,20);
    glPopMatrix();

    // Road
    glPushMatrix();
    glColor3d(0,0.5,0.1);
    glTranslated(0,.65,-3.5);
    glScaled(5,0.45,12.25);
    Wuerfel_TexturStreet(1., groundTexture);
    glPopMatrix();

    //2. Tree (the big one) left side
    glPushMatrix();
    glAlphaFunc(GL_GREATER, 0.5);
    glEnable(GL_ALPHA_TEST);
    glTranslated(-7,1.5,-1);
    glRotated(65,0,1,0);
    glRotated(-15,0,1,0);
    glScaled(1.5,2.,2);
    drawGround(treeTex);
    glPopMatrix();

    //1. Tree (small) left side
    glPushMatrix();
    glTranslated(-6,1.5,-2);
    glRotated(65,0,1,0);
    glRotated(-15,0,1,0);
    glScaled(1.5,2,2);
    drawGround(treeTex);
    glPopMatrix();

    //1. Tree (small) on the right
    glPushMatrix();
    glTranslated(6,1.5,-4);
    glRotated(-65,0,1,0);
    glRotated(15,0,1,0);
    glScaled(1.5,2,2);
    drawGround(treeTex);
    glPopMatrix();

    //2. Tree (big) on the right
    glPushMatrix();
    glTranslated(7.,1.5,-2);
    glRotated(-65,0,1,0);
    glScaled(1.5,2.5,2);
    drawGround(treeTex);
    glDisable(GL_ALPHA_TEST);
    glPopMatrix();
}

void drawCircle(float cx, float cy, float cz,
                float r, int points,
                float red, float green, float blue, GLuint tex_2d)
{
    float theta;

    theta = 2 * 3.14 / (float)points;

    float c = cosf(theta); // precalculate the sine and cosine
    float s = sinf(theta);
    float t;
    int i;

    float x = r; // we start at angle = 0
    float y = 0;

    float tx = (x/r + 1)*0.5;
    float ty = (y/r + 1)*0.5;

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex_2d);

    glPushMatrix();
    glTranslatef(cx, cy, cz);

    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0,0);
    glVertex2f(0,0);
    for(i = 0; i < points; i++)
    {
        float const tx = (x/r + 1)*0.5;
        float const ty = (y/r + 1)*0.5;

        glTexCoord2f(tx, ty);
        glVertex2f(x, y);

        //apply the rotation matrix
        t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    }
    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

