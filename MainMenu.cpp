/*
 * MainMenu.cpp
 *
 *  Created on: May 23, 2020
 *      Author: rizwan
 */

#include "MainMenu.h"
#include "util.h"
MainMenu::MainMenu()/*:level()*/ {
	// TODO Auto-generated constructor stub
	MenuOption=0;
	for(int i=0;i<4;i++){
		x[i]=0;
	}
}
void MainMenu::TimeMode(){
	l.TimeMode();
}
int MainMenu::getOption(){
	return l.getOption();
}
MainMenu::MainMenu(int m){
	MenuOption=m;
	for(int i=0;i<4;i++){
		x[i]=0;
	}
}
void MainMenu::setMenuOption(int o){
	MenuOption=o;
}
int MainMenu::getmoves(){
	return l.getMoves();
}
int MainMenu::getMenuOption(){
	return MenuOption;
}
void MainMenu::MenuDisplay(){
	if(MenuOption==0){
		glClearColor(0/*Red Component*/,0 ,	//148.0/255/*Green Component*/,
				0/*Blue Component*/, 0 /*Alpha component*/); //#include <GL/gl.h>
		// Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		DrawString(230,100,"Press the mentioned number to Enter" , colors[RED]);

		DrawLine(100,705,135,705,5,colors[WHITE]);
		DrawLine(100,705,100,650,5,colors[WHITE]);
		DrawLine(100,650,135,650,5,colors[WHITE]);
		DrawLine(135,675,135,650,5,colors[WHITE]);

		DrawLine(160,705,160,650,5,colors[WHITE]);
		DrawLine(160,705,195,705,5,colors[WHITE]);
		DrawLine(160,675,195,675,5,colors[WHITE]);
		DrawLine(160,650,195,650,5,colors[WHITE]);

		DrawLine(220,705,220,650,5,colors[WHITE]);
		DrawLine(220,705,245,670,5,colors[WHITE]);
		DrawLine(270,705,245,670,5,colors[WHITE]);
		DrawLine(270,705,270,650,5,colors[WHITE]);

		DrawLine(295,705,345,705,5,colors[WHITE]);
		DrawLine(295,675,345,675,5,colors[WHITE]);
		DrawLine(295,705,295,675,5,colors[WHITE]);
		DrawLine(345,650,345,675,5,colors[WHITE]);
		DrawLine(295,650,345,650,5,colors[WHITE]);


		DrawLine(380,705,420,705,5,colors[WHITE]);
		DrawLine(380,705,380,650,5,colors[WHITE]);
		DrawLine(380,650,420,650,5,colors[WHITE]);

		DrawLine(445,705,445,650,5,colors[WHITE]);
		DrawLine(445,705,485,705,5,colors[WHITE]);
		DrawLine(445,675,485,675,5,colors[WHITE]);
		DrawLine(485,705,485,675,5,colors[WHITE]);
		DrawLine(465,675,485,650,5,colors[WHITE]);

		DrawLine(510,705,510,650,5,colors[WHITE]);
		DrawLine(510,650,550,650,5,colors[WHITE]);
		DrawLine(550,705,550,650,5,colors[WHITE]);

		DrawLine(575,705,625,705,5,colors[WHITE]);
		DrawLine(575,675,625,675,5,colors[WHITE]);
		DrawLine(575,705,575,675,5,colors[WHITE]);
		DrawLine(625,650,625,675,5,colors[WHITE]);
		DrawLine(575,650,625,650,5,colors[WHITE]);

		DrawLine(650,705,650,650,5,colors[WHITE]);
		DrawLine(650,675,690,675,5,colors[WHITE]);
		DrawLine(690,705,690,650,5,colors[WHITE]);

		DrawString( 350, 550, "1.Start New Game", colors[MISTY_ROSE]);
		DrawString( 350, 500, "2.Levels", colors[MISTY_ROSE]);
		DrawString( 350, 450, "3.Level Modes", colors[MISTY_ROSE]);
		DrawString( 350, 400, "4.Instructions", colors[MISTY_ROSE]);
		DrawString( 350, 350, "5.HighScores", colors[MISTY_ROSE]);
		DrawString( 350, 300, "6.Exit", colors[MISTY_ROSE]);

		glutSwapBuffers(); // do not modify this line..
	}
}
void MainMenu::name(){
	if(MenuOption==1){
		glClearColor(0/*Red Component*/,0 ,	//148.0/255/*Green Component*/,
				0/*Blue Component*/, 0 /*Alpha component*/); //#include <GL/gl.h>
		// Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		DrawLine(135,135,135,705,5,colors[WHITE]);
		DrawLine(135,135,705,135,5,colors[WHITE]);
		DrawLine(705,135,705,705,5,colors[WHITE]);
		DrawLine(135,705,705,705,5,colors[WHITE]);

		DrawString( 350, 430, "Enter Your Name", colors[MISTY_ROSE]);
		glutSwapBuffers();
	}
}
void MainMenu::HighScore(){
	if(MenuOption==6){

		int temp1=0,temp2=0;
		ifstream infile("highscore.txt");

		infile.read(reinterpret_cast<char*>(&x),sizeof(x));

		infile.close();
		for (int i = 0; i < 4; ++i) {
			if(p.getScore()>x[i]){
				temp1=x[i];
				x[i]=p.getScore();
				for (int j = i; j < 3; ++j) {
					temp2=x[j+1];
					x[j+1]=temp1;
					temp1=temp2;
				}
				break;
			}
		}
		ofstream outfile("highscore.txt");

		outfile.write(reinterpret_cast<char*>(&x),sizeof(x));

		outfile.close();
	}
}
void MainMenu::DisplayHighscore(){
	if(MenuOption==5){
		glClearColor(0/*Red Component*/,0 ,	//148.0/255/*Green Component*/,
				0/*Blue Component*/, 0 /*Alpha component*/); //#include <GL/gl.h>
		// Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
//		if()
		DrawLine(135,135,135,705,5,colors[WHITE]);
		DrawLine(135,135,705,135,5,colors[WHITE]);
		DrawLine(705,135,705,705,5,colors[WHITE]);
		DrawLine(135,705,705,705,5,colors[WHITE]);
		ifstream infile("highscore.txt", ios::binary);

		infile.read(reinterpret_cast<char*>(&x),sizeof(x));

		infile.close();
		DrawString( 350, 550, "1."+Num2Str(x[0]), colors[MISTY_ROSE]);
		DrawString( 350, 500, "2."+Num2Str(x[1]), colors[MISTY_ROSE]);
		DrawString( 350, 450, "3."+Num2Str(x[2]), colors[MISTY_ROSE]);
		DrawString( 350, 400, "4."+Num2Str(x[3]), colors[MISTY_ROSE]);

		DrawString( 350, 300, "1.Exit", colors[RED]);

		glutSwapBuffers(); // do not modify this line..

	}
}
void MainMenu::setLevel(int lvl){
	p.setLevel(lvl);
}
void MainMenu::setMoves(int mv){
	l.setMoves(mv);
}
void MainMenu::setOption(int o){
	l.setOption(o);
}
void MainMenu::GameOver(){
	if(MenuOption==6){

		HighScore();
		glClearColor(0/*Red Component*/,0 ,	//148.0/255/*Green Component*/,
				0/*Blue Component*/, 0 /*Alpha component*/); //#include <GL/gl.h>
		// Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		DrawLine(135,135,135,705,5,colors[WHITE]);
		DrawLine(135,135,705,135,5,colors[WHITE]);
		DrawLine(705,135,705,705,5,colors[WHITE]);
		DrawLine(135,705,705,705,5,colors[WHITE]);

		DrawString( 350, 650, "GAME OVER", colors[RED]);

		DrawString( 350, 550, "1.Start New Game", colors[MISTY_ROSE]);
		DrawString( 350, 500, "2.Levels", colors[MISTY_ROSE]);
		DrawString( 350, 450, "3.Level Modes", colors[MISTY_ROSE]);
		DrawString( 350, 400, "4.Setting", colors[MISTY_ROSE]);
		DrawString( 350, 350, "5.HighScores", colors[MISTY_ROSE]);
		DrawString( 350, 300, "6.Exit", colors[MISTY_ROSE]);
		Restart();
		glutSwapBuffers();
	}
}
void MainMenu::Restart(){
	p.setF(0);
	p.setLevel(1);
	p.setProgress(0);
	p.setLives(3);
	p.setScore(0);
	l.setTime(100);
	l.setMoves(30);
}
void MainMenu::Pause(){
	if(MenuOption==7){
		glClearColor(0/*Red Component*/,0 ,	//148.0/255/*Green Component*/,
				0/*Blue Component*/, 0 /*Alpha component*/); //#include <GL/gl.h>
		// Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors

		DrawLine(135,135,135,705,5,colors[WHITE]);
		DrawLine(135,135,705,135,5,colors[WHITE]);
		DrawLine(705,135,705,705,5,colors[WHITE]);
		DrawLine(135,705,705,705,5,colors[WHITE]);

		DrawString( 350, 650, "Pause", colors[GREEN]);
		DrawString( 350, 550, "1.Continue", colors[MISTY_ROSE]);
		DrawString( 350, 500, "2.Start a New Game", colors[MISTY_ROSE]);
		DrawString( 350, 450, "3.Instructions", colors[MISTY_ROSE]);
		DrawString( 350, 400, "4.HighScores", colors[MISTY_ROSE]);
		DrawString( 350, 350, "5.Exit", colors[MISTY_ROSE]);

		glutSwapBuffers(); // do not modify this line..
	}
}
void MainMenu::levels(){
	if(MenuOption==2){
		glClearColor(0/*Red Component*/,0 ,	//148.0/255/*Green Component*/,
				0/*Blue Component*/, 0 /*Alpha component*/); //#include <GL/gl.h>
		// Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
//		if()
		DrawLine(135,135,135,705,5,colors[WHITE]);
		DrawLine(135,135,705,135,5,colors[WHITE]);
		DrawLine(705,135,705,705,5,colors[WHITE]);
		DrawLine(135,705,705,705,5,colors[WHITE]);
		int f=p.getLevel();
		if (f==1) {
			DrawSquare(330,555,10,colors[RED]);
		}
		else if (f==2) {
			DrawSquare(330,505,10,colors[RED]);
		}
		else if (f==3) {
			DrawSquare(330,455,10,colors[RED]);
		}
		else if (f==4) {
			DrawSquare(330,405,10,colors[RED]);
		}
		else if (f==5) {
			DrawSquare(330,355,10,colors[RED]);
		}
		DrawString( 350, 550, "1.level 1", colors[MISTY_ROSE]);
		DrawString( 350, 500, "2.level 2", colors[MISTY_ROSE]);
		DrawString( 350, 450, "3.level 3", colors[MISTY_ROSE]);
		DrawString( 350, 400, "4.level 4", colors[MISTY_ROSE]);
		DrawString( 350, 350, "5.level 5", colors[MISTY_ROSE]);
		DrawString( 350, 300, "6.Exit", colors[MISTY_ROSE]);

		glutSwapBuffers(); // do not modify this line..
	}

}
void MainMenu::instruction(){
	if(MenuOption==4){
		glClearColor(0/*Red Component*/,0 ,	//148.0/255/*Green Component*/,
				0/*Blue Component*/, 0 /*Alpha component*/); //#include <GL/gl.h>
		// Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		DrawLine(135,135,135,705,5,colors[WHITE]);
		DrawLine(135,135,705,135,5,colors[WHITE]);
		DrawLine(705,135,705,705,5,colors[WHITE]);
		DrawLine(135,705,705,705,5,colors[WHITE]);

		DrawString( 200, 650, "Crush candies by swiping over three matching", colors[MISTY_ROSE]);
		DrawString( 200, 600, "pieces of candy in a row. You can match more", colors[MISTY_ROSE]);
		DrawString( 200, 550, "than three pieces in a  row or in a connected", colors[MISTY_ROSE]);
		DrawString( 200, 500, "shape for special bonuses. Once you crush a ", colors[MISTY_ROSE]);
		DrawString( 200, 450, "row of candies, the row will disappear and ", colors[MISTY_ROSE]);
		DrawString( 200, 400, "the candies above the row will drop down.", colors[MISTY_ROSE]);
		DrawString( 350, 300, "1.Exit", colors[RED]);

		glutSwapBuffers(); // do not modify this line..
	}
}
void MainMenu::levelModes(){
	if(MenuOption==3){
		glClearColor(0/*Red Component*/,0 ,	//148.0/255/*Green Component*/,
				0/*Blue Component*/, 0 /*Alpha component*/); //#include <GL/gl.h>
		// Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		DrawLine(135,135,135,705,5,colors[WHITE]);
		DrawLine(135,135,705,135,5,colors[WHITE]);
		DrawLine(705,135,705,705,5,colors[WHITE]);
		DrawLine(135,705,705,705,5,colors[WHITE]);
		int f=l.getOption();
		if (f==0) {
			DrawSquare(330,485,10,colors[RED]);
		}
		else if (f==1) {
			DrawSquare(330,435,10,colors[RED]);
		}
		DrawString( 350, 480, "1.Normal Mode", colors[MISTY_ROSE]);
		DrawString( 350, 430, "2.Time Trail Mode", colors[MISTY_ROSE]);
		DrawString( 350, 380, "3.Exit", colors[MISTY_ROSE]);

		glutSwapBuffers(); // do not modify this line..
	}
}
MainMenu::~MainMenu() {
	// TODO Auto-generated destructor stub
}

