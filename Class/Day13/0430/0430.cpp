#include "Util.h"
#include "Vector.h"
#include "Circle.h"
int main()
{
    Util util;
    util.myprint();
    
    Vector vec1;

    Circle circle;
    circle.SetCenter(10, 10);
    Point p = circle.GetCenter();
    cout << p.x << "\t" << p.y << endl;

    Point px = { 100, 100 };
    circle.SetCenter(px);

    p = circle.GetCenter();
    cout << p.x << "\t" << p.y << endl;

    return 0;
}

