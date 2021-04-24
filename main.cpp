#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define GL_GLEXT_PROTOTYPES

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "control.h"
#include "lighting.h"
#include "shadow.h"

#ifndef M_PI
#define M_PI 3.14159265
#endif

static int renderShadow = 1, renderScene = 1, renderReflection = 1;

GLfloat lightColor0[] = {0.8, 1.0, 0.8, 1.0}; //Color (0.5, 0.5, 0.5)

static GLfloat floorVertices[4][3] = {
    { -20.0, 0.0, 20.0 },
    { 20.0, 0.0, 20.0 },
    { 20.0, 0.0, -20.0 },
    { -20.0, 0.0, -20.0 },
};

static GLfloat floorVertices1[4][3] = {
    { -15.0, 0.01, 15.0 },
    { 15.0, 0.01, 15.0 },
    { 15.0, 0.01, -15.0 },
    { -15.0, 0.01, -15.0 },
};

// function to draw floor for given coordinates disabling the lighting property
void drawFloor(GLfloat floorVertices[4][3]) {
    glDisable(GL_LIGHTING);

    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3fv(floorVertices[0]);
    glVertex3fv(floorVertices[1]);
    glVertex3fv(floorVertices[2]);
    glVertex3fv(floorVertices[3]);
    glEnd();
    glPopMatrix();

    glEnable(GL_LIGHTING);
}

static GLfloat floorPlane[4];

static void redraw(void)
{
    int start, end;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    lightPosition[0] = 12*cos(lightAngle);
    lightPosition[1] = lightHeight;
    lightPosition[2] = 12*sin(lightAngle);
    lightPosition[3] = 0.0;


    CshaMatrix(floorShadow, floorPlane, lightPosition);

    glPushMatrix();
    if(angle2<-10)
        angle2=30;
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);

    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    if (renderReflection) {

        glDisable(GL_DEPTH_TEST);
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);

        glEnable(GL_STENCIL_TEST);
        glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
        glStencilFunc(GL_ALWAYS, 1, 0xffffffff);
        drawFloor(floorVertices1);

        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
        glEnable(GL_DEPTH_TEST);

        glStencilFunc(GL_EQUAL, 1, 0xffffffff);
        glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

        glPushMatrix();
        glScalef(10.0, -8.0, 10.0);

        Ediffuselight();
        Especularlight();
        glEnable(GL_NORMALIZE);

        glDisable(GL_CULL_FACE);
        flags=1;
        draw();
        glEnable(GL_CULL_FACE);
        glDisable(GL_NORMALIZE);

        Ediffuselight();
        Especularlight();
        glPopMatrix();

        glDisable(GL_STENCIL_TEST);

    }

    glFrontFace(GL_CW);
    glColor4f(0.1, 0.1, 0.7, 1.0);
    drawFloor(floorVertices);
    glFrontFace(GL_CCW);

    if (renderShadow) {

        glEnable(GL_STENCIL_TEST);
        glStencilFunc(GL_ALWAYS, 3, 0xffffffff);
        glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    }

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.5, 1.0, 0.5, 0.3);
    drawFloor(floorVertices);
    glColor4f(0.196078, 0.6, 0.8,0.3);
    drawFloor(floorVertices1);
    glDisable(GL_BLEND);

    if (renderScene) {
        glPushMatrix();
        glColor3f(1.0, 1, 1);
        glScalef(10,10, 10);
        glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
        glEnable(GL_NORMALIZE);
        glDisable(GL_CULL_FACE);

        flags=1;
        draw();

        glEnable(GL_CULL_FACE);
        glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
        glDisable(GL_NORMALIZE);
        glPopMatrix();
    }


    shadow(1);


    glPushMatrix();
    glDisable(GL_LIGHTING);
    glColor3f(1.0, 1.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_LIGHTING);
    glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}



void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_CULL_FACE);
    glMatrixMode(GL_PROJECTION);
    gluPerspective( 45.0, 2.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){
    int i;
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(400, 400 );
    glutCreateWindow("CGV-Reflection + Shadow");
    initRendering();

    glutDisplayFunc(redraw);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutIdleFunc(idle);
    //glutKeyboardFunc(normalKeyboard);

    polygonOffsetVersion = 2;
    glPolygonOffset(-2.0, -1.0);

    Lighting();
    gluLookAt(0.0, 8.0, 40.0,
              0, 8, 0.0,
              0.0, 1.0, 0);

    findPlane(floorPlane, floorVertices[1], floorVertices[2], floorVertices[3]);

    glutMainLoop();
    return 0;
}
