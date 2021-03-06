/*
 * PositionCluster.h
 *
 *  Created on: Sep 7, 2018
 *      Author: julia
 */

#ifndef POSITIONCLUSTER_H_
#define POSITIONCLUSTER_H_

class Position;

class PositionCluster {
public:
	PositionCluster();
	PositionCluster(Position frontRight, Position frontLeft, Position rearRight, Position rearLeft);
	virtual ~PositionCluster();

	//Position frontRight, frontLeft, rearRight, rearLeft;
	Position position[4];
};

#endif /* POSITIONCLUSTER_H_ */
