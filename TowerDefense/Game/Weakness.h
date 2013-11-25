#ifndef WEAKNESS_H
#define	WEAKNESS_H
#include "Effect.h"

class Weakness : public Effect{
public:
    Weakness();
    Weakness(const Weakness& orig);
    virtual ~Weakness();
    virtual void action(Enemy&);
    virtual void expired(Enemy&);
};

#endif	/* WEAKNESS_H */

