#ifndef ENEMY_H
#define	ENEMY_H
#include <vector>
#include "Effect.h"
//#include "EffectContainer.h"
#include "Point.h"
#include "GameApp.h"
#include <algorithm>
#include "Castle.h"

class Enemy : public Actor{
public:
    Enemy();
    Enemy(Vector2);
    Enemy(const Enemy& orig);
    virtual ~Enemy();
    void time();
    virtual bool change_position(Point);
    void setEffects(std::vector<Effect>);
    virtual void ReceiveMessage(Message *message);
    std::vector<Effect> getEffects() const;
    void setSpeed(float speed);
    float getSpeed() const;
    void setCash(float cash);
    float getCash() const;
    void GoTo(Vector2 newDestination);
    virtual void Render();
    void setMax_health(float max_health);
    float getMax_health() const;
    void setHealth(float heath);
    float getHealth() const;
    void GetToNextPoint();
    void get_damage(int);
private:
    float health, max_health, cash, speed;
    std::vector<Effect> effects;
    void move();
    void effect(Effect);
    void die();
    void damage(float);
    bool tower_attack();
    Vector2List _pathPoints;
    unsigned int _pathIndex;
};

#endif	/* ENEMY_H */

