/*
 * timeTrailMode.h
 *
 *  Created on: May 23, 2020
 *      Author: rizwan
 */

#ifndef TIMETRAILMODE_H_
#define TIMETRAILMODE_H_

class timeTrailMode {
protected:
	int time;
public:
	timeTrailMode();
	timeTrailMode(int t);
	void TimeMode();
	int getTime();
	void setTime(int);
	virtual ~timeTrailMode();
};

#endif /* TIMETRAILMODE_H_ */
