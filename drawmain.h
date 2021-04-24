#ifndef DRAWMAIN_H
#define DRAWMAIN_H
#include "component.h"
#include <bits/stdc++.h>

using namespace std;
vector<double> default_vect;

#define Z_AXIS 0
#define Y_AXIS 1
#define SLANT 2

void draw_window(int axis, vector<int> val, vector<double> trans_val = default_vect) {
    glPushMatrix();
    if(trans_val.size() > 0)
        glTranslatef(trans_val[0], trans_val[1], trans_val[2]);
    switch(axis) {
        case Z_AXIS:    draw_window_z(val[0]);
                        break;
        case Y_AXIS:    draw_window_y(val[0]);
                        break;
        case SLANT:     draw_window_slnt(val[0], val[1], val[2]);
                        break;
    }
    glPopMatrix();
}

float sx=1.0f,sy=1.0f,sz=1.0f;

float xRot, yRot, zRot;
int flags;

void drawfix()
{
    glColor3f(199/256.0, 144/256.0, 86/256.0);
    glBegin(GL_POLYGON);

    glVertex3f(2*r,0.35f,3*r);
    glVertex3f(3*r,0.35f,2*r);
    glVertex3f(3*r,0.35f,-2*r);
    glVertex3f(2*r,0.35f,-3*r);
    glVertex3f(-2*r,0.35f,-3*r);
    glVertex3f(-3*r,0.35f,-2*r);
    glVertex3f(-3*r,0.35f,2*r);
    glVertex3f(-2*r,0.35f,3*r);

    glEnd();
}

