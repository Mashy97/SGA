#pragma once
#include "Shape.h"
class Sphere :
    public Shape
{

public:
    Point3D center3d;   // �߽���

    Point3D v[8];

    Sphere();
    Sphere(Point3D* pv, Point3D center);
    ~Sphere();
    
    void Volume();

};

