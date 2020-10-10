/*
 * Player.cpp
 *
 *  Created on: May 22, 2020
 *      Author: rizwan
 */

#include "Player.h"

Player::Player() {
	// TODO Auto-generated constructor stub
	score=0;
	level=1;
	progress=0;
	f=0;
	lives=3;
}
void Player::setLevel(int l){
	level=l;
}

void Player::setProgress(int p){
	progress=p;
}
void Player::setScore(int s){
	score=s;
}
Player::Player(int s,int l,int p,int F,int lves){
	score=s;
	level=l;
	progress=p;
	f=F;
	lives=lves;
}
void Player::incScore(){
	score++;
}

int Player::getF(){
	return f;
}
void Player::setF(int F){
	f=F;
}
void Player::setLives(int l){
	lives=l;
}
int Player::getLives(){
	return lives;
}
void Player::incProgress(){
	progress++;
}
bool Player::incLevel(){
	if(progress>=31){
		level++;
		f=0;
		progress=0;
		return 1;
	}
	return 0;
}
int Player::getLevel(){
	return level;
}
int Player::getScore(){
	return score;
}
int Player::getProgress(){
	return progress;
}
Player::~Player() {
	// TODO Auto-generated destructor stub
}

