#ifndef MAGICTOWER_H
#define	MAGICTOWER_H
#include "Tower.h"

class MagicTower : Tower{
public:
    MagicTower();
    MagicTower(const MagicTower& orig);
    virtual ~MagicTower();
protected:
    virtual bool attack();
};

#endif	/* MAGICTOWER_H */

