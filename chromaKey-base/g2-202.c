#include <stdio.h>
#include <stdlib.h>
#include <string.h>		// para usar strings
#include <math.h>

#ifdef _WIN32
#include <windows.h>    /* includes only in MSWindows not in UNIX */
#endif

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>     /* OpenGL functions */
#include <GL/glu.h>    /* OpenGL utilitarian functions */
#include <GL/glut.h>
#endif

#include "include/SOIL.h"

typedef struct {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} RGBPixel;

typedef struct {
	int width, height;
	RGBPixel *img;
} Img;


// Funções da interface gráfica e OpenGL

void init();
void draw();
void keyboard(unsigned char key, int x, int y);
void reshape(int w, int h);
void arrow_keys(int a_keys, int x, int y);

int width,height;   // largura e altura da janela

void load(char* name, Img* pic);
void chromaKey(Img* back, Img* front, Img* out, int threshold);
void process();

GLuint tex;

Img back, front, out;

int threshold = 40;

// Carrega uma imagem para a struct Img
void load(char* name, Img* pic)
{
	int chan;
	pic->img = (RGBPixel*) SOIL_load_image(name, &pic->width, &pic->height, &chan, SOIL_LOAD_RGB);
	if(!pic->img)
	{
		printf( "SOIL loading error: '%s'\n", SOIL_last_result() );
		exit(1);
	}
	printf("Load: %d x %d x %d\n", pic->width, pic->height, chan);
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);

	// Define do modo de operacao da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	load(argv[1],&back);
	load(argv[2],&front);
	load(argv[1],&out);

	width = back.width;
	height = back.height;

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(width, height);

	// Cria a janela passando como argumento o titulo da mesma
	glutCreateWindow("G2");

	// Registra a funcao callback de redesenho da janela de visualizacao
	glutDisplayFunc(draw);

	// Registra a funcao callback para tratamento das teclas ASCII
	glutKeyboardFunc (keyboard);

	glutReshapeFunc(reshape);
	glutSpecialFunc(arrow_keys);

	tex = SOIL_create_OGL_texture((unsigned char*)out.img, out.width, out.height, SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, 0);

	// Define a janela de visualizacao 2D
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,width,height,0.0);
	glMatrixMode(GL_MODELVIEW);

	process();

	glutMainLoop();
	return 0;
}

void keyboard(unsigned char key, int x, int y)
{
	char changed=0;

	// ESC termina o programa
	if(key==27) {

		free(back.img);
		free(front.img);
		free(out.img);
		exit(1);
	}
   
	glutPostRedisplay();
}

/*
*
* Função chamada quando a janela precisa ser redesenhada
*
*/

void draw()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // fundo preto
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glColor3ub(255, 255, 255);  // branco

	glBindTexture(GL_TEXTURE_2D, tex);
		glEnable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);

		glTexCoord2f(0,1);
		glVertex2f(0,0);

		glTexCoord2f(1,1);
		glVertex2f(back.width,0);

		glTexCoord2f(1,0);
		glVertex2f(back.width, back.height);

		glTexCoord2f(0,0);
		glVertex2f(0,back.height);

		glEnd();
		glDisable(GL_TEXTURE_2D);

	
	glutSwapBuffers();
}

float DistanciaEntreCores(int r, int g, int b, int mr, int mg, int mb){
	return sqrt(pow(mr - r, 2) + pow(mg - g, 2) + pow(mb - b, 2));
}

void chromaKey(Img* back, Img* front, Img* out, int threshold) {

	RGBPixel (*pixels)[back->width] = (RGBPixel(*)[back->width]) back->img;
	RGBPixel (*mask)[front->width] = (RGBPixel(*)[front->width]) front->img;
	RGBPixel (*pixout)[out->width] = (RGBPixel(*)[out->width]) out->img;

	/////////////////////////////////////////////////////////////////////////
	//
	// Implemente nesta função o algoritmo que executa o merge das imagens,
	//      conforme definido no enunciado do exercício
	//
	// Caso vc julgue necessário, podem ser acrescentadas funções auxiliares
	//     não há motivo algum, no entanto, para que alteres o restante 
	//     do código disponibilizado
	//
	// Seu nome/matrícula aqui: 
	//
	//////////////////////////////////////////////////////////////////////////

	int sub_square = 10; //Lateral do quadrado do qual será pega a média das cores
	int sum_red, sum_green, sum_blue; //Somas das cores (usado para calculo da média)
	int med_red, med_green, med_blue; //Médias das cores

	//Zerando valores
	sum_red = sum_green = sum_blue = 0;
	med_red = med_green = med_blue = 0;

	//Calculando a média da cor de fundo. Analisado o primeiro quadrado no canto superior direito
	for (int h = 0; h < sub_square; h++){
		for (int w = 0; w < sub_square; w++){
			sum_red += mask[h][w].r;
			sum_green += mask[h][w].g;
			sum_blue += mask[h][w].b;			
		}
	}

	//Calculando medias
	med_red = sum_red / (sub_square * sub_square);
	med_green = sum_green / (sub_square * sub_square);
	med_blue = sum_blue / (sub_square * sub_square);

	//Passan por cada pixel
	for (int h = 0; h < front -> height; h++){
		for (int w = 0; w < front -> width; w++){
			if(DistanciaEntreCores(mask[h][w].r, mask[h][w].g, mask[h][w].b, med_red, med_green, med_blue) >= threshold){
				pixout[h][w].r = mask[h][w].r;
				pixout[h][w].g = mask[h][w].g;
				pixout[h][w].b = mask[h][w].b;
			}else{
				pixout[h][w].r = pixels[h][w].r;
				pixout[h][w].g = pixels[h][w].g;
				pixout[h][w].b = pixels[h][w].b;
			}
		}
	}
}

void reshape(int w, int h)
{
	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	gluOrtho2D(0, w, 0, h);

	// Set the clipping volume
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void arrow_keys(int a_keys, int x, int y)
{
	switch(a_keys)
	{
		case GLUT_KEY_RIGHT:
			threshold += 5;
			process();
			glutPostRedisplay();
			break;
	case GLUT_KEY_LEFT:
			threshold -= 5;
			process();
			glutPostRedisplay();
			break;
	default:
			break;
	}
}

// Reconstrói a textura da imagem de saída quando algum parâmetro
// for alterado
void process()
{
	//if(tex == -1)
	//    glGenTextures(1, &tex);
	

	printf("Threshold: %d\n",threshold);
	chromaKey(&back, &front, &out, threshold);

	glBindTexture(GL_TEXTURE_2D, tex);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, out.width, out.height, 0, GL_RGB, GL_UNSIGNED_BYTE, out.img);
}

