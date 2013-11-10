#ifndef LANDSCAPE_H
#define	LANDSCAPE_H
#include "Square.h"
class Landscape {
public:
    Landscape();
    Landscape(const Landscape& orig);
    virtual ~Landscape();
    bool change_square(int, int, Square);
    bool change_size(int, int);
    bool validate();
    void setName(std::string);
    std::string getName() const;
    int getHeight() const;
    int getWidth() const;
private:
    int width, height;
    std::string name;
    Square** squares;
};

#endif	/* LANDSCAPE_H */

