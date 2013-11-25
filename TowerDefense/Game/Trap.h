#ifndef TRAP_H
#define	TRAP_H
#include "Tower.h"
#include <chrono>
#include <ctime>
#include <thread>
#include <vector>
#include <memory>

class Trap : public Tower{
public:
    Trap();
    Trap(const Trap& orig);
    virtual ~Trap();
    virtual void Render();
    virtual void ReceiveMessage(Message *message);
    Actor *circle;
protected:
    virtual bool attack();
    bool rendered;
};

#endif	/* TRAP_H */

