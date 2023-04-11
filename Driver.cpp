//
// Created by Lavinia Mihut on 17.02.2021.
//

#include "Driver.h"

void createDriver() {
    glPushMatrix();
    glRotatef(180, 0, 1, 0);

    // Kopf
    glPushMatrix();
    glColor3f(0.5,0.5,0);
    glTranslated(0,-0.37,0.2);
    glutSolidSphere(0.25,30,30);
    glPopMatrix();

    // Helm
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(0,-0.3,0.2);
    glutSolidSphere(0.25,30,30);
    glPopMatrix();

    // Koerper
    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(0.0, -0.8, 0.);
    glRotated(15,1,0,0);
    Wuerfel_mit_Normalen(.6, 1.2, .5);
    glPopMatrix();

    // Bein links
    glPushMatrix();
    glColor3f(0.5,0.5,0.);
    glTranslatef(0.2, -0.98, 0);
    glRotatef(-15, 1, 0, 0);
    glTranslatef(0, -0.4, 0);
    glScaled(1,1.25,1);
    Wuerfel_mit_Normalen(0.3, 2.0, 0.3);
    glPopMatrix();

    // Bein rechts
    glPushMatrix();
    glColor3f(0.5,0.5,0);
    glTranslatef(-0.2, -0.98, 0);
    glRotatef(-15, 1, 0, 0);
    glTranslatef(0, -0.4, 0);
    glScaled(1,1.25,1);
    Wuerfel_mit_Normalen(0.3, 2.0, 0.3);
    glPopMatrix();

    // Arm links
    glPushMatrix();
    glTranslated(-0.2,-0.75,0.3);
    glRotated(-45,1,0,0);
    glScaled(1,3,1);
    Wuerfel_mit_Normalen(0.3, 1., 0.3);
    glPopMatrix();

    // Arm rechts
    glPushMatrix();
    glColor3f(0.5,0.5,0);
    glTranslated(0.2,-0.75,0.3);
    glRotated(-45,1,0,0);
    glScaled(1,3,1);
    Wuerfel_mit_Normalen(0.3, 1., 0.3);
    glPopMatrix();

    glPopMatrix();
}