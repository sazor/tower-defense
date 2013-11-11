#ifndef LAIR_H
#define	LAIR_H
#include <vector>
#include "Enemy.h"
#include "Point.h"
#include "GameApp.h"
#include <chrono>
#include <ctime>
#include <thread>

class Lair : public Actor{
public:
    Lair();
    Lair(const Lair& orig);
    virtual ~Lair();
    void release_enemy(Vector2 vec);
    void time();
    virtual bool change_position(Point);
    virtual void ReceiveMessage(Message *message);
    virtual void Render();
private:
    int interval; 
    bool first_render;
};

#endif	/* LAIR_H */

