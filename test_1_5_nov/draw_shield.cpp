//
//  draw_shield.cpp
//  test_1_5_nov
//
//  Created by Murilo Fuza da Cunha on 05/11/22.
//

#include "draw_shield.hpp"
#include "glut.hpp"
#include "geometry.hpp"

void draw_shield(float ang){

    glRotatef(ang, 0, 1, 0);
    glPushMatrix();
    
    glScalef(25.0, 25.0, 25.0);

    

    
    //escudo
    glPushMatrix();
    color( 0.87059f, 0.72157f, 0.52941f);
    glScalef(1, 1, 30);
    drawCircle(1.0, 1);
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
        drawHalfSphere(0.03);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0, -1, 0.03);
        drawHalfSphere(0.03);
    glPopMatrix();
    
    //esquerda direita
    glPushMatrix();
    glTranslatef(-1, 0, 0.03);
        drawHalfSphere(0.03);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1, 0, 0.03);
        drawHalfSphere(0.03);
    glPopMatrix();
    
    //esquerda cima e direita  baixo
    glPushMatrix();
    glTranslatef(0.70, -0.70, 0.03);
        drawHalfSphere(0.03);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.70, 0.70, 0.03);
        drawHalfSphere(0.03);
    glPopMatrix();
    
    //esquerda baixo e direita  cima
    glPushMatrix();
    glTranslatef(-0.70, -0.70, 0.03);
        drawHalfSphere(0.03);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.70, 0.70, 0.03);
        drawHalfSphere(0.03);
    glPopMatrix();
    
    
    
    
    
    //bolinhas do prato do escudo
    glPushMatrix();
    color( 0.45294, 0.43725,0.45020);
    glPushMatrix();
    glTranslatef(0.0, -0.4, 0);
        drawHalfSphere(0.03);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.0, 0.4, 0);
        drawHalfSphere(0.03);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.37, -0.2, 0);
        drawHalfSphere(0.03);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.37, 0.2, 0);
        drawHalfSphere(0.03);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-0.37, -0.2, 0);
        drawHalfSphere(0.03);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.37, 0.2, 0);
        drawHalfSphere(0.03);
    glPopMatrix();
    
    glPopMatrix();
    
    
    
    //esfera do meio do escudo
    glPushMatrix();
    color( 0.45294, 0.43725,0.45020);
    drawHalfSphere(0.35);
    glPopMatrix();
    
    //prato do escudo
    glPushMatrix();
    color( 0.55, 0.53,0.49);
    glScalef(1, 1, 10);
    drawCircle(0.5, 0);
    glPopMatrix();
    
    glPopMatrix();
}
