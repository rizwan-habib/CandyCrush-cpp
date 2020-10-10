/*
 * MainMenu.h
 *
 *  Created on: May 23, 2020
 *      Author: rizwan
 */

#ifndef MAINMENU_H_
#define MAINMENU_H_
#include "Player.h"
#include "level.h"
#include<fstream>    //used for file handling

class MainMenu/*:public level*/ {
protected:
	int MenuOption;
	int x[4];
	Player p;
	level l;
public:
	MainMenu();
	MainMenu(int/*,int,int,int*/);
	void setMenuOption(int);
	int getMenuOption();
	int getmoves();
	void setLevel(int);
	void setMoves(int);
	void setOption(int);
	int getOption();
	void Restart();
	void TimeMode();
	void MenuDisplay();
	void levels();
	void name();
	void GameOver();
	void Pause();
	void levelModes();
	void instruction();
	void HighScore();
	void DisplayHighscore();
	virtual ~MainMenu();
};

#endif /* MAINMENU_H_ */
