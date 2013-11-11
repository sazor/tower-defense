/* 
 * File:   Enemy.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:27 PM
 */

#include "Enemy.h"
#include <iostream>

Enemy::Enemy(){
   /* SetPosition(5.0f, 5.0f);
    SetDrawShape(ADS_Square);
    SetSprite("Resources/Images/Test.png");*/
    SetColor(1, 0, 0);
    SetSize(0.75f);
    SetDrawShape(ADS_Circle);
    theSwitchboard.SubscribeTo(this, "MouseDown");
    theSwitchboard.SubscribeTo(this, "PathPointReached");
    _pathIndex = 0;
    Vector2 aim = Vector2(-9.29f,0.71f);
    GoTo(aim);
}

Enemy::Enemy(Vector2 pos){
    SetColor(1, 0, 0);
    SetSize(0.75f);
    SetPosition(pos);
    SetDrawShape(ADS_Circle);
    theSwitchboard.SubscribeTo(this, "MouseDown");
    theSwitchboard.SubscribeTo(this, "PathPointReached");
    _pathIndex = 0;
    theWorld.Add(this, 2);
    Vector2 aim = Vector2(-9.29f,0.71f);
    GoTo(aim);
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
            theSwitchboard.Broadcast(new Message("EndPointReached", this));
            _pathPoints.clear();
            _pathIndex = 0;
            theWorld.Remove(this);
        }

    }
    if (message->GetMessageName() == "MouseDown")
    {
        ConsoleLog *c = new ConsoleLog();
        TypedMessage<Vec2i> *m = (TypedMessage<Vec2i>*)message;
        Vec2i screenCoordinates = m->GetValue();
        Vector2 next = MathUtil::ScreenToWorld(screenCoordinates);
        c->Printf("X: %4.4f. Y: %4.4f ", next.X, next.Y);
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
    float time = distance / 8.0f;
    MoveTo(next, time, false, "PathPointReached");
}


void Enemy::setSpeed(int speed)
{
    this->speed = speed;
}

int Enemy::getSpeed() const
{
    return speed;
}

void Enemy::setCash(int cash)
{
    this->cash = cash;
}

int Enemy::getCash() const
{
    return cash;
}

void Enemy::setMax_health(int max_health)
{
    this->max_health = max_health;
}

int Enemy::getMax_health() const
{
    return max_health;
}

void Enemy::setHeath(int heath)
{
    this->heath = heath;
}

int Enemy::getHeath() const
{
    return heath;
}

bool Enemy::change_position(Point){
    
}