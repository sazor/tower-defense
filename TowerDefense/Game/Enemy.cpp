/* 
 * File:   Enemy.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:27 PM
 */

#include "Enemy.h"
#include <iostream>

Enemy::Enemy(){
    SetSize(MathUtil::PixelsToWorldUnits(25.0f), MathUtil::PixelsToWorldUnits(40.0f));
    SetSprite("Resources/Images/zombie_001.png");
    LoadSpriteFrames("Resources/Images/zombie_001.png");
    PlaySpriteAnimation(0.5f, SAT_Loop, 0, 2, "Anim"); 
    speed = 3.0f;
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
    theSwitchboard.SubscribeTo(this, "MouseDown");
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
    if (message->GetMessageName() == "MouseDown")
    {
        TypedMessage<Vec2i> *m = (TypedMessage<Vec2i>*)message;
        Vec2i screenCoordinates = m->GetValue();
        Vector2 next = MathUtil::ScreenToWorld(screenCoordinates);
        GoTo(next);
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
    //Want this guy to move at a constant rate of 8.0 units per second
    float time = distance / speed;
    MoveTo(next, time, false, "PathPointReached");
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

void Enemy::setHeath(float heath)
{
    this->heath = heath;
}

float Enemy::getHeath() const
{
    return heath;
}

bool Enemy::change_position(Point){
    
}