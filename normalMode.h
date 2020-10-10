/*
 * normalMode.h
 *
 *  Created on: May 23, 2020
 *      Author: rizwan
 */

#ifndef NORMALMODE_H_
#define NORMALMODE_H_

class normalMode {
protected:
	int moves;
public:
	normalMode();
	normalMode(int m);
	int getMoves();
	void setMoves(int);
	void decMoves();
	virtual ~normalMode();
};

#endif /* NORMALMODE_H_ */
