#pragma once
#include "Shape.h"
// class 자식 클래스 : public 부모 클래스
class Rectangle :
    public Shape
{
public:// 사각형의 중심

    int m_width, m_height;
    int m_area, m_length;

    void Area();    // 넓이
    void Length();  // 둘레

    Rectangle();
    ~Rectangle();

};

