#include <GL/glut.h>
#include <iostream>
#include <stdlib.h>
#include <GL/SOIL.h>

#include "Cube.h"
#include "Landscape.h"
#include "Motorbike.h"
#include "Text.h"

#define ROAD_SIZE 20

using namespace std;

GLuint buildingTextured14;
const char *buildingTexpathd14 = "..\\Docs/d14.png";

GLuint buildingTexture;
const char *buildingTexpath = "..\\Docs/c10.jpg";

GLuint groundTexture;
const char *groundTexpath = "..\\Docs/asphalt.jpg";

GLuint grassTex;
const char* grassTexPath="..\\Docs/grass.png";

GLuint treeTex;
const char* treeTexPath="..\\Docs/TREE1.png";

GLuint bitcoinTex;
const char* bitTexPath="..\\Docs/bitcoin.jpg";

GLfloat x_winkel = 0.0, y_winkel = 0.0;

float zoom = 4;
int building_array[5000][5000];
float trackX = 0, trackY = 0, trackZ = -8;
float routeSection1 = -20, routeSection2 = -40, routeSection3 = -60, routeSection4 = -80, routeSection5 = -100, routeSection6 = -120;
float rotationX = 0, rotationY = 0, rotationZ = 0;

float bikeSpeed = 0.4;

float angleBackFracment = 0.02;
float r[] = {0.6,0.4,0.4,0.9,0.4,0.6,0.9,0.7,0.5,1.0};
float g[] = {0.2,0.8,0.4,0.5,0.6,0.5,0.9,0.9,1.,0.8};
float b[] = {0.6,0.5,0.8,0.8,0.9,0.8,0.9,0.6,0.8,1.0};
int counter = 0;
int counterAnzeige = 0;
int delayGameOver = 0;
int countLive = 6;
int showLive = 0;

float bitcoinPosX[7] = {1, -2, 2, -2, -2, 0, 2}; // Positionen der Torus-Platzierungen
float bitcoinPosY[7] = {1, 1, 1, 1, 1, 1, 1};

float kegelPosX[5] = {0, 0, -2, 2, 2};
float kegelPosY[5] = {1, 1, 1, 1, 1};

int TIME = 0;
bool START = false;
bool LIGHT = false;
bool GAMEOVER = false;
bool rot = false;
bool isFullscreen = false;


void environment(int n)
{
    // Ground
    glColor3d(0,0.5,0.1);
    glPushMatrix();
    glTranslated(0,0,0);
    glScaled(ROAD_SIZE * 2, 0.3, ROAD_SIZE * 2);
    Wuerfel_TexturStreet(1.,grassTex);
    glPopMatrix();

    // Road
    glPushMatrix();
    glTranslated(0,.65,0.5);
    glScaled(ROAD_SIZE / 4, 0.45, 20.25);
    Wuerfel_TexturStreet(1., groundTexture);
    glPopMatrix();

    // Hinderniskegel
    glColor3f(1.0, 0., 0.0);
    glPushMatrix();

    glTranslated(kegelPosX[n], kegelPosY[n] - 0.45, 10);
    glTranslatef(0,0.1,0);
    glRotatef(270.0, 1.0, 0.0, 0.0);
    glutSolidCone(0.5, 1.0, 10, 5);

    glColor3f(1.0, 0., 0.0);
    glTranslatef(0,0,0.0); // Startpositionen
    Wuerfel_mit_Normalen(1, 1, 0.2);
    glPopMatrix();

    // Bitcoins
    glColor3d(1,1,0.1);
    glPushMatrix();
    glTranslated(bitcoinPosX[n], bitcoinPosY[n] - 1, 0);
    glScaled(3.2,3.2,0.);
    drawCircle(0.0, 0.4, 0.5,0.20, 10000,0.5, 0.5, 0, bitcoinTex);
    glPopMatrix();

    for(int i= -(ROAD_SIZE / 2) + 4; i < (ROAD_SIZE / 2); i+=2)
    {
        for(int j= -(ROAD_SIZE / 2) + 4; j < (ROAD_SIZE / 2); j+=2)
        {
            if(building_array[i + (ROAD_SIZE / 2) + 1][j + (ROAD_SIZE / 2) + 1] != 0)
            {
                glPushMatrix();
                glTranslated(i,0,j);
                building(building_array[i + (ROAD_SIZE / 2) + 1][j + (ROAD_SIZE / 2) + 1], i, j);
                glPopMatrix();
            }
            else if(i >= -5 && i <= 5){}
            else
            {
                building_array[i + (ROAD_SIZE / 2) + 1][j + (ROAD_SIZE / 2) + 1]= (rand() % 5) + 1;
                glPushMatrix();
                glTranslated(i,0,j);
                building(building_array[i + (ROAD_SIZE / 2) + 1][j + (ROAD_SIZE / 2) + 1], i, j);
                glPopMatrix();
            }
        }
    }
}

