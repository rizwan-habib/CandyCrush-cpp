/*
 * level.cpp
 *
 *  Created on: May 23, 2020
 *      Author: rizwan
 */

#include "level.h"

level::level():normalMode(),timeTrailMode() {
	// TODO Auto-generated constructor stub
	option=0;
}
level::level(int m,int t,int o):normalMode(m),timeTrailMode(t){
	option=o;
}
int level::getOption(){
	return option;
}
void level::setOption(int o){
	option=o;
}
level::~level() {
	// TODO Auto-generated destructor stub
}

