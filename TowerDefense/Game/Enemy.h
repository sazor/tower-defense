#ifndef ENEMY_H
#define	ENEMY_H
#include <vector>
#include "Effect.h"
//#include "EffectContainer.h"
#include "Point.h"
#include "GameApp.h"

class Enemy : public Actor{
public:
    Enemy();
    Enemy(const Enemy& orig);
    virtual ~Enemy();
    void time();
    virtual bool change_position(Point);
    void setEffects(std::vector<Effect>);
    virtual void ReceiveMessage(Message *message);
    std::vector<Effect> getEffects() const;
    void setSpeed(int speed);
    int getSpeed() const;
    void setCash(int cash);
    int getCash() const;
    void GoTo(Vector2 newDestination);
    virtual void Render();
    void setMax_health(int max_health);
    int getMax_health() const;
    void setHeath(int heath);
    int getHeath() const;
    void GetToNextPoint();

private:
    int heath, max_health, cash, speed;
    std::vector<Effect> effects;
    void move();
    void effect(Effect);
    void die();
    void damage(int);
    bool tower_attack();
    Vector2List _pathPoints;
    unsigned int _pathIndex;
};

#endif	/* ENEMY_H */

