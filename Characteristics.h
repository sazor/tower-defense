#ifndef CHARACTERISTICS_H
#define	CHARACTERISTICS_H
#include "Level.h"
class Characteristics {
public:
    Characteristics();
    Characteristics(const Characteristics& orig);
    virtual ~Characteristics();
    int get_cost(int);
    int get_radius(int);
    int get_damage(int);
    int get_speed(int);
    Effect get_effect(int);
private:
    Level* levels;
  
};

#endif	/* CHARACTERISTICS_H */

