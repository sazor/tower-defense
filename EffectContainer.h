#ifndef EFFECTCONTAINER_H
#define	EFFECTCONTAINER_H
#include "Effect.h"
class EffectContainer {
private:
    Effect* effects;
    int number;
public:
    EffectContainer();
    EffectContainer(const EffectContainer& orig);
    virtual ~EffectContainer();
    void action(Enemy&);
    void setNumber(int number);
    int getNumber() const;
    void setEffects(Effect* effects);
    Effect* getEffects() const;
private:
    void delete_effect(int);
    void add_effect(int);
    void check_time();
};

#endif	/* EFFECTCONTAINER_H */

