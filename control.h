#ifndef CONTROL_H
#define CONTROL_H

static float lightAngle = 0.0, lightHeight = 20;
GLfloat angle = -150;
GLfloat angle2 = 30;

int moving, startx, starty;
int lightMoving = 0, lightStartX, lightStartY;


static void mouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving =0.0;
        }
    }
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            lightMoving = 1;
            lightStartX = x;
            lightStartY = y;
        }
        if (state == GLUT_UP) {
            lightMoving = 0.0;
        }
    }
}

static void motion(int x, int y)
{
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
    if (lightMoving) {
        lightAngle += (x - lightStartX)/40.0;
        lightHeight += (lightStartY - y)/20.0;
        lightStartX = x;
        lightStartY = y;
        glutPostRedisplay();
    }
}

static void idle(void)
{
    if (!lightMoving) {
        lightAngle += 0.02;
    }
    glutPostRedisplay();
}

#endif
