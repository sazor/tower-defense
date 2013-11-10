#ifndef ABSTRACTOBJECT_H
#define	ABSTRACTOBJECT_H
#include "Point.h"
#include <string>
class AbstractObject {
protected:
    bool visible;
    int width, height, weight;
    std::string name;
public:
    virtual bool change_position(Point) = 0;
    virtual ~AbstractObject() = 0;
};

#endif	/* ABSTRACTOBJECT_H */

