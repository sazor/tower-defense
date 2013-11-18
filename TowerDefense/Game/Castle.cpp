/* 
 * File:   Castle.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:30 PM
 */
#include "Castle.h"
const int standart_cost = 100;
const int magic_cost = 150;
const int trap_cost = 150;
Castle::Castle()
{
    rendered = false;
    this->max_health = 100;
    this->health = max_health;
    this->cash = 500;
}

Castle::Castle(const Castle& orig)
{
}

Castle::~Castle()
{
}

bool Castle::buy_tower(int type){
    //1 - standart tower, 2 - magic tower, 3 - trap
    int cost = 0;
    switch(type){
        case 1: cost = standart_cost; break;
        case 2: cost = magic_cost; break;
        case 3: cost = trap_cost; break;
    }
    if(cash >= cost){
        cash -= cost;
        GameApp::castle_cash->SetDisplayString("Castle cash: " + IntToString(cash));
        return true;
    }
    return false;
}
void Castle::get_damage(int dmg){
    this->health -= dmg;
    if(health <= 0){
        theWorld.StopGame();
    }
    GameApp::castle_health->SetDisplayString("Castle health: " + IntToString(health));
}

void Castle::setCash(int cash)
{
        this->cash = cash;
}

int Castle::getCash() const
{
        return cash;
}

void Castle::setMax_health(int max_health)
{
        this->max_health = max_health;
}

int Castle::getMax_health() const
{
        return max_health;
}

void Castle::setHealth(int health)
{
        this->health = health;
}

int Castle::getHealth() const
{
        return this->health;
}

bool Castle::change_position(Point){
	
}

void Castle::Render()
{
    Actor::Render();
}

void Castle::ReceiveMessage(Message *message){

}

void Castle::give_cash(int amount){
    cash += amount;
    GameApp::castle_cash->SetDisplayString("Castle cash: " + IntToString(cash));
}