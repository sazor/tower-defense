#ifndef STANDARTTOWER_H
#define	STANDARTTOWER_H
#include "Tower.h"

class StandartTower : Tower{
public:
    StandartTower();
    StandartTower(const StandartTower& orig);
    virtual ~StandartTower();
protected:
    virtual bool attack();

};

#endif	/* STANDARTTOWER_H */

