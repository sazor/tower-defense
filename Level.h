#ifndef LEVEL_H
#define	LEVEL_H

class Level {
public:
    Level();
    Level(const Level& orig);
    virtual ~Level();
    void SetEffect(Effect effect);
    Effect GetEffect() const;
    void SetSpeed(int speed);
    int GetSpeed() const;
    void SetDamage(int damage);
    int GetDamage() const;
    void SetRadius(int radius);
    int GetRadius() const;
    void SetCost(int cost);
    int GetCost() const;
private:
    int cost, radius, damage, speed;
    Effect effect;
};

#endif	/* LEVEL_H */

