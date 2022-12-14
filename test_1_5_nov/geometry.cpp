//
//  geometry.cpp
//  test_1_5_nov
//
//  Created by Murilo Fuza da Cunha on 05/11/22.
//

#include "geometry.hpp"
#include "glut.hpp"
#ifndef GEOMETRY_CPP

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <stdlib.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <math.h>

#define GEOMETRY_CPP

#define PI 3.1415926535897

float rad(float angle) {
    return (angle / 180) * PI;
}

void drawCircle(float radius, int solid,  unsigned int texture[2]) {
    float twoPI = 2 * PI;

        // GL_TRIANGLE_FAN | GL_POINTS
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(!solid ? GL_POINTS : GL_TRIANGLE_FAN);
        for (float i = 0.0; i <= twoPI; i += 0.001){
            glTexCoord2f((sin(i)*radius), (cos(i)*radius)); point((sin(i)*radius), (cos(i)*radius), 0);
            glTexCoord2f((sin(i)*radius), (cos(i)*radius)); point((sin(i)*radius), (cos(i)*radius), -0.003);
            }
    glEnd();
}

void drawCustomCircle(float startingAngle, float endingAngle, float radius, float spacing, int x, int y, int z, int solid) {
    // Must be in pairs of axes
    if(!(x & y) && !(x & z) && !(y & z)) return;

    // Must be in pairs of axes
    if(x & y & z) return;
    
    if(startingAngle > endingAngle) {
        float temp = startingAngle;
        startingAngle = endingAngle;
        endingAngle = temp;
        spacing *= -1;
    }

    // GL_TRIANGLE_FAN | GL_POINTS
  glBegin(!solid ? GL_POINTS : GL_TRIANGLE_FAN);
    for (float i = startingAngle; i <= endingAngle; i += spacing){
        if(x & y) point(sin(i/180 * PI) * radius, cos(i/180 * PI) * radius, 0);
        if(x & z) point(sin(i/180 * PI) * radius, 0, cos(i/180 * PI) * radius);
        if(y & z) point(0, sin(i/180 * PI) * radius, cos(i/180 * PI) * radius);
        }
  glEnd();
}

void drawHalfSphere(float radius, unsigned int textura[2]) {
    float space = 1;
    float x, y, z;
    
    //GL_POINTS | GL_TRIANGLE_FAN
    glBindTexture(GL_TEXTURE_2D, textura[0]);
    glBegin(GL_POINTS);
        for (float theta = 0; theta <= 90 - space; theta += space) {
            
            for (float phi = 0; phi <= 360 - space; phi += space) {
                x = radius * sin(phi/180 * PI) * sin(theta/180 * PI);
                y = radius * cos(phi/180 * PI) * sin(theta/180 * PI);
                z = radius * cos(theta/180 * PI);
                glTexCoord2f(x, y);
                point(x, y, z);
            }
        }
    glEnd();
}

void drawSphereSection(float startingTheta, float startingPhi, float endingTheta, float endingPhi, float radius, float space, int solid) {
    float x, y, z;
    
    //GL_POINTS | GL_TRIANGLE_FAN
    glBegin(!solid ? GL_POINTS : GL_TRIANGLE_FAN);
        for (float theta = startingTheta; theta <= endingTheta; theta += space) {
            for (float phi = startingPhi; phi <= endingPhi; phi += space) {
                x = radius * sin(phi/180 * PI) * sin(theta/180 * PI);
                y = radius * cos(phi/180 * PI) * sin(theta/180 * PI);
                z = radius * cos(theta/180 * PI);
                point(x, y, z);
            }
        }
    glEnd();
}

void drawRings(float radius_top, float radius_bottom, float gap, int solid) {
    float twoPI = 2 * PI;
    
    //GL_POINTS | GL_TRIANGLE_FAN
    glBegin(!solid ? GL_POINTS : GL_LINES);
        for (float i = 0.0; i <= twoPI; i += 0.001){
        point((sin(i)*radius_top), gap/2, (cos(i)*radius_top));
        point((sin(i)*radius_bottom), -gap/2, (cos(i)*radius_bottom));
        }
    glEnd();
}

void drawHalfRings(float radius_top, float radius_bottom, float gap, int solid) {
    float twoPI = 2 * PI;
    
    //GL_POINTS | GL_TRIANGLE_FAN
    glBegin(!solid ? GL_POINTS : GL_LINES);
    for (float i = 0.0; i <= twoPI / 2; i += 0.001){
        point( (sin(i)*radius_top), gap/2,(cos(i)*radius_top) );
        point((sin(i)*radius_top), -gap/2, (cos(i)*radius_top));
    }
    glEnd();
}

void drawHalfRingsSword(float radius_top, float radius_bottom, float gap, int solid, unsigned int texture[2]) {
    
    //GL_POINTS | GL_TRIANGLE_FAN
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(!solid ? GL_POINTS : GL_LINES);
    for (float i = 30; i <= 150; i += 0.001){
        glTexCoord2f((sin(rad(i))*radius_top),(cos(rad(i))*radius_top));    point((sin(rad(i))*radius_top), gap/2,(cos(rad(i))*radius_top) );
        glTexCoord2f((sin(rad(i))*radius_top),(cos(rad(i))*radius_top));   point((sin(rad(i))*radius_top), -gap/2, (cos(rad(i))*radius_top));
    }
    glEnd();
}

void drawRing(float radius) {
    float twoPI = 2 * PI;
    
    //GL_POINTS | GL_TRIANGLE_FAN
    glBegin(GL_POINTS);
        for (float i = 0.0; i <= twoPI; i += 0.001){
        point((sin(i)*radius), 0, (cos(i)*radius));
        }
    glEnd();
}

void drawBaseWard(unsigned int texture[2]){
    
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_POLYGON);
    glTexCoord2f(1.0, 0.0);    point(2, 0, 0);
    point(1.5, 0, 1.5);
    point(0, 0, 2);
    point(-1.5, 0, 1.5);
    point(-2, 0, 0);
    point(-1.5, 0, -1.5);
    point(0, 0, -2);
    point(1.5, 0, -1.5);
    //desceu
    glTexCoord2f(0.0, 1.0); point(1.5, -0.2, -1.5);
    
    point(0, -0.2, -2);
    point(0, 0, -2);
    point(0, -0.2, -2);
    
    point(-1.5, -0.2, -1.5);
    point(-1.5, 0, -1.5);
    point(-1.5, -0.2, -1.5);
    
    glTexCoord2f(1.0, 1.0); point(-2, -0.2, 0);
    point(-2, 0, 0);
    point(-2, -0.2, 0);
    
    point(-1.5, -0.2, 1.5);
    point(-1.5, 0, 1.5);
    point(-1.5, -0.2, 1.5);
    
    glTexCoord2f(0.0, 0.0); point(0, -0.2, 2);
    point(0, 0, 2);
    point(0, -0.2, 2);
    
    point(1.5, -0.2, 1.5);
    point(1.5, 0, 1.5);
    point(1.5, -0.2, 1.5);
    
    point(2, -0.2, 0);
    point(2, 0, 0);
    point(2, -0.2, 0);
    
    point(1.5, -0.2, -1.5);
    point(1.5, 0, -1.5);
    
    glEnd();
    glPopMatrix();
}

void drawWing(int factor, int numPoints) {
    // GL_POINTS | GL_TRIANGLE_FAN
    glBegin(GL_TRIANGLE_FAN);
        for(int i = 0, j = numPoints; i < numPoints; i++, j--) {
            point(0.1 * i, 0.005 * i * i, 0.02 * i * factor);
        }
    glEnd();
}

#endif
