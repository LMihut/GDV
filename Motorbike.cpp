/* ----------------------------------------------------------- */
/* Motorbike.cpp                                               */
/* Autor: Lavinia Mihut & Jan Blanquett                        */
/* ----------------------------------------------------------- */

#include "Motorbike.h"

extern bool LIGHT;


void draw_wheel()
{
    int iTimeElapsed = glutGet(GLUT_ELAPSED_TIME);
    float fRevolveScale2 = 1.5f;
    long i;

    // push temp state
    glPushMatrix();

    glRotatef(iTimeElapsed * fRevolveScale2,0.0,0.0,1.0);

    glPushMatrix();
    glColor3f(1,1,0);
    glTranslated(0,0.025,0.35);
    glScaled(0.05,1.2,0.05);
    glutSolidCube(1.);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,0);
    glTranslated(0,0.025,-0.35);
    glScaled(0.05,1.2,0.05);
    glutSolidCube(1.);
    glPopMatrix();

    glColor3f(1., 0., 0.);
    glutSolidSphere(0.1f, 16, 16);
    glutSolidTorus(0.42,0.2,30,30);

    // five bolts, step 72 degree (72*5=360 degree)
    glColor3f(.1, .1, .0);
    for(i=0; i<5; ++i)
    {
        glPushMatrix();
        glRotatef(72.0f*i,0.0,0.0,1.0); // rotate coordinate 72 degree
        glTranslatef(0.04f, 0.0, 0.0);// translate on the rotated coordinate
        glutSolidTorus(0.35,0.5,30,30);
        glPopMatrix();
    }

    glTranslatef(0.0f, 0.0f, 0.0f);// translate on the rotated coordinate
    glutSolidSphere(0.01, 16, 16);
    glutSolidTorus(0.35,0.5,30,30);

    // pop temp state
    glPopMatrix();
}

int spot_light(GLfloat posX, GLfloat posY, GLfloat posZ, GLfloat *spotDir)
{
    GLfloat light_position[] = {posX, posY, posZ, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.05);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2.0);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 55.0);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDir);
    return 0;
}


void drawMotorbike()
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;

    glStencilFunc(GL_ALWAYS, 1, 0xFF);
    glStencilMask(0xFF);

    //Wheels
    glPushMatrix();
    glColor3d(0,0,0);
    glEnable(GL_DEPTH_TEST);
    glTranslated(0, 0, 0);
    glScaled (0.25, 0.25, 0.25);
    draw_wheel();
    glPopMatrix();

    glPushMatrix();
    glColor3d(0,0,0);
    glTranslated(1.5, 0, 0);
    glScaled (0.25, 0.25, 0.25);
    draw_wheel();
    glPopMatrix();

    //Reifenhalter1
    glColor3d(1,0,0);
    glPushMatrix();
    glTranslated(0.,0.15,0);
    glScaled(0.1,0.2,0.2);
    glRotated(70,0,0,1);
    glTranslated(0.0,-0.15,0);
    glutSolidCube(1);
    glPopMatrix();

    //Reifenhalter2
    glColor3d(1,0,0);
    glPushMatrix();
    glTranslated(1.5,0.25,0);
    glRotated(30,0,0,1);
    glScaled(0.1,0.2,0.2);
    glTranslated(-1.5,-0.25,0);
    glutSolidCube(1);
    glPopMatrix();

    //Carcasa1
    glColor3d(1,0,0);
    glPushMatrix();
    glTranslated(0.09,0.25,0.);
    glScaled(0.5,0.5,0.2);
    glRotated(120,0,0,1);
    glTranslated(-0.09,-0.25,0.);
    Trapezoid(1.);
    glPopMatrix();

    //Carcasa2
    glColor3d(1,0,0);
    glPushMatrix();
    glTranslated(0.30,0.3,0.);
    glScaled(0.5,0.5,0.2);
    glRotated(90,0,0,1);
    glTranslated(-0.30,-0.3,0.);
    Trapezoid(1.);
    glPopMatrix();

    //Unterer Teil
    glColor3d(1,0,0);
    glPushMatrix();
    glTranslated(0.8,0.02,0);
    glScaled(0.5,0.25,0.2);
    Wuerfel_mit_Normalen(1);
    glPopMatrix();

    //Toba de esapament fata
    glColor3d(0.5,0.5,0);
    glPushMatrix();
    glTranslated(1.5,0.25,0.1);
    glRotated(-45, 0,0,1);
    glScaled(0.1,0.5,0.15);
    glTranslated(-1.5,-0.25,0.1);
    glutSolidSphere(1,30,30);
    glPopMatrix();

    //Toba de esapament spate
    glColor3d(0.5,0.5,0);
    glPushMatrix();
    glTranslated(1.5,0.25,-0.1);
    glRotated(-45, 0,0,1);
    glScaled(0.1,0.5,0.15);
    glTranslated(-1.5,-0.25,0.1);
    glutSolidSphere(1,30,30);
    glPopMatrix();

    // Windschutzscheibe
    glColor3d(0,0,0);
    glPushMatrix();
    glTranslated(0.3,0.7,0);
    glRotated(80,0,0,1);
    glScaled(0.15,0.02,0.19);
    glTranslated(-0.3,-0.7,0);
    Wuerfel_mit_Normalen(1.);
    glPopMatrix();

    //Koerper
    glColor3d(1,0,0);
    glPushMatrix();
    glTranslated(1.25,0.29,0.);
    glRotated(-60, 0,0,1);
    glScaled(0.1,0.75,0.2);
    glTranslated(-1.25,-0.29,0.);
    Wuerfel_mit_Normalen(1.);
    glPopMatrix();

    glColor3d(1,0,0);
    glPushMatrix();
    glTranslated(0.75,0.29,0.);
    glScaled(0.55,0.35,0.2);
    Wuerfel_mit_Normalen(1.);
    glPopMatrix();

    //Schwarzer Sitz
    glColor3d(0,0,0);
    glPushMatrix();
    glTranslated(0.65,0.5,0.);
    glRotated(90, 0,0,1);
    glScaled(0.1,0.25,0.2);
    glTranslated(-0.65,-0.5,0.);
    glutSolidSphere(0.75,30,30);
    glPopMatrix();

    if(LIGHT)
    {
        glEnable(GL_LIGHTING);
        GLfloat spotDir[] = {-3.5, 1, -2.5};
        spot_light(0, 1.5, 2.5 * 0.2, spotDir);
        spot_light(0, 1.5, 2.5 * 0.2, spotDir);
    }
    // Licht
    glColor3d(1,1,0);
    glPushMatrix();

    if(LIGHT)
    {
        glDisable(GL_LIGHTING);
    }
    glTranslated(-0.12,0.35,0);
    glRotated(170, 0,0,1);
    glScaled(0.025,0.1,0.1);
    glTranslated(0.12,-0.35,0);
    Wuerfel_mit_Normalen(1.);

    if (LIGHT)
    {
        glEnable(GL_LIGHTING);
    }
    glPopMatrix();

    // Lenkrad
    glColor3d(0,0,0);
    glPushMatrix();
    glTranslated(0.25,0.5,0);
    glRotated(80,0,0,1);
    glScaled(0.05,0.05,0.35);
    glTranslated(-0.25,-0.5,0);
    Wuerfel_mit_Normalen(1.);
    glPopMatrix();

    //Driver
    glPushMatrix();
    glColor3f(1.,1.,0);
    glRotated(90,0,1,0);
    glScaled(0.75,0.7,0.75);
    glTranslated(0,1.75,1.);
    createDriver();
    glPopMatrix();
}