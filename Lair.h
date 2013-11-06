#ifndef LAIR_H
#define	LAIR_H

class Lair : AbstractObject{
public:
    Lair();
    Lair(const Lair& orig);
    virtual ~Lair();
    void release_enemy();
    void time();
    void add_enemy(Enemy&);
    void delete_enemy(Enemy&);
    virtual bool change_position(Point);
private:
    EnemyNode* current_enemy;
};

#endif	/* LAIR_H */

