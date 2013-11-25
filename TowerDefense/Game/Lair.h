#ifndef LAIR_H
#define	LAIR_H
#include <vector>
#include "Enemy.h"
#include "GameApp.h"
#include <chrono>
#include <ctime>
#include <thread>

class Lair : public Actor{
public:
    Lair();
    Lair(const Lair& orig);
    virtual ~Lair();
    void release_enemy();
    void time();
    virtual void ReceiveMessage(Message *message);
    virtual void Render();
private:
    int time_interval; 
    bool rendered;
};

#endif	/* LAIR_H */