void building(int n, int R, int G)
{
    for(int i=0; i<n; i++)
    {
        glPushMatrix();
        glTranslated(0,0.95+i,0);
        singleBuilding(G, R, i);
        glPopMatrix();
    }
}

void singleBuilding(int R, int G, int B)
{
    glColor3d(r[R%11],g[G%11],b[B%11]);
    glPushMatrix();
    glTranslated(0,0,0);
    glEnable(GL_TEXTURE_2D);
    Wuerfel_TexturBuilding(2., buildingTexture);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 1000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void backGroundColor (int item)
{
    switch(item)
    {
        case 1 :
        {
            glClearColor(0.70, 0.90, 0.98, 1.0); // Hintergrundfarbe hell blau definieren
            glutPostRedisplay();
            break;
        }
        case 2 :
        {
            glClearColor(.0f,.0f,.0f,.0f);	// Hintergrundfarbe schwarz definieren
            glutPostRedisplay();
            break;
        }
        case 3 :
        {
            glClearColor(1.0f,1.0f,1.0f,1.0f);// Hintergrundfarbe weiss definieren
            glutPostRedisplay();
            break;
        }
    }
}

void toggle_fullscreen()
{
    isFullscreen = !isFullscreen;
    if (isFullscreen)
    {
        glutFullScreen();
    }
    else
    {
        glutReshapeWindow(1300, 700);
        glutPositionWindow(100, 100);
    }
}

void mainMenu(int item)
{
    switch(item)
    {
        case 1 :
            std::cout << "Exit" << std::endl;
            exit(0);
    }
}

void subMenu() // Unter-Menu
{
    int submenu1;
    submenu1 = glutCreateMenu(backGroundColor);
    glutAddMenuEntry("BackgroundColor LIGHT BLUE", 1);
    glutAddMenuEntry("BackgroundColor BLACK", 2);
    glutAddMenuEntry("BackgroundColor WHITE", 3);

    // Haupt-Menu
    glutCreateMenu(mainMenu);
    glutAddSubMenu("Background color", submenu1);
    glutAddMenuEntry("Exit", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void prepareGametoDisplay(double a, double aa);

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
    glMatrixMode(GL_MODELVIEW);

    buildingTexture = SOIL_load_OGL_texture(buildingTexpath,
                                            SOIL_LOAD_AUTO,
                                            SOIL_CREATE_NEW_ID,
                                            SOIL_FLAG_MIPMAPS
                                            | SOIL_FLAG_INVERT_Y
                                            | SOIL_FLAG_NTSC_SAFE_RGB
                                            | SOIL_FLAG_COMPRESS_TO_DXT );

    buildingTextured14 = SOIL_load_OGL_texture(buildingTexpathd14, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                            SOIL_FLAG_MIPMAPS
                                            | SOIL_FLAG_INVERT_Y
                                            | SOIL_FLAG_NTSC_SAFE_RGB
                                            | SOIL_FLAG_COMPRESS_TO_DXT );

    treeTex = SOIL_load_OGL_texture(treeTexPath, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                       SOIL_FLAG_INVERT_Y
                                       | SOIL_FLAG_MULTIPLY_ALPHA );

    bitcoinTex = SOIL_load_OGL_texture(bitTexPath, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                   SOIL_FLAG_MIPMAPS
                                   | SOIL_FLAG_INVERT_Y
                                   | SOIL_FLAG_NTSC_SAFE_RGB
                                   | SOIL_FLAG_COMPRESS_TO_DXT );

    groundTexture = SOIL_load_OGL_texture(groundTexpath, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                       SOIL_FLAG_MIPMAPS
                                       | SOIL_FLAG_INVERT_Y
                                       | SOIL_FLAG_NTSC_SAFE_RGB
                                       | SOIL_FLAG_COMPRESS_TO_DXT );

    grassTex = SOIL_load_OGL_texture(grassTexPath, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                          SOIL_FLAG_MIPMAPS
                                          | SOIL_FLAG_INVERT_Y
                                          | SOIL_FLAG_NTSC_SAFE_RGB
                                          | SOIL_FLAG_COMPRESS_TO_DXT );

    glClearDepth(1.0);
    subMenu();
}

void MouseFunc(int button, int state, int x, int y)
{
    GLfloat xMousePos = float(x);
    GLfloat yMousePos = float(y);
    switch(button)
    {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
                cout << "linke Maustaste gedrueckt " << xMousePos << ", " << yMousePos << endl;
            else
                cout << "linke Maustaste losgelassen "<< xMousePos<<", " << yMousePos << endl;
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
                cout << "rechte Maustaste gedrueckt " << xMousePos << ", " << yMousePos << endl;
            else
                cout << "rechte Maustaste losgelassen "<< xMousePos << ", " << yMousePos << endl;
            break;
    }
}

void draw()
{
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;

    TIME = t;

    // Motorbike
    if(rotationX > 11) rotationX = 11;
    if(rotationX < -11) rotationX =- 11;
    if(rotationZ > 10) rotationZ = 10;
    if(rotationZ < -15) rotationZ =- 15;

    glPushMatrix();
    glTranslated(0,0.8,0);
    glRotated(270,0,1,0);
    glRotated(0,0,0,1);
    glRotated(rotationX, 1, 0, 0);
    glRotated(rotationY, 0, 1, 0);
    glRotated(rotationZ, 0, 0, 1);

    glScaled(0.75,0.75,0.75);
    drawMotorbike();
    glPopMatrix();

    // Environment
    if(trackX >= 2.1) trackX = 2.1; // linke Spurbegrenzung
    if(trackX <= -2.1) trackX = -2.1; // rechte Spurbegrenzung

    if(trackY > 0.1) trackY = 0.1;
    if(trackY < -15) trackY = -15;

    glPushMatrix();
    glTranslated(trackX, trackY, trackZ);
    environment(2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(trackX, trackY, routeSection1);
    treeLandscape();
    glPopMatrix();

    glPushMatrix();
    glTranslated(trackX, trackY, routeSection2);
    environment(3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(trackX, trackY, routeSection3);
    environment(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(trackX, trackY, routeSection4);
    environment(5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(trackX, trackY, routeSection5);
    environment(4);
    glPopMatrix();

    glPushMatrix();
    glTranslated(trackX, trackY, routeSection6);
    environment(2);
    glPopMatrix();

    trackZ += bikeSpeed;
    routeSection1 += bikeSpeed;
    routeSection2 += bikeSpeed;
    routeSection3 += bikeSpeed;
    routeSection4 += bikeSpeed;
    routeSection5 += bikeSpeed;
    routeSection6 += bikeSpeed;

    if(trackZ >= 20)trackZ=-110;
    if(routeSection1 >= 20)routeSection1 = -110;
    if(routeSection2 >= 20)routeSection2 = -110;
    if(routeSection3 >= 20)routeSection3 = -110;
    if(routeSection4 >= 20)routeSection4 = -110;
    if(routeSection5 >= 20)routeSection5 = -110;
    if(routeSection6 >= 20)routeSection6 = -110;

    if(rotationX > 0) rotationX -= angleBackFracment;
    if(rotationX < 0) rotationX += angleBackFracment;
    if(rotationY > 0) rotationY -= angleBackFracment;
    if(rotationY < 0) rotationY += angleBackFracment;
    if(rotationZ > 0) rotationZ -= angleBackFracment;
    if(rotationZ < 0) rotationZ += angleBackFracment;

    unsigned char data[4];
    glReadPixels(683, 0, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, data);
    cout << "R: " << (int)data[0] << endl;
    cout << "G: " << (int)data[1] << endl;
    cout << "B: " << (int)data[2] << endl;

    int rot_Anteil_mitte = (int)data[0];

    if(rot_Anteil_mitte == 255)
    {
        cout << "Auf Hindernis getroffen! Das Spiel ist vorbei!" << endl;
        cout << "Eingesammelte Bitcoin: " << counter / 2 << endl;
        countLive -=1;
        if(countLive == 0){
            GAMEOVER = true;
        }
    }

    cout << "trackX: " << trackX << " rotationX: " << rotationX << " rotationY: " << rotationY << endl; // Testausgabe
    if(trackX < 2.4 && trackX > 1.5) // linker Bitcoin getroffen
    {
        if(rot_Anteil_mitte >= 5 && rot_Anteil_mitte != 255 && rot_Anteil_mitte != 25)
        {
            cout << "Sie haben den linken Bitcoin getroffen." << endl;
            counter++;
        }
    }

    if(trackX <= 0.4 && trackX >= -0.4)
    {
        if(rot_Anteil_mitte >= 5 && rot_Anteil_mitte != 255 && rot_Anteil_mitte != 25)
        {
            cout << "Sie haben den mittleren Bitcoin getroffen." << endl;
            counter++;
        }
    }

    if(trackX <= -1.7 && trackX >= -2.3)
    {
        if(rot_Anteil_mitte >= 5 && rot_Anteil_mitte != 255 && rot_Anteil_mitte != 25)
        {
            cout << "Sie haben den rechten Bitcoin getroffen." << endl;
            counter++;
        }
    }
    cout << "Eingesammelte Bitcoin: " << counter / 2 << endl;
}

void display()
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;
    double aa = a;

    if(!rot)
    {
        a=0;
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    prepareGametoDisplay(a, aa);
}

void prepareGametoDisplay(double a, double aa)
{
    gluLookAt(0.0, 7.5, 10.0,
              0, 4, 0,
              0, 1.0f, 0.0f);

    if(START)
    {
        glPushMatrix();
        glTranslated(0,0,0);
        glScaled(zoom,zoom,zoom);
        glRotated(a,0,1,0);
        glRotatef(x_winkel, 1.0f, 0.0f, 0.0f);
        glRotatef(y_winkel, 0.0f, 1.0f, 0.0f);
        draw();
        glPopMatrix();
        drawText("LEFT: A, RIGHT: D, MAIN MENU: M", -8, 0.9, 0);
        drawText("TIME : ", 5, -4, 0);

        drawText("SCORE: ", 3, -4, 0);
        counterAnzeige = counter / 2;
        drawText("LIVES: ", 1.5, -4, 0);
        showLive = countLive / 2;
        drawChar(showLive + 48, 1.75, -4, 0);

        if(GAMEOVER)
        {
            drawText2("GAME OVER!", -8, -5, 0);
            delayGameOver++;
            if(delayGameOver == 40)
            {
                exit(0);
            }
        }

        int mod, number=0;
        while(TIME)
        {
            mod = TIME % 10;
            number = number * 10 + mod;
            TIME /= 10;
        }
        float tmp = 0;
        while(number)
        {
            mod = number % 10;
            drawChar(mod + 48, 6 + tmp, -4, 0);
            number /= 10;
            tmp += 0.2;
        }
        mod = 0;
        number = 0;
        while(counterAnzeige)
        {
            mod = counterAnzeige % 10;
            number = number * 10 + mod;
            counterAnzeige /= 10;
        }
        tmp = 0;
        while(number)
        {
            mod = number % 10;
            drawChar(mod + 48, 4 + tmp, -4, 0);
            number /= 10;
            tmp += 0.2;
        }
    }
    else if(LIGHT)
    {
        // Dunklen Background
        glColor3f(1,1,1);
        drawText("MAIN MENU: M", -1, -1, 0);
        glTranslated(0.,3,0.);
        glScaled(2,2,2);
        glPushMatrix();

        //Floor
        glColor3f(0, 1, 0);
        glScaled(2,2,2);
        Wuerfel_TexturStreet(2., grassTex);

        //D14
        glPushMatrix();
        glColor3f(0, 1., 1.);
        glTranslatef(0,0.25,-0.25);
        glScaled(2,2,0.02);
        Wuerfel_TexturBuilding(0.5, buildingTextured14);
        glPopMatrix();

        //Motorbike
        glScalef(0.25, 0.25, 0.25);
        glPushMatrix();
        glTranslated(0,1,3);
        glRotated(aa,0,1,0);
        glScaled(1.5,1.5,1.5);
        drawMotorbike();
        glPopMatrix();

        glPopMatrix();
    }
    else if(LIGHT == false && START == false)
    {
        glDisable(GL_LIGHTING);
        glPushMatrix();
        glTranslated(0,3,0);
        glRotated(aa,0,1,0);
        glScaled(2.5,2.5,2.5);
        drawMotorbike();
        glPopMatrix();
        drawText("Press G to Start ** Press L for Light", -3, -1, 0);
        drawText2("Motorbike Game", -3, 0, 0);
    }
    glutSwapBuffers();
}

void RenderScene(void)
{
    // Hier befindet sich der Code der in jedem Frame ausgefuehrt werden muss
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Puffer loeschen
    glLoadIdentity();
    glutSwapBuffers();
    glFlush();
}

void SpecialFunc(int key, int x, int y) // Funktions- und Pfeil-Tasten abfragen
{
    GLfloat xMousePos = float(x);
    GLfloat yMousePos = float(y);
    if (key <= 12)
        cout << "GLUT_KEY_F" << key << "  " << xMousePos << ", " << yMousePos << endl;
    else
        switch (key)
        {
            case GLUT_KEY_LEFT:
                cout << "GLUT_KEY_LEFT " << xMousePos << ", " << yMousePos << endl;
                if(y_winkel != 20)
                    y_winkel = y_winkel + 5.0f;
                if (y_winkel > 360.0)
                    y_winkel = 0.0f;
                break;
            case GLUT_KEY_UP:
                cout << "GLUT_KEY_UP " << xMousePos << ", " << yMousePos << endl;
                if(x_winkel != 10)
                    x_winkel = x_winkel + 5.0f;
                if (x_winkel > 360.0)
                    x_winkel = 0.0f;
                break;
            case GLUT_KEY_RIGHT:
                cout << "GLUT_KEY_RIGHT "<< xMousePos << ", " << yMousePos << endl;
                if(y_winkel != 340)
                    y_winkel = y_winkel - 5.0f;
                if (y_winkel < 0.0)
                    y_winkel = 360.0f;
                break;

            case GLUT_KEY_DOWN:
                cout << "GLUT_KEY_DOWN " << xMousePos << ", " << yMousePos << endl;
                if(x_winkel != 350)
                    x_winkel = x_winkel - 5.0f;
                if (x_winkel<0.0)
                    x_winkel = 360.0f;
                break;
            case GLUT_KEY_END:
                cout << "GLUT_KEY_END " << xMousePos << ", " << yMousePos << endl;
                glLoadIdentity();
                break;
        }
}

static void key(unsigned char key, int x, int y)
{
    float frac = 0.3;
    float rotFrac = 1;
    switch (key)
    {
        case 'q':
            exit(0);
        case 'r':
            rot = true;
            break;
        case 't':
            rot = false;
            break;
        case 'z':
            zoom += 0.05;
            if(zoom >= 6) zoom = 6; // näher
            break;
        case 'Z':
            zoom -= 0.05;
            if(zoom <= 0.75) zoom = 0.75; // entfernter
            break;
        case 'a':
            trackX += frac;
            rotationX += rotFrac * 3;
            rotationY += rotFrac / 2;
            if(trackX >= 2.1) trackX = 2.1;
            if(rotationX <= -9) rotationX = -9;
            if(rotationY >= 4.79) rotationY = 4.79;
            break;
        case 'd':
            trackX -= frac;
            rotationX -= rotFrac * 3;
            rotationY -= rotFrac / 2;
            if(trackX <= -2.1) trackX = -2.1;
            if(rotationX >= 10.95) rotationX = 10.95;
            if(rotationY <= -2.26) rotationY = -2.26;
            break;

        case 'g':
        {
            START = true;
            LIGHT = false;
            break;
        }
        case 'f':
            toggle_fullscreen();
            break;
        case 'm':
        {
            START = false;
            LIGHT = false;
            break;
        }
        case 'l':
        {
            LIGHT = true;
            START = false;
            break;
        }
    }
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */
void Animate (int value)
{
    int wait_msec = 10;
    glutTimerFunc(wait_msec, Animate, ++value);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1366,720);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

    glutCreateWindow("**BLANQUETT**MIHUT**");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glutTimerFunc(10, Animate, 0);

    glutSpecialFunc(SpecialFunc);
    glutMouseFunc(MouseFunc);
    init();

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}