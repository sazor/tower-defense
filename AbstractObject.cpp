/* 
 * File:   AbstractObject.cpp
 * Author: Sammy Guergachi <sguergachi at gmail.com>
 * 
 * Created on October 28, 2013, 11:23 PM
 */

#include "AbstractObject.h"

AbstractObject::AbstractObject()
{
}

AbstractObject::AbstractObject(const AbstractObject& orig)
{
}

AbstractObject::~AbstractObject()
{
}

void AbstractObject::setName(std::string name)
{
        this->name = name;
}

std::string AbstractObject::getName() const
{
        return name;
}

void AbstractObject::setWeight(int weight)
{
        this->weight = weight;
}

int AbstractObject::getWeight() const
{
        return weight;
}

void AbstractObject::setHeight(int height)
{
        this->height = height;
}

int AbstractObject::getHeight() const
{
        return height;
}

void AbstractObject::setWidth(int width)
{
        this->width = width;
}

int AbstractObject::getWidth() const
{
        return width;
}

void AbstractObject::setVisible(bool visible)
{
        this->visible = visible;
}

bool AbstractObject::isVisible() const
{
        return visible;
}

