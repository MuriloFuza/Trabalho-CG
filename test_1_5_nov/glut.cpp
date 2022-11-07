//
//  glut.cpp
//  test_1_5_nov
//
//  Created by Murilo Fuza da Cunha on 05/11/22.
//

#include "glut.hpp"
#ifndef GLUT_CPP

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <stdlib.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>

#define GLUT_CPP

void point(GLfloat x, GLfloat y, GLfloat z) {
    glVertex3f(x, y, z);
}

void color(GLfloat r, GLfloat g, GLfloat b) {
    glColor3f(r, g, b);
}

#endif
