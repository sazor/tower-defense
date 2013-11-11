#ifndef CASTLE_H
#define	CASTLE_H
#include "Point.h"
#include "GameApp.h"

class Castle : public Actor{
public:
    Castle();
    Castle(const Castle& orig);
    ~Castle();
    void get_damage(int);
    void collapse();
    void get_cash(int);
    virtual bool change_position(Point);
    void setCash(int cash);
    int getCash() const;
    void setMax_health(int max_health);
    int getMax_health() const;
    void setHealth(int health);
    int getHealth() const;
    virtual void ReceiveMessage(Message *message);
    virtual void Render();
private:
    int health, max_health, cash;
    bool rendered;
};

#endif	/* CASTLE_H */

