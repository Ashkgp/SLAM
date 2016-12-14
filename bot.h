#ifndef BOT_H
#define BOT_H

#include <iostream>
/*****************************
Probability of correct measurement
and uncertainity with time.
*****************************/
#define P_MEASURE 0.8
#define P_MOVE 0.7

#define INF 9999

struct Point{
	double x;
	double y;
};

class Bot{

	Point grid_mean;
	double grid_varx;
	double grid_vary;

public:
	Bot(){
		grid_varx = INF;
		grid_vary = INF;
		grid_mean.x = null;
		grid_mean.y = null;
	}
	Bot(Point new_Point, Point var){
		grid_varx = var.x;
		grid_vary = var.y;
		grid_mean = new_Point;
	}

	void mov_update(Point velocity, Point var){
		grid_mean.x += velocity.x;
		grid_mean.y += velocity.y;
		grid_varx += var.x;
		grid_vary += var.y;
	}
	void see_update(Point new_Point, Point var){
		grid_mean.x = (grid_mean.x + new_Point.x)/2;
		grid_mean.y = (grid_mean.y + new_Point.y)/2;
		grid_vary = 1/(1/grid_vary + 1/var.y);
		grid_varx = 1/(1/grid_varx + 1/var.x);
	}

	Point get_prob(){
		Point a;
		a.x = grid_varx;
		a.y = grid_vary;
		return a;
	}

};

#endif