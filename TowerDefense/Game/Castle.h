#ifndef CASTLE_H
#define	CASTLE_H
#include "GameApp.h"
#include "Level.h"

class Castle : public Actor{
public:
    Castle();
    Castle(const Castle& orig);
    ~Castle();
    void get_damage(int);
    void collapse();
    void get_cash(int);
    void setCash(int cash);
    int getCash() const;
    void setMax_health(int max_health);
    int getMax_health() const;
    void setHealth(int health);
    int getHealth() const;
    virtual void ReceiveMessage(Message *message);
    virtual void Render();
    bool buy_tower(int);
    void give_cash(int);
    bool buy_level(int);
private:
    int health, max_health, cash;
    bool rendered;
};

#endif	/* CASTLE_H */

