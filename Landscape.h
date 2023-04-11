//
// Created by Lavinia Mihut on 28.02.2021.
//

#ifndef BLANQUETTMIHUT_GDV_LANDSCAPE_H
#define BLANQUETTMIHUT_GDV_LANDSCAPE_H


#include <GL/glut.h>

void Landscape(GLuint roadTex);
void Landscape (GLfloat side, GLfloat roadWidth, GLuint pavementTex, GLuint roadTex);
void treeLandscape();
void drawGround(GLuint treeTex);
void building(int n, int R, int G);
void singleBuilding(int R, int G, int B);
void drawQuad();

void drawCircle(float cx, float cy, float cz,
                float r, int points,
                float red, float green, float blue, GLuint tex_2d);


#endif //BLANQUETTMIHUT_GDV_LANDSCAPE_H
