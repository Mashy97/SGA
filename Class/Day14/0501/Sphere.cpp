#include "sphere.h"


Sphere::Sphere()
	:center3d{ 0,0,0 }
{
	v[8] = {};
}

Sphere::Sphere(Point3D* pv, Point3D center)
{
	for (int i = 0; i < 8; i++) {
		this->v[i] = *(pv+1);
	}

	center3d = center;
}

Sphere::~Sphere()
{
}
