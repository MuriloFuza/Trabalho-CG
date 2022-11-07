//
//  draw_sword.cpp
//  test_1_5_nov
//
//  Created by Murilo Fuza da Cunha on 05/11/22.
//

#include "draw_sword.hpp"
#include "glut.hpp"
#include "geometry.hpp"


void draw_sword(float ang){
    GLUquadricObj *quadratic = gluNewQuadric();
    
    glRotatef(ang, 0, 1, 0);
    glPushMatrix();
    glTranslatef(0, -20, 0);

    glScalef(12.0, 12.0, 12.0);
    //glScalef(25.0, 25.0, 25.0);
    

    //Lamina
    glPushMatrix();
    glColor3f( 0.64314f, 0.63529f, 0.63137f );
    glBegin(GL_POLYGON);
    point(0.19, 1.25, 0.02);
    point(0.16, 4, 0.015);
    
    point(0, 4.4, 0);
    
    point(0.16, 4, -0.03);
    point(0.19, 1.25, -0.05);
    
    point(-0.19, 1.25, 0.02);
    point(-0.16, 4, 0.015);
    
    point(0, 4.4, 0);
    
    point(-0.16, 4, -0.03);
    point(-0.19, 1.25, -0.05);
    //subindo de volta

   
    glEnd();
    glPopMatrix();
    
    //base da lamina
    glPushMatrix();
    glScalef(1, 1, 0.3);
    glTranslatef(0, 1.28, -0.08);
    glRotatef(90, 1, 0, 0);
    glColor3f( 0.64314f, 0.63529f, 0.63137f );
    drawHalfSphere(0.2);
    glPopMatrix();
    
    
    //cabo
    glPushMatrix();
    
    glPushMatrix();
    glTranslatef(0, 1.6, -0.03);
    glRotatef(270, 0, 0, 1);
    glRotatef(-90, 1, 0, 0);
    glColor3f( 0.11373f, 0.09020f, 0.07451f );
    drawHalfRingsSword(0.5, 0.5, 0.1, 1);
    glPopMatrix();
    
    //parte de segurar no cabo
    glPushMatrix();
    glTranslatef(0, 0.3, -0.03);
    glRotatef(90, 1, 0, 0);
    glColor3f( 0.27451f, 0.27059f, 0.26275f );
        gluCylinder(quadratic, 0.08, 0.03, 0.1, 30, 30);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0.3, -0.03);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(quadratic, 0.08, 0.08, 0.8, 30, 30);
    glPopMatrix();
        
    
    //basezinha do cabo
    glPushMatrix();
    glTranslatef(0, -0.3, -0.03);
    glRotatef(90, 1, 0, 0);
        gluCylinder(quadratic, 0.07, 0.03, 0.1, 30, 30);
    glPopMatrix();
    
    //circulos do cabo
    glPushMatrix();
    glTranslatef(0, 0, 0.05);
    glScalef(1, 1, 25);
    glColor3f( 0.38431f, 0.36078f, 0.35686f );
    drawCircle(0.12, 1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0, -0.05);
    glScalef(1, 1, 25);
    glColor3f( 0.38431f, 0.36078f, 0.35686f );
    drawCircle(0.12, 1);
    glPopMatrix();
    
    glPushMatrix();
    glScalef(1, 1, 25);
    glColor3f( 0.12549f, 0.10588f, 0.09020f );
    drawCircle(0.3, 0);
    glPopMatrix();
    
    glPopMatrix();

    
    glPopMatrix();
}
