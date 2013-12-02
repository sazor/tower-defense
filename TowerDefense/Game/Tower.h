#ifndef TOWER_H
#define	TOWER_H
#include "GameApp.h"
#include <chrono>
#include <ctime>
#include <thread>
#include "Enemy.h"
#include "Level.h"
typedef bool (*tactics) (Enemy*, Enemy*);

class Tower : public Actor{
public:
    bool nearest_tower(Enemy*, Enemy*);
    bool nearest_castle(Enemy*, Enemy*);
    bool weakest(Enemy*, Enemy*);
    bool strongest(Enemy*, Enemy*);
    bool fastest(Enemy*, Enemy*);
    bool slowest(Enemy*, Enemy*);
    Tower();
    Tower(const Tower& orig);
    virtual ~Tower() { };
    void time();
    virtual bool attack() { };
    virtual bool level_up();
    virtual void ReceiveMessage(Message *message);
    virtual void Render();
protected:
    int level;
    bool rendered;
};

#endif	/* TOWER_H */

