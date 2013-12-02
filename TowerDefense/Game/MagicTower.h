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
    virtual void ReceiveMessage(Message *message);
    virtual void Render();
    Actor *circle;
    virtual bool level_up();
protected:
    virtual bool attack();
    void delete_circle(Actor*);
    bool rendered;
    int ticks;
};

#endif	/* MAGICTOWER_H */

