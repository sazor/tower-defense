#pragma once
#include <vector>
#include "Effect.h"
#include <memory>
#include "Point.h"
#include "GameApp.h"
#include <algorithm>
#include "Castle.h"
#include "Container.h"

class Enemy : public Actor{
public:
    Enemy();
    Enemy(const Enemy& orig);
    virtual ~Enemy();
    void time();
    virtual bool change_position(Point);
    virtual void ReceiveMessage(Message *message);
    void GoTo(Vector2 newDestination);
    virtual void Render();
    void GetToNextPoint();
    void get_damage(int);
    void effect(std::shared_ptr<Effect>);
    void decrease_speed(float);
    void increase_dmg_factor(float);
    void increase_speed(float);
    void decrease_dmg_factor(float);
private:
    float health, max_health, cash, speed;
    Container<std::shared_ptr<Effect>> effects;
    void move();
    void die();
    int damage_factor;
    void damage(float);
    bool tower_attack();
    Vector2List _pathPoints;
    unsigned int _pathIndex;
};
