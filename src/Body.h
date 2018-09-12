/*
 * Body.h
 *
 *  Created on: Sep 5, 2018
 *      Author: julia
 */

#ifndef BODY_H_
#define BODY_H_

#include "Position.h"
#include "PositionCluster.h"

class Position;
class PositionCluster;

class Body {
public:
	Body();
	virtual ~Body();

	PositionCluster getLocalCornerPos(Position localBodyPos);
	PositionCluster getGlobalCornerPos(Position localBodyPos, Position globalBodyPos);
	PositionCluster getGlobalStepCenter(Position localBodyPos, Position globalBodyPos);
	Position getGlobalCoMPos(Position localBodyPos, Position globalBodyPos);
	Position getGlobalAdjustedCoMPos(Position localBodyPos, Position globalBodyPos, int corner);
	Position getRelativeFootPos(Position globalCornerPos, Position globalFootPos);

	double toRadians(double degrees);

private:
	PositionCluster localCornerPos;
};

#endif /* BODY_H_ */
