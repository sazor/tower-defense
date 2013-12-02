/* 
 * File:   Level.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:30 PM
 */

#include "Level.h"
std::vector<Lev> Level::levels;

void Level::addLevel(float radius, int cost){
	Lev new_lev(radius, cost);
    levels.push_back(new_lev);
}

void Level::setLevel(int level, float radius, int cost){
	levels[level-1].radius = radius;
	levels[level-1].cost = cost;
}

int Level::Cost(int level){
	return levels[level-1].cost;
}

float Level::Radius(int level){
	return levels[level-1].radius;
}

int Level::MaxLevel(){
	return levels.size();
}