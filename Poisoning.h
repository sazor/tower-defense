#ifndef POISONING_H
#define	POISONING_H
class Poisoning : public Effect {
public:
    Poisoning();
    Poisoning(const Poisoning& orig);
    virtual ~Poisoning();
    virtual void action(Enemy&);
private:

};

#endif	/* POISONING_H */

