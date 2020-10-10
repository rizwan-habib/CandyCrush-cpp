//============================================================================
// Name        : .cpp
// Author      : Rizwan Janjua
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include "gameScene.h"
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
/*
 * Main Canvas drawing function.
 * */
gameScene gam;
void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.
	gam.MenuDisplay();
	gam.levels();
	gam.levelModes();
	gam.instruction();
	gam.name();
	gam.GameOver();
	gam.Pause();

	gam.DisplayHighscore();
if(gam.getMenuOption()==10){
	glClearColor(0/*Red Component*/,0 ,	//148.0/255/*Green Component*/,
			0/*Blue Component*/, 0 /*Alpha component*/); //#include <GL/gl.h>
// Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	gam.CandiesGenerator();
	DrawLine(135,135,135,705,5,colors[WHITE]);
	DrawLine(135,135,705,135,5,colors[WHITE]);
	DrawLine(705,135,705,705,5,colors[WHITE]);
	DrawLine(135,705,705,705,5,colors[WHITE]);
	gam.isMatching();
	gam.newCandiesGenerator();
	glutSwapBuffers(); // do not modify this line..
}
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
	} else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	static bool hs=0;
	if (gam.getMenuOption()==0 || gam.getMenuOption()==6) {
		if (key=='1') {
			gam.setMenuOption(10);
		}
		if (key=='2') {
			gam.setMenuOption(2);
		}
		if (key=='3') {
			gam.setMenuOption(3);
		}
		if (key=='4') {
			hs=1;
			gam.setMenuOption(4);
		}
		if (key=='5') {
			hs=1;
			gam.setMenuOption(5);
		}
		if (key=='6') {
			exit(1);
		}
	}

	else if( gam.getMenuOption()==5 || gam.getMenuOption()==4){
		if (key=='1') {
			if(hs==1){
				gam.setMenuOption(0);
			}
			else{
				gam.setMenuOption(7);
			}
		}
	}
	else if (gam.getMenuOption()==2) {
		if (key=='1') {
			gam.setLevel(1);
		}
		if (key=='2') {
			gam.setLevel(2);
		}
		if (key=='3') {
			gam.setLevel(3);
		}
		if (key=='4') {
			gam.setLevel(4);
		}
		if (key=='5') {
			gam.setLevel(5);
		}
		if (key=='6') {
			gam.setMenuOption(0);
		}
	}
	else if (gam.getMenuOption()==6) {
		if (key=='1') {
			gam.Restart();
			gam.setMenuOption(10);
		}
		if (key=='2') {
			gam.setMenuOption(2);
		}
		if (key=='3') {
			gam.setMenuOption(3);
		}
		if (key=='4') {
			gam.setMenuOption(4);
		}
		if (key=='5') {
			gam.setMenuOption(5);
		}
		if (key=='6') {
			exit(1);
		}
	}
	else if (gam.getMenuOption()==7) {
		hs=0;
		if (key=='1') {
			gam.setMenuOption(10);
		}
		if (key=='2') {
			gam.Restart();
			gam.setMenuOption(0);
		}
		if (key=='3') {
			gam.setMenuOption(4);
		}
		if (key=='4') {
			gam.setMenuOption(5);
		}
		if (key=='5') {
			exit(1);
		}
		if (key=='6') {
			gam.setMenuOption(5);
		}
		if (key=='7') {
			exit(1);
		}
	}
	else if (gam.getMenuOption()==10) {
		if(key=='p'|| key=='P'){
			gam.setMenuOption(7);
		}
	}
	else if(gam.getMenuOption()==3){
		if(key=='1'){
			gam.setOption(0);
		}
		if(key=='2'){
			gam.setOption(1);
		}
		if (key=='3') {
			gam.setMenuOption(0);
		}
	}
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constan//#include <GL/gl.h>
 * t FPS.
 *
 * */
//int timee=120;
void Timer(int m) {
	// implement your functionality here
	if(gam.getOption()==1 && gam.getMenuOption()==10){
		gam.TimeMode();
		gam.HighScore();
		glutPostRedisplay();
	}
	// once again we tell the library to call our Timer function after next 1000/FPS
		glutTimerFunc(1000, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {

	glutPostRedisplay();

}
void MouseMoved(int x, int y) {
//	cout << x << " " << y << endl;
//	y=800-(y*800/655);
//	DrawSquare(x,y,5,colors[RED]);

	glutPostRedisplay();
//	glutSwapBuffers();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	static int sx_1=0,sy_1=0,sx_2=0,sy_2=0;
	y=800-(y*800/655);
//	cout << x << " " <<y << endl;

		if (button == GLUT_LEFT_BUTTON) // dealing only with left button
		{

			if (state == GLUT_DOWN )
			{
				sx_1=0;
				sy_1=0;
				sx_2=0;
				sy_2=0;

				sx_1=x/70;
				sy_1=y/70;


			}
			if (state == GLUT_UP)
			{
				sx_2=x/70;
				sy_2=y/70;
				gam.Swap(sx_1,sy_1,sx_2,sy_2);
			}
	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 800, height = 800; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Candy Crush"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ *///#include <GL/gl.h>
