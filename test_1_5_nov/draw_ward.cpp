//
//  draw_ward.cpp
//  test_1_5_nov
//
//  Created by Murilo Fuza da Cunha on 08/11/22.
//
#include "draw_ward.hpp"
#include "glut.hpp"
#include "geometry.hpp"
#include "draw_wing.hpp"
#include <iostream>
#define DRAW_WARD_CPP

void draw_ward(float ang){
    GLUquadricObj *quadratic = gluNewQuadric();
    glRotatef(ang, 0, 1, 0);
    glScalef(5.0, 5.0, 5.0);
    
    glPushMatrix();
    
    //asa esquerda
    glPushMatrix();
    glColor3f( 0.81176f, 0.70980f, 0.23137f );
    glTranslatef(0, 1.7, 0);
    glScalef(0.1, 0.1, 0.1);
    glRotatef(180, 0, 1, 0);
    draw_wing(ang);
    glPopMatrix();
    
    //ASA DIREITA
    glPushMatrix();
    glColor3f( 0.81176f, 0.70980f, 0.23137f );
    glTranslatef(0, 1.7, 0);
    glScalef(0.1, 0.1, 0.1);
    draw_wing(ang);
    glPopMatrix();
    
    //joia de cima
    glPushMatrix();
    glTranslatef(0, 4.7, 0);
    glScalef(0.65, 0.65, 0.65);
    color(0, 1, 0);
    glutSolidDodecahedron();
    glPopMatrix();
    
    //base de cima
    glPushMatrix();
    glColor3f( 0.81176f, 0.70980f, 0.23137f );
    glScalef(0.5, 1, 0.5);
    glTranslatef(0, 4.2, 0);
    drawBaseWard();
    glPopMatrix();
    
    //cilindro da estrutura parte de Cima 2
    glPushMatrix();
    glColor3f( 0.36078f, 0.20000f, 0.09020f );
    glTranslatef(0, 3, 0);
    glRotatef(-90, 1, 0, 0);
        gluCylinder(quadratic, 0.8, 1, 1, 8, 8);
    glPopMatrix();
    
    //cilindro da estrutura parte de Cima 1
    glPushMatrix();
    glColor3f( 0.36078f, 0.20000f, 0.09020f );
    glTranslatef(0, 2, 0);
    glRotatef(-90, 1, 0, 0);
        gluCylinder(quadratic, 0.7, 0.8, 1, 8, 8);
    glPopMatrix();
    
    //cilindro da estrutura parte de baixo 2
    glPushMatrix();
    glColor3f( 0.36078f, 0.20000f, 0.09020f );
    glTranslatef(0, 1, 0);
    glRotatef(-90, 1, 0, 0);
        gluCylinder(quadratic, 1, 0.7, 1, 8, 8);
    glPopMatrix();
    
    //cilindro da estrutura parte de baixo 1
    glPushMatrix();
    glColor3f( 0.36078f, 0.20000f, 0.09020f );
    glRotatef(-90, 1, 0, 0);
        gluCylinder(quadratic, 1.5, 1, 1, 8, 8);
    glPopMatrix();
    
    
    //base da ward
    glPushMatrix();
    glColor3f( 0.81176f, 0.70980f, 0.23137f );
    drawBaseWard();
    glPopMatrix();

    glPopMatrix();
}
