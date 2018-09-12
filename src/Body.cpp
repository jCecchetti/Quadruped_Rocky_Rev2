/*
 * Body.cpp
 *
 *  Created on: Sep 5, 2018
 *      Author: julia
 */

#include "Body.h"
#include "Constants.h"
#include "Position.h"
#include "PositionCluster.h"
#include <math.h>
#include "Matrix.h"

PositionCluster Body::getLocalCornerPos(Position localBodyPos){
	PositionCluster localCornerPos;
	double tempLocalCornerPos [4][3] = {{Constants::BODYLENGTH/2, Constants::BODYWIDTH/2, 0},
									{Constants::BODYLENGTH/2, -Constants::BODYWIDTH/2, 0},
									{-Constants::BODYLENGTH/2, Constants::BODYWIDTH/2, 0},
									{-Constants::BODYLENGTH/2, -Constants::BODYWIDTH/2, 0}};

	double pitchRotationMatrix [3][3]= {{cos(toRadians(localBodyPos.pitch)), 0, -sin(toRadians(localBodyPos.pitch))},
									 {0, 1, 0},
									 {sin(toRadians(localBodyPos.pitch)), 0, cos(toRadians(localBodyPos.pitch))}};
	double rollRotationMatrix [3][3]= {{1, 0, 0},
									  {0, cos(toRadians(localBodyPos.roll)), sin(toRadians(localBodyPos.roll))},
									  {0, -sin(toRadians(localBodyPos.roll)), cos(toRadians(localBodyPos.roll))}};
	double yawRotationMatrix [3][3]= {{cos(toRadians(localBodyPos.yaw)), -sin(toRadians(localBodyPos.yaw)), 0},
								    {sin(toRadians(localBodyPos.yaw)), cos(toRadians(localBodyPos.yaw)), 0},
								    {0, 0, 1}};
	for(int i = 0; i < 4; i++){
		double newCornerPos[3];
		Matrix::multiply(rollRotationMatrix, tempLocalCornerPos[i], newCornerPos);
		tempLocalCornerPos[i][0] = newCornerPos[0];
		//Matrix::multiply(pitchRotationMatrix, tempLocalCornerPos[i], newLocalCornerPos[i]);
		//Matrix::multiply(yawRotationMatrix, tempLocalCornerPos[i], newLocalCornerPos[i]);
		localCornerPos.position[i].set(tempLocalCornerPos[i][0] + localBodyPos.x, tempLocalCornerPos[i][1] + localBodyPos.y,
				tempLocalCornerPos[i][2] + localBodyPos.z, localBodyPos.roll, localBodyPos.pitch, localBodyPos.yaw);

	}

	return localCornerPos;
}

PositionCluster Body::getGlobalCornerPos(Position localBodyPos, Position globalBodyPos){
		PositionCluster globalCornerPos = getLocalCornerPos(localBodyPos);
		for(int i = 0; i < 4; i++){
			globalCornerPos.position[i].set(globalCornerPos.position[i].x + globalBodyPos.x, globalCornerPos.position[i].y + globalBodyPos.y,
					globalCornerPos.position[i].z + globalBodyPos.z, localBodyPos.roll, localBodyPos.pitch, localBodyPos.yaw);
		}
		return globalCornerPos;
}

PositionCluster Body::getGlobalStepCenter(Position localBodyPos, Position globalBodyPos){
		PositionCluster globalStepCenter;
		double stepCenter[4][3] = {{Constants::BODYLENGTH/2, Constants::BODYWIDTH/2, 0},
				{Constants::BODYLENGTH/2, -Constants::BODYWIDTH/2, 0},
				{-Constants::BODYLENGTH/2, Constants::BODYWIDTH/2, 0},
				{-Constants::BODYLENGTH/2, -Constants::BODYWIDTH/2, 0}};

		double yawRotationMatrix[3][3] = {{cos(toRadians(localBodyPos.yaw)), -sin(toRadians(localBodyPos.yaw)), 0},
				{sin(toRadians(localBodyPos.yaw)), cos(toRadians(localBodyPos.yaw)), 0},
				{0, 0, 1}};

		for(int i = 0; i < 4; i++){
			Matrix::multiply(yawRotationMatrix, stepCenter[i], stepCenter[i]);
			globalStepCenter.position[i].set(stepCenter[0][i] + globalBodyPos.x, stepCenter[1][i] + globalBodyPos.y,
					stepCenter[2][i] + globalBodyPos.z, localBodyPos.roll, localBodyPos.pitch, localBodyPos.yaw);
		}

		return globalStepCenter;
	}

double Body::toRadians(double degrees){
	return degrees*0.0174533;
}


Body::Body() {

}

Body::~Body() {

}
