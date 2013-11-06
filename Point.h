#ifndef POINT_H
#define	POINT_H

class Point {
public:
    Point();
    Point(const Point& orig);
    virtual ~Point();
    int x, y;
private:

};

#endif	/* POINT_H */

