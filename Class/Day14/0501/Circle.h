#pragma once
#include "Shape.h"
// class �ڽ� Ŭ���� : public �θ� Ŭ����
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

