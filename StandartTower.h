#ifndef STANDARTTOWER_H
#define	STANDARTTOWER_H

class StandartTower : Tower{
public:
    StandartTower();
    StandartTower(const StandartTower& orig);
    virtual ~StandartTower();
protected:
    virtual bool attack();

};

#endif	/* STANDARTTOWER_H */

