#ifndef LEVEL_H
#define	LEVEL_H
#include <vector>

struct Lev {
    float radius;
    int cost;
    Lev(float _rad, int _cost):radius(_rad), cost(_cost){};
};

class Level {
public:
    static void addLevel(float, int);
    static void setLevel(int, float, int);
    static int Cost(int);
    static float Radius(int);
    static int MaxLevel();
private:
    static std::vector<Lev> levels;
};

#endif	/* LEVEL_H */

