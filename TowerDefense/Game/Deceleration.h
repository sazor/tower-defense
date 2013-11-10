#ifndef DECELERATION_H
#define	DECELERATION_H
#include "Effect.h"

class Deceleration : public Effect {
public:
    Deceleration();
    Deceleration(const Deceleration& orig);
    virtual ~Deceleration();
    virtual void action(Enemy&);

};

#endif	/* DECELERATION_H */