void draw()
{
    float gx=117/256.0f, gy=58/256.0f,gz=6/256.0f;

    glPushMatrix();
    if(flags)
        glColor3f(199/256.0, 144/256.0, 86/256.0);
    draw_face(1);

    draw_smallface(1,0);

    draw_smallface(1,1);

    draw_face(-1);

    draw_smallface(-1,0);

    draw_smallface(-1,1);

    draw_facey(1);


    draw_smallfacey(1,0);

    draw_smallfacey(1,1);

    draw_facey(-1);

    draw_smallfacey(-1,0);

    draw_smallfacey(-1,1);

    draw_slnt(1,1);

    draw_slnt(1,-1);

    draw_slnt(-1,1);

    draw_slnt(-1,-1);
    glPopMatrix();

    glPushMatrix();
    drawBase();
    glPopMatrix();


    //draws minaret
    glPushMatrix();
    glTranslatef(0.7f,0,0.7f);
    if(flags)
    glColor3f(1,1,1);
    draw_cylinder(r/4,r/5,0.6f);
    glPopMatrix();


    // draws disc on minaret
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.7f,0.6f,0.7f);
    draw_cylinder(r/4,r/4,0.035f);
    glPopMatrix();
    // glPopMatrix();

    //draws disc along minaret
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.7f,0.19f,0.7f);
    draw_cylinder(0.25*r,0.25*r,0.035f);
    glPopMatrix();
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.7f,0.19f,0.7f);
    glTranslatef(0,0.18f,0);
    draw_cylinder(0.25*r,0.25*r,0.035f);

    glPopMatrix();

    //complete minaret
    glPushMatrix();
    if(flags)
    glColor3f(1,1.0,1);
    glTranslatef(0.7f,0.65f,0.7f);
    draw_hemisphere(r/4,0.01f);

    glPopMatrix();

    //draws minaret
    glPushMatrix();
    glTranslatef(0.7f,0,-0.7f);
    if(flags)
    glColor3f(1,1,1);
    draw_cylinder(r/4,r/5,0.6f);
    glPopMatrix();

    //draws disc on minaret
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.7f,0.6f,-0.7f);
    draw_cylinder(r/4,r/4,0.035f);
    glPopMatrix();

    //draws disc along minaret
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.7f,0.19f,-0.7f);
    draw_cylinder(0.25*r,0.25*r,0.035f);
    glPopMatrix();
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.7f,0.19f,-0.7f);
    glTranslatef(0,0.18f,0);
    draw_cylinder(0.25*r,0.25*r,0.035f);

    glPopMatrix();

    //completes minaret
    glPushMatrix();
    if(flags)
    glColor3f(1,1.0,1);
    glTranslatef(0.7f,0.65f,-0.7f);
    draw_hemisphere(r/4,0.01f);

    glPopMatrix();


    //draws minaret
    glPushMatrix();
    glTranslatef(-0.7f,0,0.7f);
    if(flags)
    glColor3f(1,1,1);
    draw_cylinder(r/4,r/5,0.6f);
    glPopMatrix();

    //draws disc on minaret
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.7f,0.6f,0.7f);
    draw_cylinder(r/4,r/4,0.035f);
    glPopMatrix();

    //draws disc along minaret
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.7f,0.19f,0.7f);
    draw_cylinder(0.25*r,0.25*r,0.035f);
    glPopMatrix();
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.7f,0.19f,0.7f);
    glTranslatef(0,0.18f,0);
    draw_cylinder(0.25*r,0.25*r,0.035f);

    glPopMatrix();


    //completes minaret
    glPushMatrix();
    if(flags)
    glColor3f(1,1.0,1);
    glTranslatef(-0.7f,0.65f,0.7f);
    draw_hemisphere(r/4,0.01f);

    glPopMatrix();

    //draws minaret
    glPushMatrix();
    glTranslatef(-0.7f,0,-0.7f);
    if(flags)
    glColor3f(1,1,1);
    draw_cylinder(r/4,r/5,0.6f);
    glPopMatrix();


    //draws disc on minaret
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.7f,0.6f,-0.7f);
    draw_cylinder(r/4,r/4,0.035f);
    glPopMatrix();

    //draws disc along minaret

    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.7f,0.19f,-0.7f);
    draw_cylinder(0.25*r,0.25*r,0.035f);
    glPopMatrix();
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.7f,0.19f,-0.7f);
    glTranslatef(0,0.18f,0);
    draw_cylinder(0.25*r,0.25*r,0.035f);

    glPopMatrix();


    //completes minaret
    glPushMatrix();
    if(flags)
    glColor3f(1,1.0,1);
    glTranslatef(-0.7f,0.65f,-0.7f);
    draw_hemisphere(r/4,0.01f);

    glPopMatrix();


    //draw  dome
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(0,0.35f,0);
    draw_cylinder(r-0.033,r-0.033,0.2f);
    glPopMatrix();

    ////draw  dome
    glPushMatrix();
    glTranslatef(0,0.55f,0);
    glTranslatef(0,0.11f,0);
    draw_hemisphere(r,0.08f);
    glPopMatrix();

    ////draw  dome
    glPushMatrix();
    glTranslatef(0,0.55f,0);
    if(flags)
    glColor3f(gx,gy,gz);
    draw_cylinder(r-0.031,r-0.031,0.08f);

    glPopMatrix();



    //draws leanPillar

    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(r,0,0.5f);
    draw_cylinder(0.015f,0.01f,0.52f);

    glPopMatrix();


    ////draws leanPillar
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-1*r,0,0.5f);
    draw_cylinder(0.015f,0.01f,0.52f);

    glPopMatrix();

    //draws leanPillar
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(r,0,-0.5f);
    draw_cylinder(0.015f,0.01f,0.52f);

    glPopMatrix();

    //draws leanPillar
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-1*r,0,-0.5f);
    draw_cylinder(0.015f,0.01f,0.52f);

    glPopMatrix();

    //draws leanPillar
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(2*r,0,0.5f);
    draw_cylinder(0.015f,0.01f,0.52f);

    glPopMatrix();

    //draws leanPillar
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-2*r,0,0.5f);
    draw_cylinder(0.015f,0.01f,0.52f);

    glPopMatrix();

    //draws leanPillar

    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(2*r,0,-0.5f);
    draw_cylinder(0.015f,0.01f,0.52f);

    glPopMatrix();

    //draws leanPillar
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-2*r,0,-0.5f);
    draw_cylinder(0.015f,0.01f,0.52f);

    glPopMatrix();

    //draws leanPillar

    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.5f,0,r);
    draw_cylinder(0.015f,0.01f,0.52f);

    glPopMatrix();

    //draws leanPillar
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.5f,0,-1*r);
    draw_cylinder(0.015f,0.01f,0.52f);
    glPopMatrix();

    //draws leanPillar
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.5f,0,2*r);
    draw_cylinder(0.015f,0.01f,0.52f);

    glPopMatrix();

    //draws leanPillar
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.5f,0,-2*r);
    draw_cylinder(0.015f,0.01f,0.52f);

    glPopMatrix();

    //draws leanPillar
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.5f,0,r);
    draw_cylinder(0.015f,0.01f,0.52f);

    glPopMatrix();

    //draws leanPillar
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.5f,0,-1*r);
    draw_cylinder(0.015f,0.01f,0.52f);
    glPopMatrix();

    //draws leanPillar
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.5f,0,2*r);
    draw_cylinder(0.015f,0.01f,0.52f);

    glPopMatrix();

    //draws leanPillar
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.5f,0,-2*r);
    draw_cylinder(0.015f,0.01f,0.52f);

    glPopMatrix();

    //draws chhatri

    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(0.3f,0.35f,0.3f);
    draw_cylinder(0.045,0.045,0.14f);
    glPopMatrix();

    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.3f,0.45f,0.3f);
    draw_cylinder(0.047,0.047,0.04f);
    glPopMatrix();

    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(0.3f,0.50f,0.3f);
    draw_hemisphere(0.046,0.1f);

    glPopMatrix();


    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(-0.3f,0.35f,0.3f);
    draw_cylinder(0.045,0.045,0.14f);
    glPopMatrix();

    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.3f,0.45f,0.3f);
    draw_cylinder(0.047,0.047,0.04f);
    glPopMatrix();

    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(-0.3f,0.50f,0.3f);
    draw_hemisphere(0.046,0.1f);

    glPopMatrix();

    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(0.3f,0.35f,-0.3f);
    draw_cylinder(0.045,0.045,0.14f);
    glPopMatrix();

    //draws chhatri

    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(0.3f,0.45f,-0.3f);
    draw_cylinder(0.047,0.047,0.04f);
    glPopMatrix();

    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(0.3f,0.50f,-0.3f);
    draw_hemisphere(0.046,0.1f);

    glPopMatrix();


    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(-0.3f,0.35f,-0.3f);
    draw_cylinder(0.045,0.045,0.14f);
    glPopMatrix();

    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(gx,gy,gz);
    glTranslatef(-0.3f,0.45f,-0.3f);
    draw_cylinder(0.047,0.047,0.04f);
    glPopMatrix();

    //draws chhatri
    glPushMatrix();
    if(flags)
    glColor3f(1,1,1);
    glTranslatef(-0.3f,0.50f,-0.3f);
    draw_hemisphere(0.046,0.1f);

    glPopMatrix();

    //draws door
    glPushMatrix();
