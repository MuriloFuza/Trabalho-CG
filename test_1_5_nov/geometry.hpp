//
//  geometry.hpp
//  test_1_5_nov
//
//  Created by Murilo Fuza da Cunha on 05/11/22.
//


#define geometry_hpp

#include <stdio.h>

#ifndef GEOMETRY_H

#define GEOMETRY_H

#define PI 3.1415926535897

float rad(float angle);

void drawCircle(float radius, int solid);

void drawCustomCircle(float startingAngle, float endingAngle, float radius, float spacing, int x, int y, int z, int solid);

void drawHalfSphere(float radius);

void drawSphereSection(float startingTheta, float startingPhi, float endingTheta, float endingPhi, float radius, float space, int solid);

void drawRings(float radius_top, float radius_bottom, float gap, int solid);

void drawRing(float radius);

void drawHalfRings(float radius_top, float radius_bottom, float gap, int solid);

void drawHalfRingsSword(float radius_top, float radius_bottom, float gap, int solid);

void drawBaseWard();

void drawWing(int factor, int numPoints);

#endif
