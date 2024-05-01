#pragma once
#include "Shape.h"
// class 자식 클래스 : public 부모 클래스
class Circle :
    public Shape
{
public:
    int m_radius, m_area, m_length;

    void Area();
    void Length();

    Circle();
    ~Circle();

};

