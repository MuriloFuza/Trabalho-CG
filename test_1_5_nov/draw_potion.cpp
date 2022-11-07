//
//  draw_potion.cpp
//  test_1_5_nov
//
//  Created by Murilo Fuza da Cunha on 05/11/22.
//
#ifndef DRAW_POTION_CPP
#include "glut.hpp"
#include "geometry.hpp"
#include <iostream>
#define DRAW_POTION_CPP

GLUquadricObj *quadratic = gluNewQuadric();

void draw_pot(float ang){
    /* Desenha os planetas com hierarquia*/
    glRotatef(ang, 0, 1, 0);
    glPushMatrix();
    
    color(0.4 , 0.4, 0.95);
    glRotatef(-90, 1, 0, 0);
    glScalef(15.0, 15.0, 15.0);
    glutWireSphere(0.7, 30, 30);
    
    glPushMatrix();
        glTranslatef(0, 0, 0.65);
        gluCylinder(quadratic, 0.3, 0.3, 0.2, 30, 30);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(0, 0, 0.7);
    color(0, 0, 0);
        gluCylinder(quadratic, 0.2, 0.25, 0.2, 30, 30);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0, 0.75);
    glRotatef(90, 1, 0, 0);
    drawRings(0.32, 0.32, 0.05, 0);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0, 0.3);
    glRotatef(90, 1, 0, 0);
    drawRings(0.6, 0.7, 0.15, 0);
    glPopMatrix();
    
    
    
    glPopMatrix();
}

#endif
