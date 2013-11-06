#ifndef TRAP_H
#define	TRAP_H
class Trap : public Tower{
public:
    Trap();
    Trap(const Trap& orig);
    virtual ~Trap();
protected:
    virtual bool attack();
private:
    EnemyNode find_enemies();
};

#endif	/* TRAP_H */

