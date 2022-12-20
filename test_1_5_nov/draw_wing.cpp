//
//  draw_wing.cpp
//  test_1_5_nov
//
//  Created by Murilo Fuza da Cunha on 08/11/22.
//

#include "draw_wing.hpp"
#include "glut.hpp"
#include "geometry.hpp"
#include <iostream>

void draw_wing(float ang, unsigned int texture_int[2]){
    glRotatef(ang, 0, 1, 0);
    glScalef(7.0, 7.0, 7.0);
    glTranslatef(0, 0, 4);
    
    glPushMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0, -4.9);
    glBindTexture(GL_TEXTURE_2D, texture_int[0]);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.5, 0.0);point(9, 3.3, -0.37);
    glTexCoord2f(0.5, 0.0);point(8.5, 2.3, -0.3);
    glTexCoord2f(0.5, 0.0);point(7, 1, -0.2);
    glTexCoord2f(0.5, 0.0);point(5, 0, -0.05);
    glTexCoord2f(0.5, 0.0);point(7, 1, 0.08);
    glTexCoord2f(0.5, 0.0);point(8.5, 2.3, 0.18);
    glTexCoord2f(0.5, 0.0);point(9, 3.3, 0.25);
    glEnd();
    glPopMatrix();
    
    //conexão das asas - parte de cima
    glPushMatrix();
    glTranslatef(0, 0, -4.9);
    glBindTexture(GL_TEXTURE_2D, texture_int[0]);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.5, 0.5);point(0, 1, 0.05);
    glTexCoord2f(0.5, 0.5);point(0, 1, -0.18);
    
    //subindo por z negativo
    glTexCoord2f(0.5, 0.5);point(2, 1.5, -0.25);
    glTexCoord2f(0.5, 0.5);point(3.5, 2, -0.28);
    glTexCoord2f(0.5, 0.5);point(5, 2, -0.29);
    glTexCoord2f(0.5, 0.5);point(7, 2.3, -0.31);
    glTexCoord2f(0.5, 0.5);point(9, 3.3, -0.37);
    
    glTexCoord2f(0.5, 0.5);point(9, 3.3, 0.25);
    glTexCoord2f(0.5, 0.5);point(7, 2.3, 0.2);
    glTexCoord2f(0.5, 0.5);point(5, 2, 0.16);
    glTexCoord2f(0.5, 0.5);point(3.5, 2, 0.14);
    glTexCoord2f(0.5, 0.5);point(2, 1.5, 0.12);
    
    glEnd();
    glPopMatrix();

    
    //asa direita
    glPushMatrix();
    glTranslatef(0, 0, -4.95);
    glRotatef(5, 1, 0, 0);
    glBindTexture(GL_TEXTURE_2D, texture_int[0]);
    glBegin(GL_POLYGON);
    
    //base
    glTexCoord2f(1.0, 0.5);point(0, 0, 0);
    glTexCoord2f(1.0, 0.5);point(0, 1, 0);
    
    //seguindo para cima
    glTexCoord2f(1.0, 0.5);point(2, 1.5, 0);
    glTexCoord2f(1.0, 0.5);point(3.5, 2, 0);
    glTexCoord2f(1.0, 0.5);point(5, 2, 0);
    glTexCoord2f(1.0, 0.5);point(7, 2.3, 0);
    glTexCoord2f(1.0, 0.5); point(9, 3.3, 0);

    //descendo
    glTexCoord2f(1.0, 0.5);point(8.5, 2.3, 0);
    glTexCoord2f(1.0, 0.5);point(7, 1, 0);
    glTexCoord2f(1.0, 0.5);point(5, 0, 0);
    glTexCoord2f(1.0, 0.5);point(3.8, -0.5, 0);
    glTexCoord2f(1.0, 0.5);point(3, -0.2, 0);
    glTexCoord2f(1.0, 0.5);point(2.5, -0.1, 0);
    
    //voltou pra base 2d
    glTexCoord2f(1.0, 0.5);point(0, 0, 0);
    glEnd();
    glPopMatrix();
    
    //asa esquerda
    glPushMatrix();
    glTranslatef(0, 0, -5);
    glRotatef(-5, 1, 0, 0);
    glBindTexture(GL_TEXTURE_2D, texture_int[0]);
    glBegin(GL_POLYGON);
    
    //base
    glTexCoord2f(1.0, 1.0);point(0, 0, 0);
    glTexCoord2f(1.0, 1.0);point(0, 1, 0);
    
    //seguindo para cima
    glTexCoord2f(1.0, 1.0);point(2, 1.5, 0);
    glTexCoord2f(1.0, 1.0);point(3.5, 2, 0);
    glTexCoord2f(1.0, 1.0);point(5, 2, 0);
    glTexCoord2f(1.0, 1.0);point(7, 2.3, 0);
    glTexCoord2f(1.0, 1.0);point(9, 3.3, 0);

    //descendo
    glTexCoord2f(1.0, 1.0);point(8.5, 2.3, 0);
    glTexCoord2f(1.0, 1.0);point(7, 1, 0);
    glTexCoord2f(1.0, 1.0);point(5, 0, 0);
    glTexCoord2f(1.0, 1.0);point(3.8, -0.5, 0);
    glTexCoord2f(1.0, 1.0);point(3, -0.2, 0);
    glTexCoord2f(1.0, 1.0);point(2.5, -0.1, 0);
    
    //voltou pra base 2d
    glTexCoord2f(1.0, 1.0);point(0, 0, 0);
    glEnd();
    glPopMatrix();
    
    glPopMatrix();
}
