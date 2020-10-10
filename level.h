/*
 * level.h
 *
 *  Created on: May 23, 2020
 *      Author: rizwan
 */

#ifndef LEVEL_H_
#define LEVEL_H_

#include "normalMode.h"
#include "timeTrailMode.h"

class level: public normalMode, public timeTrailMode {
protected:
	bool option;
public:
	level();
	level(int,int,int);
	int getOption();
	void setOption(int);
	virtual ~level();
};

#endif /* LEVEL_H_ */
