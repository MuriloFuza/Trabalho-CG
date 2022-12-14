//
//  glut.hpp
//  test_1_5_nov
//
//  Created by Murilo Fuza da Cunha on 05/11/22.
//

#define glut_hpp

#ifndef GLUT_HPP

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <stdlib.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <fstream>

#define GLUT_HPP

void point(GLfloat x, GLfloat y, GLfloat z);

void color(GLfloat r, GLfloat g, GLfloat b);

#endif
