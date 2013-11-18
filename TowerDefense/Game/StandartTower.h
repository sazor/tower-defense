#ifndef STANDARTTOWER_H
#define	STANDARTTOWER_H
#include "Tower.h"
#include <chrono>
#include <ctime>
#include <thread>
#include <vector>

class StandartTower : public Tower{
public:
    StandartTower();
    StandartTower(const StandartTower& orig);
    virtual ~StandartTower();
    Actor *circle;
    virtual void Render();
protected:
    virtual bool attack();
    bool rendered;
};

#endif	/* STANDARTTOWER_H */

