/*
 * normalMode.cpp
 *
 *  Created on: May 23, 2020
 *      Author: rizwan
 */

#include "normalMode.h"

normalMode::normalMode() {
	// TODO Auto-generated constructor stub
	moves=30;
}
normalMode::normalMode(int m){
	moves=m;
}
int normalMode::getMoves(){
	return moves;
}
void normalMode::setMoves(int m){
	moves=m;
}
void normalMode::decMoves(){
	moves--;
}
normalMode::~normalMode() {
	// TODO Auto-generated destructor stub
}

