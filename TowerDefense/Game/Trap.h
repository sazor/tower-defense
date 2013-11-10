#ifndef TRAP_H
#define	TRAP_H
#include <vector>
#include "MagicTower.h"
#include "StandartTower.h"

class Trap : public MagicTower, public StandartTower{
public:
    Trap();
    Trap(const Trap& orig);
    virtual ~Trap();
protected:
    virtual bool attack();
private:
    std::vector<Enemy&> find_enemies();
};

#endif	/* TRAP_H */

