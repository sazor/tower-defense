#ifndef EFFECT_H
#define	EFFECT_H
class Enemy;

class Effect {
protected:
    int remaining_time, value;
public:
    Effect();
    Effect(const Effect& orig);
    virtual ~Effect() { };
    virtual void action(Enemy&) { };
    virtual void smth(Enemy&) { };
    void setValue(int value);
    int getValue() const;
    void setRemaining_time(int remaining_time);
    int getRemaining_time() const;
    virtual void expired(Enemy&) { };
};

#endif	/* EFFECT_H */

