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
#include "draw_wing.hpp"

static unsigned char chessboard[64][64][3]; // Storage for chessboard image.

#define y_min 40
#define ro_min 120
float ang = 0;
float eyex = 30, eyey =10, eyez = 100;
float rotate_global = 0;

#define ALLOW_AXES 1

static unsigned int texture[2], texture_cabo[2],
texture_vidro[2], texture_tampa[2],
texture_base[2], texture_esferas[2],
texture_cabo_ward[2], texture_base_ward[2]; // Array of texture indices.

using namespace std;


// Struct of bitmap file.
struct BitMapFile
{
   int sizeX;
   int sizeY;
   unsigned char *data;
};

// Works only for uncompressed bmp files of 24-bit color.
BitMapFile *getBMPData(string filename)
{
   BitMapFile *bmp = new BitMapFile;
   unsigned int size, offset, headerSize;
  
   // Read input file name.
   ifstream infile(filename.c_str(), ios::binary);
 
   // Get the starting point of the image data.
   infile.seekg(10);
   infile.read((char *) &offset, 4);
   
   // Get the header size of the bitmap.
   infile.read((char *) &headerSize,4);

   // Get width and height values in the bitmap header.
   infile.seekg(18);
   infile.read( (char *) &bmp->sizeX, 4);
   infile.read( (char *) &bmp->sizeY, 4);

   // Allocate buffer for the image.
   size = bmp->sizeX * bmp->sizeY * 24;
   bmp->data = new unsigned char[size];

   // Read bitmap data.
   infile.seekg(offset);
   infile.read((char *) bmp->data , size);
   
   // Reverse color from bgr to rgb.
   int temp;
   for (int i = 0; i < size; i += 3)
   {
      temp = bmp->data[i];
      bmp->data[i] = bmp->data[i+2];
      bmp->data[i+2] = temp;
   }
   return bmp;
}

