#ifndef ABSTRACTOBJECT_H
#define	ABSTRACTOBJECT_H
#include "Point.h"
#include "Lair.h"
#include "Enemy.h"
#include "Tower.h"
#include "Castle.h"
class AbstractObject {
private:
    bool visible;
    int width, height, weight;
    std::string name;
public:
    AbstractObject();
    AbstractObject(const AbstractObject& orig);
    virtual bool change_position(Point);
    virtual ~AbstractObject();
    void setName(std::string name);
    std::string getName() const;
    void setWeight(int weight);
    int getWeight() const;
    void setHeight(int height);
    int getHeight() const;
    void setWidth(int width);
    int getWidth() const;
    void setVisible(bool visible);
    bool isVisible() const;
};

#endif	/* ABSTRACTOBJECT_H */

