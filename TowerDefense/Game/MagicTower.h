#ifndef MAGICTOWER_H
#define	MAGICTOWER_H
#include "Tower.h"
#include <chrono>
#include <ctime>
#include <thread>
#include <vector>
#include <memory>

class MagicTower : public Tower{
public:
    MagicTower();
    MagicTower(const MagicTower& orig);
    virtual ~MagicTower();
    virtual void Render();
    Actor *circle;
protected:
    virtual bool attack();
    bool rendered;
};

#endif	/* MAGICTOWER_H */

