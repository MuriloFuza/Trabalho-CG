//
//  draw_ward.cpp
//  test_1_5_nov
//
//  Created by Murilo Fuza da Cunha on 08/11/22.
//
#include "draw_ward.hpp"
#include "glut.hpp"
#include "geometry.hpp"
#include <iostream>
#define DRAW_WARD_CPP

void draw_ward(float ang){
    GLUquadricObj *quadratic = gluNewQuadric();
    glRotatef(ang, 0, 1, 0);
    glScalef(5.0, 5.0, 5.0);
    
    glPushMatrix();
    
    //base de cima
    glPushMatrix();
    glScalef(0.5, 1, 0.5);
    glTranslatef(0, 4.2, 0);
    drawBaseWard();
    glPopMatrix();
    
    //cilindro da estrutura parte de Cima 2
    glPushMatrix();
    glTranslatef(0, 3, 0);
    glRotatef(-90, 1, 0, 0);
        gluCylinder(quadratic, 0.8, 1, 1, 8, 8);
    glPopMatrix();
    
    //cilindro da estrutura parte de Cima 1
    glPushMatrix();
    glTranslatef(0, 2, 0);
    glRotatef(-90, 1, 0, 0);
        gluCylinder(quadratic, 0.7, 0.8, 1, 8, 8);
    glPopMatrix();
    
    //cilindro da estrutura parte de baixo 2
    glPushMatrix();
    glTranslatef(0, 1, 0);
    glRotatef(-90, 1, 0, 0);
        gluCylinder(quadratic, 1, 0.7, 1, 8, 8);
    glPopMatrix();
    
    //cilindro da estrutura parte de baixo 1
    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
        gluCylinder(quadratic, 1.5, 1, 1, 8, 8);
    glPopMatrix();
    
    
    //base da ward
    glPushMatrix();
    drawBaseWard();
    glPopMatrix();

    glPopMatrix();
}
