#ifndef SQUARE_H
#define	SQUARE_H
#include "AbstractObject.h"
enum Ground{
    Road,
    Field,
    Forest
};
class Square {
public:
    Square();
    Square(const Square& orig);
    virtual ~Square();
    bool add_object(AbstractObject&);
    bool remove_object(int);
    bool exist(AbstractObject&);
    void setType(Ground type);
    Ground getType() const;
    void setPosition(Point position);
    Point getPosition() const;
    void setQuantity(int quantity);
    int getQuantity() const;
    AbstractObject* getContent() const;
private:
    AbstractObject* content;
    int quantity;
    Point position;
    Ground type;
};

#endif	/* SQUARE_H */

