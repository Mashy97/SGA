#pragma once
#include "Shape.h"
class Triangle :
    public Shape
{
public:
    int m_width, m_height;
    int m_area, m_length;

    void Area();
    void Length();
};

