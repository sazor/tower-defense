#pragma once
#include <vector>
#include "Effect.h"
#include <memory>
#include "GameApp.h"
#include <algorithm>
#include "Castle.h"
#include "Container.h"

class Enemy : public Actor{
public:
    Enemy();
    Enemy(const Enemy& orig);
    virtual ~Enemy();
    virtual void ReceiveMessage(Message *message);
    void GoTo(Vector2 newDestination);
    virtual void Render();
    void GetToNextPoint();
    bool get_damage(int);
    void effect(std::shared_ptr<Effect>);
    void decrease_speed(float);
    void increase_dmg_factor(float);
    void increase_speed(float);
    void decrease_dmg_factor(float);
private:
    float health, max_health, cash, speed;
    Container<std::shared_ptr<Effect>> effects;
    void die();
    float damage_factor;
    void damage(float);
    Vector2List _pathPoints;
    unsigned int _pathIndex;
};
