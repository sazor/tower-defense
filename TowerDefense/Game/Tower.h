#ifndef TOWER_H
#define	TOWER_H
#include "Characteristics.h"
#include "GameApp.h"
#include <chrono>
#include <ctime>
#include <thread>

class Tower : public Actor{
protected:
    Enemy& find_enemy();
    Enemy& nearest_tower();
    Enemy& nearest_castle();
    Enemy& weakest();
    Enemy& strongest();
    Enemy& fastest();
public:
    Tower();
    Tower(const Tower& orig);
    virtual ~Tower() { };
    void time();
    virtual bool attack() { };
    void level_up();
    void setCharacteristics(Characteristics characteristics);
    Characteristics getCharacteristics() const;
    void setLevel(int level);
    int getLevel() const;
    virtual void ReceiveMessage(Message *message);
    virtual void Render();
private:
    int level;
    bool rendered;
    Characteristics characteristics;
};

#endif	/* TOWER_H */