//    glDisable(GL_LIGHTING);
//    glDisable(GL_DEPTH);
//    glDisable(GL_LIGHTING);
//    glDisable(GL_LIGHT0);
//    glDisable(GL_LIGHT1);
//    glDisable(GL_LIGHT2);
    draw_door_z(1);
    glPopMatrix();

      //draws door
    glPushMatrix();
//    glDisable(GL_LIGHTING);
//    glDisable(GL_DEPTH);
    draw_door_z(-1);
    glPopMatrix();


      //draws door
    glPushMatrix();
//    glDisable(GL_LIGHTING);
//    glDisable(GL_DEPTH);
    draw_door_y(1);
    glPopMatrix();


      //draws door
    glPushMatrix();
//    glDisable(GL_LIGHTING);
//    glDisable(GL_DEPTH);
    draw_door_y(-1);
    glPopMatrix();

    // Draw windows
    draw_window(Z_AXIS, {1});
    draw_window(Z_AXIS, {1}, {0.5*r, 0, 0});
    draw_window(Z_AXIS, {1}, {0,0.175f,0});
    draw_window(Z_AXIS, {1}, {0.5*r,0.175f,0});
    draw_window(Z_AXIS, {-1});
    draw_window(Z_AXIS, {-1}, {0.5*r,0,0});
    draw_window(Z_AXIS, {-1}, {0,0.175f,0});
    draw_window(Z_AXIS, {-1}, {0.5*r,0.175f,0});
    draw_window(Z_AXIS, {1}, {-3*r,0,0});
    draw_window(Z_AXIS, {1}, {0.5*r-3*r,0,0});
    draw_window(Z_AXIS, {1}, {-3*r,0.175f,0});
    draw_window(Z_AXIS, {1}, {0.5*r-3*r,0.175f,0});
    draw_window(Z_AXIS, {-1}, {-3*r,0,0});
    draw_window(Z_AXIS, {-1}, {0.5*r-3*r,0,0});
    draw_window(Z_AXIS, {-1}, {-3*r,0.175f,0});
    draw_window(Z_AXIS, {-1}, {0.5*r-3*r,0.175f,0});
    draw_window(Y_AXIS, {1});
    draw_window(Y_AXIS, {1}, {0, 0, 0.5*r});
    draw_window(Y_AXIS, {1}, {0,0.175f,0});
    draw_window(Y_AXIS, {1}, {0,0.175f,0.5*r});
    draw_window(Y_AXIS, {-1});
    draw_window(Y_AXIS, {-1}, {0,0,0.5*r});
    draw_window(Y_AXIS, {-1}, {0,0.175f,0});
    draw_window(Y_AXIS, {-1}, {0,0.175f,0.5*r});
    draw_window(Y_AXIS, {1}, {0, 0, -3*r});
    draw_window(Y_AXIS, {1}, {0,0,0.5*r-3*r});
    draw_window(Y_AXIS, {1}, {0,0.175f,-3*r});
    draw_window(Y_AXIS, {1}, {0,0.175f,0.5*r-3*r});
    draw_window(Y_AXIS, {-1}, {0,0,-3*r});
    draw_window(Y_AXIS, {-1}, {0,0,0.5*r-3*r});
    draw_window(Y_AXIS, {-1}, {0,0.175f,-3*r});
    draw_window(Y_AXIS, {-1}, {0,0.175f,0.5*r-3*r});
    draw_window(SLANT, {1, 1, 1});
    draw_window(SLANT, {-1, -1, -1});
    draw_window(SLANT, {-1, 1, 1});
    draw_window(SLANT, {1, -1, -1});


    //draws an end
    glPushMatrix();
    drawfix();
    glPopMatrix();

}
#endif /* COMPONENT_H */

