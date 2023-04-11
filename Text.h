//
// Created by lored on 28.02.2021.
//

#ifndef BLANQUETTMIHUT_GDV_TEXT_H
#define BLANQUETTMIHUT_GDV_TEXT_H

#include <GL/glut.h>

void drawTextNum(char ch[],int numtext,int xpos, int ypos);
void drawTextNum2(char ch[],int numtext,int xpos, int ypos);
void drawBitmapText(char *str,float x,float y,float z);
void drawText2(char* str, int x, int y, int z);
void drawText(char* str, int x, int y, int z);
void drawChar(char c, float x, float y, float z);
void drawText(char ch[], int xpos, int ypos);

#endif //BLANQUETTMIHUT_GDV_TEXT_H
