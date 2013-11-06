#ifndef ENEMY_H
#define	ENEMY_H
#include "EffectContainer.h"
class Enemy {
public:
    Enemy();
    Enemy(const Enemy& orig);
    virtual ~Enemy();
    void time();
    virtual bool change_position(Point);
    void setEffects(EffectContainer effects);
    EffectContainer getEffects() const;
    void setSpeed(int speed);
    int getSpeed() const;
    void setCash(int cash);
    int getCash() const;
    void setMax_health(int max_health);
    int getMax_health() const;
    void setHeath(int heath);
    int getHeath() const;
private:
    int heath, max_health, cash, speed;
    EffectContainer effects;
    void move();
    void effect(Effect);
    void die();
    void damage(int);
    bool tower_attack();
};

#endif	/* ENEMY_H */

