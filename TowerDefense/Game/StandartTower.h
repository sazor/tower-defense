#ifndef STANDARTTOWER_H
#define	STANDARTTOWER_H
#include "Tower.h"
#include <chrono>
#include <ctime>
#include <thread>
#include <vector>
#include <functional>
		
class StandartTower : public Tower{
public:
    StandartTower();
    StandartTower(const StandartTower& orig);
    virtual ~StandartTower();
    virtual void ReceiveMessage(Message *message);
    Actor *circle;
    virtual void Render();
    virtual bool level_up();
protected:
    virtual bool attack();
    void delete_circle(Actor*);
    bool rendered;
    int ticks;
};

#endif	/* STANDARTTOWER_H */

