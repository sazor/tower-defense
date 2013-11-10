#ifndef CASTLE_H
#define	CASTLE_H
#include "Tower.h"
#include "Point.h"

class Castle{
public:
    Castle();
    Castle(const Castle& orig);
    ~Castle();
    void get_damage(int);
    void collapse();
    void get_cash(int);
    bool levelup_tower(Tower&);
    virtual bool change_position(Point);
    void setCash(int cash);
    int getCash() const;
    void setMax_health(int max_health);
    int getMax_health() const;
    void setHealth(int health);
    int getHealth() const;
private:
    int health, max_health, cash;
};

#endif	/* CASTLE_H */
