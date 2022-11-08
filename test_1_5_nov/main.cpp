//
//  main.cpp
//  test_1_5_nov
//
//  Created by Murilo Fuza da Cunha on 05/11/22.
//

#include <iostream>
#include "glut.hpp"
#include "geometry.hpp"
#include "draw_potion.h"
#include "draw_shield.hpp"
#include "draw_sword.hpp"
#include "draw_ward.hpp"

#define y_min 40
#define ro_min 120
float ang = 0;
float eyex = 0, eyey = 100, eyez = 100;
float rotate_global = 0;

#define ALLOW_AXES 1

void display(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    /* Limpa o Buffer de Pixels */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    /* Estabelece a cor da primitiva como preta */
    glColor3f (0.0f, 0.0f, 0.0f);
    
    /* Define a posição do observador */
    gluLookAt(eyex, eyey, eyez, 0, 0, 0, 0, 1, 0);
    
    if(ALLOW_AXES){
            /* Desenhando eixos */

            // Eixo X
            glBegin(GL_LINES);
                glColor3f(1, 0, 0);
                glVertex3f(-100, 0, 0);
                glVertex3f(100, 0, 0);
            glEnd();

            // Eixo Y
            glBegin(GL_LINES);
                glColor3f(0, 1, 0);
                glVertex3f(0, -100, 0);
                glVertex3f(0, 100, 0);
            glEnd();

            // Eixo Z
            glBegin(GL_LINES);
                glColor3f(0, 0, 1);
                glVertex3f(0, 0, -100);
                glVertex3f(0, 0, 100);
            glEnd();
        }
    
    /*
    glPushMatrix();
    draw_pot(ang);
    glPopMatrix();
    */
    
    /*
     glPushMatrix();
     draw_shield(ang);
     glPopMatrix();
     */
    
    glPushMatrix();
    draw_ward(ang);
    glPopMatrix();
    
    /*
    Inicia o processo de desenho atraves dos
    dados bufferizados
    */
    glutSwapBuffers();
}


void TimerFunc(int value) {

    if(rotate_global == 1) ang += 2.0;
    glutPostRedisplay();
    glutTimerFunc( 33, TimerFunc, 1);
}

void reshape(int width, int height) {
    glViewport(0,0,width,height); // Reset The Current Viewport
    
    glMatrixMode(GL_PROJECTION); // Select The Projection Matrix
    glLoadIdentity(); // Reset The Projection Matrix
    
    // Calculate The Aspect Ratio Of The Window
    gluPerspective(45.0f,(float)640/(float)480,0.1f,1000.0f);
    // Always keeps the same aspect as a 640 wide and 480 high window
    
    glMatrixMode(GL_MODELVIEW); // Select The Modelview Matrix
    glLoadIdentity(); // Reset The Modelview Matrix
}

void keyboard (unsigned char key, int x, int y)
{
    //eyex, eyey, eyez
 switch (key) {
 case 'r':
     case 'R':
         rotate_global = 0;
 glutPostRedisplay();
 break;
 case 't':
     case 'T':
         rotate_global = 1;
 glutPostRedisplay();
 break;
 case 'y':
         ang += 1.0;

 glutPostRedisplay();
 break;
 case 'u':
         ang -= 1.0;

 glutPostRedisplay();
 break;
  
     case 27:
         exit(0);
        
 default:
 break;
 }
}



void init() {
    glClearColor(1,1,1,1);
    glClearDepth(1.0); // Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LESS); // The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST); // Enables Depth Testing
    glShadeModel(GL_SMOOTH); // Enables Smooth Color Shading
}

int main(int argc, char** argv)
{
    //Inicia a Telinha
    glutInit(&argc,argv);
    
    /*
    Estabelece o modo de exibicao a ser utilizado pela janela a ser
    neste caso utiliza-se de um buffer duplo, ou seja, a apresentacao
    execucao
    Define o modo de cores como RGBA
    */
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    
    /*
    Determina o tamanho em pixels da
    janela a ser criada
    */
    glutInitWindowSize (800, 800);
    
    /*
    Estabelece a posicao inicial para criacao da
    janela
    */
    glutInitWindowPosition (100, 100);
    
    /*
    Cria uma janela com base nos parametros especificados
    nas funcoes glutInitWindowSize e glutInitWindowPosition
    com o nome de titulo especificado em seu argumento
    */
    glutCreateWindow ("Projeto Base");
    
    /*
    Especifica os parametros inicias para as variaveis
    de estado do OpenGL
    */
    init ();
    
    // Associa a funcao display como uma funcao de callback
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(33, TimerFunc, 1);
    /*
    Inicia a execucao do programa OpenGL.
    O programa ira executar num loop infinito devendo
    o desenvolvedor especificar as condicoes de saida do mesmo
    atraves de interrupcoes no proprio programa ou atraves
    de comandos de mouse ou teclado como funcoes de callback
    */
    glutMainLoop();
    return 0;
}
