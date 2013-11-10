#ifndef LAIR_H
#define	LAIR_H
#include <vector>
#include "Enemy.h"
#include "Point.h"

class Lair{
public:
    Lair();
    Lair(const Lair& orig);
    virtual ~Lair();
    void release_enemy();
    void time();
    void add_enemy(Enemy&);
    void delete_enemy(Enemy&);
    virtual bool change_position(Point);
    std::vector<Enemy> getEnemies() const;
private:
    std::vector<Enemy> enemies;
};

#endif	/* LAIR_H */

