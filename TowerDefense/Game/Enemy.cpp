/* 
 * File:   Enemy.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:27 PM
 */

#include "Enemy.h"
#include <iostream>

const int cost = 100;

Enemy::Enemy(){
    health = 100;
    SetSize(MathUtil::PixelsToWorldUnits(25.0f), MathUtil::PixelsToWorldUnits(40.0f));
    SetSprite("Resources/Images/zombie_001.png");
    Tag("enemy");
    LoadSpriteFrames("Resources/Images/zombie_001.png");
    PlaySpriteAnimation(0.5f, SAT_Loop, 0, 2, "Anim"); 
    speed = 2.0f;
    theSwitchboard.SubscribeTo(this, "MouseDown");
    theSwitchboard.SubscribeTo(this, "PathPointReached");
    _pathIndex = 0;
}

Enemy::Enemy(Vector2 pos){
    //Params
    SetColor(1, 0, 0);
    SetSize(0.75f);
    SetPosition(pos);
    SetDrawShape(ADS_Circle);
    speed = 3.0f;
    //Events
    theSwitchboard.SubscribeTo(this, "PathPointReached");
    _pathIndex = 0;
    
}

Enemy::Enemy(const Enemy& orig)
{
}

void Enemy::Render()
{
    Actor::Render();
}

void Enemy::ReceiveMessage(Message *message){
    if ( (message->GetMessageName() == "PathPointReached") && (message->GetSender() == this))
    {
        if (_pathIndex < _pathPoints.size() - 1)
        {
            GetToNextPoint();
        }
        else 
        {
            _pathPoints.clear();
            _pathIndex = 0;
            Castle* castle = (Castle*)Actor::GetNamed("Castle");
            castle->get_damage(5);
            theWorld.Remove(this);
            Actor::Destroy();
        }

    }
}

Enemy::~Enemy()
{
}

void Enemy::setEffects(std::vector<Effect> effects)
{
    this->effects = effects;
}

std::vector<Effect> Enemy::getEffects() const
{
    return effects;
}

void Enemy::GoTo(Vector2 newDestination)
{
    Vector2List pathTest;

    theSpatialGraph.GetPath(GetPosition(), newDestination, pathTest);
    
    if (pathTest.size() > 0)
    {
        _pathPoints = pathTest;
        _pathIndex = 0;
        GetToNextPoint();
    }
}

//Called at the start and every point in between to set up the movement to our
// next point in the path.
void Enemy::GetToNextPoint()
{
    Vector2 next = _pathPoints[++_pathIndex];
    float distance = Vector2::Distance(_position, next);
    float time = distance / speed;
    MoveTo(next, time, false, "PathPointReached");
}

void Enemy::get_damage(int dmg){
    health -= dmg;
    if(health <= 0){
        ConsoleLog *c = new ConsoleLog();
        c->Printf("Death");
        Castle* castle = (Castle*)Actor::GetNamed("Castle");
        castle->give_cash(cost);
        this->Untag("enemy");
        theWorld.Remove(this);
        Actor::Destroy();
    }
}

void Enemy::setSpeed(float speed)
{
    this->speed = speed;
}

float Enemy::getSpeed() const
{
    return speed;
}

void Enemy::setCash(float cash)
{
    this->cash = cash;
}

float Enemy::getCash() const
{
    return cash;
}

void Enemy::setMax_health(float max_health)
{
    this->max_health = max_health;
}

float Enemy::getMax_health() const
{
    return max_health;
}

void Enemy::setHealth(float heath)
{
    this->health = health;
}

float Enemy::getHealth() const
{
    return health;
}

bool Enemy::change_position(Point){
    
}