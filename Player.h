/*
 * Player.h
 *
 *  Created on: May 22, 2020
 *      Author: rizwan
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <iostream>
using namespace std;
class Player {
	int score;
	int level;
	int lives;
	int progress;
	int f;
public:
	Player();
	Player(int,int,int,int,int);
	void incScore();
	void setScore(int);
	void setProgress(int);
	void incProgress();
	bool incLevel();
	int getLevel();
	int getF();
	int getLives();
	void setLives(int);
	void setF(int);
	void setLevel(int);
	int getScore();
	int getProgress();
	virtual ~Player();
};

#endif /* PLAYER_H_ */
