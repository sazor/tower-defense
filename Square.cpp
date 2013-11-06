/* 
 * File:   Square.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:24 PM
 */

#include "Square.h"

Square::Square()
{
}

Square::Square(const Square& orig)
{
}

Square::~Square()
{
}

void Square::setType(Ground type)
{
        this->type = type;
}

Ground Square::getType() const
{
        return type;
}

void Square::setPosition(Point position)
{
        this->position = position;
}

Point Square::getPosition() const
{
        return position;
}

void Square::setQuantity(int quantity)
{
        this->quantity = quantity;
}

int Square::getQuantity() const
{
        return quantity;
}

AbstractObject* Square::getContent() const
{
        return content;
}

