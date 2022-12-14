//
//  draw_sword.cpp
//  test_1_5_nov
//
//  Created by Murilo Fuza da Cunha on 05/11/22.
//

#include "draw_sword.hpp"
#include "glut.hpp"
#include "geometry.hpp"

GLUquadric* quadratic_cylinder;

void draw_sword(float ang, unsigned int texture_1[2], unsigned int texture_cabo[2]){
    quadratic_cylinder = gluNewQuadric();
    
    glRotatef(ang, 0, 1, 0);
    glPushMatrix();
    glTranslatef(0, -20, 0);

    glScalef(10.0, 10.0, 10.0);
    //glScalef(25.0, 25.0, 25.0);
    

    //Lamina
    glPushMatrix();
    glColor3f( 0.64314f, 0.63529f, 0.63137f );
    glBindTexture(GL_TEXTURE_2D, texture_1[0]);
    
    glBegin(GL_POLYGON);
    glTexCoord2f(0.5, 0.0); point(0.19, 1.25, 0.02);
    glTexCoord2f(0.5, 0.5); point(0.16, 4, 0.015);
    glTexCoord2f(0.0, 0.5); point(0, 4.4, 0);
    glTexCoord2f(0.0, 0.0); point(0.16, 4, -0.03);
    glTexCoord2f(1.0, 0.0); point(0.19, 1.25, -0.05);
    glTexCoord2f(1.0, 1.0); point(-0.19, 1.25, 0.02);
    glTexCoord2f(0.0, 1.0); point(-0.16, 4, 0.015);
    glTexCoord2f(0.0, 0.0);  point(0, 4.4, 0);
    glTexCoord2f(0.8, 0.0); point(-0.16, 4, -0.03);
    glTexCoord2f(0.8, 0.8);  point(-0.19, 1.25, -0.05);

   
    glEnd();
    glPopMatrix();

    //base da lamina
    glPushMatrix();
    glScalef(1, 1, 0.3);
    glTranslatef(0, 1.28, -0.08);
    glRotatef(90, 1, 0, 0);
    glColor3f( 0.64314f, 0.63529f, 0.63137f );
    glBindTexture(GL_TEXTURE_2D, texture_1[0]);
    drawHalfSphere(0.2, texture_1);

    glPopMatrix();
    

    //cabo
    glPushMatrix();
    
    glPushMatrix();
    glTranslatef(0, 1.6, -0.03);
    glRotatef(270, 0, 0, 1);
    glRotatef(-90, 1, 0, 0);
    glColor3f( 0.11373f, 0.09020f, 0.07451f );
    drawHalfRingsSword(0.5, 0.5, 0.1, 1, texture_cabo);
    glPopMatrix();
    
    //parte de segurar no cabo
    glPushMatrix();
    glTranslatef(0, 0.3, -0.03);
    glRotatef(90, 1, 0, 0);
    glColor3f( 0.27451f, 0.27059f, 0.26275f );
        gluQuadricDrawStyle(quadratic_cylinder, GLU_FILL);
        glBindTexture(GL_TEXTURE_2D, texture_cabo[0]);
        gluQuadricTexture(quadratic_cylinder, GL_TRUE);
        gluQuadricNormals(quadratic_cylinder, GLU_SMOOTH);
        gluCylinder(quadratic_cylinder, 0.08, 0.03, 0.1, 30, 30);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0.3, -0.03);
    glRotatef(-90, 1, 0, 0);
        gluQuadricDrawStyle(quadratic_cylinder, GLU_FILL);
        glBindTexture(GL_TEXTURE_2D, texture_cabo[0]);
        gluQuadricTexture(quadratic_cylinder, GL_TRUE);
        gluQuadricNormals(quadratic_cylinder, GLU_SMOOTH);
    gluCylinder(quadratic_cylinder, 0.08, 0.08, 0.8, 30, 30);
    glPopMatrix();
        
    
    //basezinha do cabo
    glPushMatrix();
    glTranslatef(0, -0.3, -0.03);
    glRotatef(90, 1, 0, 0);
        gluQuadricDrawStyle(quadratic_cylinder, GLU_FILL);
        glBindTexture(GL_TEXTURE_2D, texture_1[0]);
        gluQuadricTexture(quadratic_cylinder, GL_TRUE);
        gluQuadricNormals(quadratic_cylinder, GLU_SMOOTH);
        gluCylinder(quadratic_cylinder, 0.07, 0.03, 0.1, 30, 30);
    glPopMatrix();
    
    //circulos do cabo
    glPushMatrix();
    glTranslatef(0, 0, 0.05);
    glScalef(1, 1, 25);
    drawCircle(0.12, 1, texture_1);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0, 0, -0.05);
    glScalef(1, 1, 25);
    drawCircle(0.12, 1, texture_1);
    glPopMatrix();
    
    glPushMatrix();
    glScalef(1, 1, 25);
    drawCircle(0.3, 1, texture_1);
    glPopMatrix();
    
    glPopMatrix();

    
    glPopMatrix();
}


