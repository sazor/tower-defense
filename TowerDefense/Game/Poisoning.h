#ifndef POISONING_H
#define	POISONING_H
#include "Effect.h"

class Poisoning : public Effect {
public:
    Poisoning();
    Poisoning(const Poisoning& orig);
    virtual ~Poisoning();
    virtual void action(Enemy&);
    virtual void expired(Enemy&);
    void damage(Enemy&);
    virtual bool tick(Enemy&);
};

#endif	/* POISONING_H */