// Load external textures.
void loadExternalTextures()
{
   // Local storage for bmp image data.
    //sword
   BitMapFile *image[1];
    BitMapFile *image_1[1];
    
    //potion
    BitMapFile *image_vidro[1];
    BitMapFile *image_tampa[1];
    
    //shield
    BitMapFile *image_base[1];
    BitMapFile *image_esferas[1];
    
    //ward
    BitMapFile *image_cabo_ward[1];
    BitMapFile *image_base_ward[1];
   
   // image sword
    image[0] = getBMPData("/Users/murilofuzadacunha/Documents/2022.2/Comput_grafica/backup_trab/Trabalho-CG/test_1_5_nov/texturas/sword/lamina.bmp");
    // Load the texture.
    image_1[0] = getBMPData("/Users/murilofuzadacunha/Documents/2022.2/Comput_grafica/backup_trab/Trabalho-CG/test_1_5_nov/texturas/sword/cabo.bmp");
    
    
    //image potion
    
    image_vidro[0] = getBMPData("/Users/murilofuzadacunha/Documents/2022.2/Comput_grafica/backup_trab/Trabalho-CG/test_1_5_nov/texturas/sword/lamina.bmp");
    
    image_tampa[0] = getBMPData("/Users/murilofuzadacunha/Documents/2022.2/Comput_grafica/backup_trab/Trabalho-CG/test_1_5_nov/texturas/potion/rolha.bmp");
    
    // image shield
    image_base[0] = getBMPData("/Users/murilofuzadacunha/Documents/2022.2/Comput_grafica/backup_trab/Trabalho-CG/test_1_5_nov/texturas/sword/cabo.bmp");
    
    image_esferas[0] = getBMPData("/Users/murilofuzadacunha/Documents/2022.2/Comput_grafica/backup_trab/Trabalho-CG/test_1_5_nov/texturas/sword/lamina.bmp");
    
    //ward
    image_cabo_ward[0] = getBMPData("/Users/murilofuzadacunha/Documents/2022.2/Comput_grafica/backup_trab/Trabalho-CG/test_1_5_nov/texturas/sword/cabo.bmp");
    
    image_base_ward[0] = getBMPData("/Users/murilofuzadacunha/Documents/2022.2/Comput_grafica/backup_trab/Trabalho-CG/test_1_5_nov/texturas/ward/base_ward.bmp");
    
    
    //Sword
    
   // Activate texture index texture[0].
   glBindTexture(GL_TEXTURE_2D, texture[0]);
    // Specify an image as the texture to be bound with the currently active texture index.
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[0]->sizeX, image[0]->sizeY, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image[0]->data);
    
    // Set texture parameters for wrapping.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);

    // Set texture parameters for filtering.
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    // Activate texture index texture[0].
    glBindTexture(GL_TEXTURE_2D, texture_cabo[0]);
     // Specify an image as the texture to be bound with the currently active texture index.
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_1[0]->sizeX, image_1[0]->sizeY, 0,
                  GL_RGB, GL_UNSIGNED_BYTE, image_1[0]->data);
     
     // Set texture parameters for wrapping.
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);

     // Set texture parameters for filtering.
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    
    //Potion
    
    // Activate texture index texture[0].
    glBindTexture(GL_TEXTURE_2D, texture_vidro[0]);
     // Specify an image as the texture to be bound with the currently active texture index.
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_vidro[0]->sizeX, image_vidro[0]->sizeY, 0,
                  GL_RGB, GL_UNSIGNED_BYTE, image_vidro[0]->data);
     
     // Set texture parameters for wrapping.
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);

     // Set texture parameters for filtering.
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    
    // Activate texture index texture[0].
    glBindTexture(GL_TEXTURE_2D, texture_tampa[0]);
     // Specify an image as the texture to be bound with the currently active texture index.
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_tampa[0]->sizeX, image_tampa[0]->sizeY, 0,
                  GL_RGB, GL_UNSIGNED_BYTE, image_tampa[0]->data);
     
     // Set texture parameters for wrapping.
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);

     // Set texture parameters for filtering.
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    // shield
    
    glBindTexture(GL_TEXTURE_2D, texture_base[0]);
     // Specify an image as the texture to be bound with the currently active texture index.
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_base[0]->sizeX, image_base[0]->sizeY, 0,
                  GL_RGB, GL_UNSIGNED_BYTE, image_base[0]->data);
     
     // Set texture parameters for wrapping.
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);

     // Set texture parameters for filtering.
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glBindTexture(GL_TEXTURE_2D, texture_esferas[0]);
     // Specify an image as the texture to be bound with the currently active texture index.
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_esferas[0]->sizeX, image_esferas[0]->sizeY, 0,
                  GL_RGB, GL_UNSIGNED_BYTE, image_esferas[0]->data);
     
     // Set texture parameters for wrapping.
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);

     // Set texture parameters for filtering.
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    
    //ward
    
    // Activate texture index texture[0].
    glBindTexture(GL_TEXTURE_2D, texture_cabo_ward[0]);
     // Specify an image as the texture to be bound with the currently active texture index.
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_cabo_ward[0]->sizeX, image_cabo_ward[0]->sizeY, 0,
                  GL_RGB, GL_UNSIGNED_BYTE, image_cabo_ward[0]->data);
     
     // Set texture parameters for wrapping.
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);

     // Set texture parameters for filtering.
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    // Activate texture index texture[0].
    glBindTexture(GL_TEXTURE_2D, texture_base_ward[0]);
     // Specify an image as the texture to be bound with the currently active texture index.
     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image_base_ward[0]->sizeX, image_base_ward[0]->sizeY, 0,
                  GL_RGB, GL_UNSIGNED_BYTE, image_base_ward[0]->data);
     
     // Set texture parameters for wrapping.
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);

     // Set texture parameters for filtering.
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void loadProceduralTextures()
{
    //SWORD
   // Activate texture index texture[1].
   glBindTexture(GL_TEXTURE_2D, texture[1]);
    
    // Activate texture index texture_cabo[1].
    glBindTexture(GL_TEXTURE_2D, texture_cabo[1]);
    
    //Potion
    // Activate texture index texture_cabo[1].
    glBindTexture(GL_TEXTURE_2D, texture_vidro[1]);
    
    // Activate texture index texture_cabo[1].
    glBindTexture(GL_TEXTURE_2D, texture_tampa[1]);
    
    //Shield
    // Activate texture index texture_cabo[1].
    glBindTexture(GL_TEXTURE_2D, texture_base[1]);
    // Activate texture index texture_cabo[1].
    glBindTexture(GL_TEXTURE_2D, texture_esferas[1]);
    
    glBindTexture(GL_TEXTURE_2D, texture_base_ward[1]);
    glBindTexture(GL_TEXTURE_2D, texture_cabo_ward[1]);
    

   // Set texture parameters for wrapping.
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

   // Set texture parameters for filtering.
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

   // Specify an image as the texture to be bound with the currently active texture index.
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 64, 64, 0, GL_RGB, GL_UNSIGNED_BYTE, chessboard);
}

// Create 128 x 128 RGB image of a chessboard.
void createChessboard(void)
{
   int i, j;
   for (i = 0; i < 64; i++)
      for (j = 0; j < 64; j++)
         if ( ( ((i/8)%2) && ((j/8)%2) ) || ( !((i/8)%2) && !((j/8)%2) ) )
         {
            chessboard[i][j][0] = 0x00;
            chessboard[i][j][1] = 0x00;
            chessboard[i][j][2] = 0x00;
         }
         else
         {
            chessboard[i][j][0] = 0xFF;
            chessboard[i][j][1] = 0xFF;
            chessboard[i][j][2] = 0xFF;
         }
}

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
    //draw_pot(ang, texture_vidro, texture_tampa);
    //draw_sword(ang, texture, texture_cabo);
    //draw_shield(ang, texture, texture_esferas);
    draw_ward(ang, texture_cabo_ward, texture_base_ward);
    glPopMatrix();
    
    /*
    Inicia o processo de desenho atraves dos
    dados bufferizados
    */
    glutSwapBuffers();
}


void TimerFunc(int value) {

    if(rotate_global == 1) ang += 1.0;
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
    
    glGenTextures(2, texture);
    glGenTextures(2, texture_cabo);
    glGenTextures(2, texture_vidro);
    glGenTextures(2, texture_tampa);
    glGenTextures(2, texture_base);
    glGenTextures(2, texture_cabo_ward);
    glGenTextures(2, texture_base_ward);
    
    loadExternalTextures();
    createChessboard();
    loadProceduralTextures();
    
    glEnable(GL_TEXTURE_2D);
    // Specify how texture values combine with current surface color values.
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
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
    glutInitWindowSize (2560, 1600);
    
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
