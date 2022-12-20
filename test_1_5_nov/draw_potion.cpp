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
GLUquadric* sphere;



void draw_pot(float angX, float angY, unsigned int texture_vidro[2], unsigned int texture_tampa[2]){
    sphere = gluNewQuadric();
    /* Desenha os planetas com hierarquia*/
    glTranslatef(angX, angY, 0);
    glPushMatrix();
    
    color(0.4 , 0.4, 0.95);
    glRotatef(-90, 1, 0, 0);
    glScalef(7.0, 7.0, 7.0);
    //glutWireSphere( 0.7, 30, 30);
    
    gluQuadricDrawStyle(sphere, GLU_FILL);
    gluQuadricNormals(sphere, GLU_SMOOTH);
    glBindTexture(GL_TEXTURE_2D, texture_vidro[0]);
    gluQuadricTexture(sphere, GL_TRUE);
    gluSphere(sphere, 0.7, 30, 30);
    
    glPushMatrix();
        glTranslatef(0, 0, 0.65);
        glBindTexture(GL_TEXTURE_2D, texture_vidro[0]);
        gluQuadricTexture(quadratic, GL_TRUE);
        gluCylinder(quadratic, 0.3, 0.3, 0.2, 30, 30);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(0, 0, 0.7);
        color(0, 0, 0);
        glBindTexture(GL_TEXTURE_2D, texture_tampa[0]);
        gluQuadricTexture(quadratic, GL_TRUE);
        gluCylinder(quadratic, 0.2, 0.25, 0.2, 30, 30);
    glPopMatrix();
    

    
    
    
    glPopMatrix();
}

#endif
