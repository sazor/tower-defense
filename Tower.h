#ifndef TOWER_H
#define	TOWER_H
#include "Characteristics.h"
#include "MagicTower.h"
#include "StandartTower.h"
#include "Trap.h"
class Tower : AbstractObject {
protected:
    bool attack();
    Enemy& find_enemy();
    Enemy& nearest_tower();
    Enemy& nearest_castle();
    Enemy& weakest();
    Enemy& strongest();
    Enemy& fastest();
public:
    Tower();
    Tower(const Tower& orig);
    virtual ~Tower();
    void time();
    virtual bool change_position(Point);
    void level_up();
    void setCharacteristics(Characteristics characteristics);
    Characteristics getCharacteristics() const;
    void setLevel(int level);
    int getLevel() const;
private:
    int level;
    Characteristics characteristics;
};

#endif	/* TOWER_H */

