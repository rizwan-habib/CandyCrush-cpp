/*
 * timeTrailMode.cpp
 *
 *  Created on: May 23, 2020
 *      Author: rizwan
 */

#include "timeTrailMode.h"

timeTrailMode::timeTrailMode() {
	// TODO Auto-generated constructor stub

	time=100;
}
timeTrailMode::timeTrailMode(int t){
	time=t;
}
void timeTrailMode::TimeMode(){

	time--;
}
void timeTrailMode::setTime(int t){
	time=t;
}
int timeTrailMode::getTime(){
	return time;
}
timeTrailMode::~timeTrailMode() {
	// TODO Auto-generated destructor stub
}

