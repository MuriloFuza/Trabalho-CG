//
//  draw_shield.cpp
//  test_1_5_nov
//
//  Created by Murilo Fuza da Cunha on 05/11/22.
//

#include "draw_shield.hpp"
#include "glut.hpp"
#include "geometry.hpp"

GLUquadric* sphere_base_shield;

void draw_shield(float angX, float angY, unsigned int texture_base[2], unsigned int texture_esferas_pratas[2]){

    
    sphere_base_shield = gluNewQuadric();

    glTranslatef(angX, angY, 0);
    glPushMatrix();
    
    glScalef(7.0, 7.0, 7.0);

    
    //escudo
    glPushMatrix();
    color( 0.87059f, 0.72157f, 0.52941f);
    glScalef(0.205, 0.205, 0.02);
    glTranslatef(0, 0, -1.2);
    gluQuadricDrawStyle(sphere_base_shield, GLU_FILL);
    glBindTexture(GL_TEXTURE_2D, texture_base[0]);
    gluQuadricTexture(sphere_base_shield, GL_TRUE);
    gluQuadricNormals(sphere_base_shield, GLU_SMOOTH);
    gluSphere(sphere_base_shield, 5, 32, 16);
    glPopMatrix();
    
    //parte de couro para segurar direita olhando de trás o escudo
    glPushMatrix();
    glTranslatef(-0.7, 0, -0.1);
    glRotatef(-90, 1, 0, 0);
    glRotatef(90, 0, 0, 1);
    color( 0.54510f, 0.27059f, 0.07451f);
    drawHalfRings(0.2, 0.2, 0.2, 1);
    glPopMatrix();
    
    //parte de couro para segurar esquerda olhando de trás o escudo
    glPushMatrix();
    glTranslatef(0.7, 0, -0.1);
    glRotatef(-90, 1, 0, 0);
    glRotatef(90, 0, 0, 1);
    color( 0.54510f, 0.27059f, 0.07451f);
    drawHalfRings(0.2, 0.2, 0.2, 1);
    glPopMatrix();
    
    //Anel de aço de volta - parte de cima
    glPushMatrix();
    glTranslatef(0, 0, -0.05);
    glRotatef(90, 1, 0, 0);
    color( 0.45294, 0.43725,0.45020);
    drawRings(1.05,1.05, 0.15, 1);
    glPopMatrix();
    
    //Anel de aço de volta - parte da frente
    glPushMatrix();
    glTranslatef(0, 0, 0.02);
    glRotatef(90, 1, 0, 0);
    color( 0.45294, 0.43725,0.45020);
    drawRings(1.05,0.95, 0.0, 0);
    glPopMatrix();
    
    //Anel de aço de volta - parte de tras
    glPushMatrix();
    glTranslatef(0, 0, -0.02);
    glRotatef(90, 1, 0, 0);
    color( 0.45294, 0.43725,0.45020);
    drawRings(1.05,0.95, 0.0, 0);
    glPopMatrix();

    //bolinhas da parte de aço da frente do escudo
    //cima baixo
    glPushMatrix();
    glTranslatef(0.0, 1, 0.03);
        drawHalfSphere(0.03, texture_esferas_pratas);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0, -1, 0.03);
        drawHalfSphere(0.03, texture_esferas_pratas );
    glPopMatrix();
    
    //esquerda direita
    glPushMatrix();
    glTranslatef(-1, 0, 0.03);
        drawHalfSphere(0.03, texture_esferas_pratas );
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1, 0, 0.03);
        drawHalfSphere(0.03, texture_esferas_pratas );
    glPopMatrix();
    
    //esquerda cima e direita  baixo
    glPushMatrix();
    glTranslatef(0.70, -0.70, 0.03);
        drawHalfSphere(0.03, texture_esferas_pratas );
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.70, 0.70, 0.03);
        drawHalfSphere(0.03, texture_esferas_pratas);
    glPopMatrix();
    
    //esquerda baixo e direita  cima
    glPushMatrix();
    glTranslatef(-0.70, -0.70, 0.03);
        drawHalfSphere(0.03, texture_esferas_pratas);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.70, 0.70, 0.03);
        drawHalfSphere(0.03, texture_esferas_pratas );
    glPopMatrix();
    
    
    
    
    
    //bolinhas do prato do escudo
    glPushMatrix();
    color( 0.45294, 0.43725,0.45020);
    glPushMatrix();
    glTranslatef(0.0, -0.4, 0);
        drawHalfSphere(0.03, texture_esferas_pratas );
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0, 0.4, 0);
        drawHalfSphere(0.03, texture_esferas_pratas );
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.37, -0.2, 0);
        drawHalfSphere(0.03, texture_esferas_pratas );
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.37, 0.2, 0);
        drawHalfSphere(0.03, texture_esferas_pratas );
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.37, -0.2, 0);
        drawHalfSphere(0.03, texture_esferas_pratas);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.37, 0.2, 0);
        drawHalfSphere(0.03, texture_esferas_pratas);
    glPopMatrix();
    
    glPopMatrix();
    
    
    
    //esfera do meio do escudo
    glPushMatrix();
    color( 0.45294, 0.43725,0.45020);
    //glBindTexture(GL_TEXTURE_2D, texture_esferas_pratas[0]);
    drawHalfSphere(0.35, texture_esferas_pratas);
    glPopMatrix();
    
    //prato do escudo
    glPushMatrix();
    color( 0.55, 0.53,0.49);
    glScalef(1, 1, 10);
    drawCircle(0.5, 0, texture_esferas_pratas);
    glPopMatrix();
    
    glPopMatrix();
}
