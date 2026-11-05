#include <iostream>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Game.h"

using namespace std;

///////////////////////////// CONSTANTS ///////////////////////////////

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int WINDOW_POSITION_X = 300;
const int WINDOW_POSITION_Y = 400;
const char TITLE[] = "Tactic Tanks";
bool fullScreenMode = false;

const GLclampf RED = 0.2;
const GLclampf GREEN = 0.6;
const GLclampf BLUE = 0.5;
const GLclampf ALPHA = 1.0;

///////////////////////////// VARIABLES /////////////////////////////////
 
int width = WINDOW_WIDTH;
int height = WINDOW_HEIGHT;
Game game;

///////////////////////////// AUXILIAR FUNCTIONS /////////////////////

void writeLine(string text) 
{
	cout << text << endl;
}

////////////////////////// OPENGL //////////////////////

void initGraphics() 
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(RED, GREEN, BLUE, ALPHA);
	game.Init();
}

void display() 
{
	GLfloat aspectRatio = ((GLfloat)width / 2) / (GLfloat)height;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width / 2, height);
	gluPerspective(75.0f, aspectRatio, 1.0f, 200.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	game.Render();
		
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(width / 2, 0, width /2, height);
	gluPerspective(75.0f, aspectRatio, 1.0f, 200.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	game.Render();
	glViewport(0, 0, width, height);
	glfwSwapBuffers();
}

void reshape(GLsizei w, GLsizei h) 
{
	if (height == 0) height = 1;
	GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;
	width = w;
	height = h;
	//glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75.0f, aspectRatio, 1.0f, 200.0f);
	glMatrixMode(GL_MODELVIEW);
}

void idle() 
{
	game.Update();
	
}

void keyPressed(unsigned char key, int px, int py) 
{
	game.ProcessKeyPressed(key, px, py);
	
}

void keyUp(unsigned char key, int px, int py)
{
	game.ProcessKeyUp(key, px, py);
	
}

void mouseMoved(int x, int y) 
{
	game.ProcessMouseMovement(x, y);
	
}

void mouseClicked(int button, int state, int x, int y) 
{
	game.ProcessMouseClick(button, state, x, y);
	
}

////////////////////////// MAIN ///////////////////////////////////

void specialKey(int key, int x, int y) 
{
	switch (key)
	{
	case GLUT_KEY_F11:
		fullScreenMode = !fullScreenMode;
		if (fullScreenMode) 
		{
			glutFullScreen();
		}
		else
		{
			glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
			glutPositionWindow(WINDOW_POSITION_X, WINDOW_POSITION_Y);
		} 
		break;
	}
	game.ProcessSpecialKeyPressed(key,x,y);
}

void specialKeyUp(int key, int x, int y) {
	game.ProcessSpecialKeyUp(key, x, y);
}

int main(int argc, char** argv)
{
	writeLine("Hello world con OpenGL");
	writeLine("Generando ventana...");
	glutInit(&argc, argv);											// Inicializa la GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);		// doble buffer, modo RGBA, depth buffer
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);				// tamaño inicial de la ventana
	glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);	// posicion inicial de la ventana
	glutCreateWindow(TITLE);										// crea una ventana con el titulo dado

	writeLine("Registrando funciones de tratamiento de eventos...");
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutSpecialFunc(specialKey);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);
	glutSpecialUpFunc(specialKeyUp);
	glutMotionFunc(mouseMoved);
	//glutPassiveMotionFunc(mouseMoved);
	glutMouseFunc(mouseClicked);
	glutIdleFunc(idle);

	writeLine("Iniciando graficos...");
	initGraphics();

	writeLine("Iniciando bucle infinito...");
	writeLine("Pulse F11 para activar/desactivar el modo pantalla completa.");
	glutMainLoop();
}