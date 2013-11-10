#ifndef EFFECT_H
#define	EFFECT_H
class Enemy;

class Effect {
private:
    int remaining_time, value;
public:
    Effect();
    Effect(const Effect& orig);
    virtual ~Effect() { };
    virtual void action(Enemy&) { };
    void setValue(int value);
    int getValue() const;
    void setRemaining_time(int remaining_time);
    int getRemaining_time() const;
};

#endif	/* EFFECT_H */

