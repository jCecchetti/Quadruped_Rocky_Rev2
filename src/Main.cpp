#include <stdio.h>
#include <time.h>
#include <chrono>
#include "Position.h"
#include "Leg.h"
#include "PositionCluster.h"
#include <iostream>
#include "Body.h"

using namespace std;

int main(int argc, char *argv[])
{
	Position position(0,0,0,0,32,10);
	Leg leg(false);
	//leg.setFootPos(position);

	Body b;
	PositionCluster a = b.getLocalCornerPos(position);
	std::cout << a.position[0].x;

	//time timer = time();
	/*double fps = 60;// updates per second
	double timePerTick = 1000000000/fps;
	double delta = 0;
	long now;
	long lastTime = 0;//nanotime
	long timer = 0;
	int ticks = 0;
	long totalSeconds = 0;
	bool running = true;*/

	/*
	while(running){
		now = std::chrono::system_clock::now();
		delta += (now - lastTime) / timePerTick;
		timer += now - lastTime;
		lastTime = now;
		//cout << now;

		if(delta >= 1){
			//update();
			ticks++;
			delta--;
			//if(motion.end) running = false;
		}

		if(timer >= 1000000000){
			//System.out.println("Ticks and Frames " + ticks);
			timer = 0;
			ticks = 0;
			totalSeconds++;
		}
	}*/

	return 0;
}
