/*
 * gameScene.h
 *
 *  Created on: May 22, 2020
 *      Author: rizwan
 */

#ifndef GAMESCENE_H_
#define GAMESCENE_H_
#include<iostream>
#include<string>
#include<cmath>
#include <cstdlib>
#include "util.h"
#include "MainMenu.h"
class gameScene:public MainMenu {
	int arr[10][10];
public:
	gameScene();
	gameScene(int,int,int,int);
	void CandiesGenerator();
	void Swap(int,int,int,int);
	bool isMatching();
	void setLevel(int);
//	void Hint();
	void newCandiesGenerator();
	void setArr(int,int,int);
	int getArr(int,int);
	~gameScene();
};

#endif /* GAMESCENE_H_ */
