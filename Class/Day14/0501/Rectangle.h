#pragma once
#include "Shape.h"
// class �ڽ� Ŭ���� : public �θ� Ŭ����
class Rectangle :
    public Shape
{
public:// �簢���� �߽�

    int m_width, m_height;
    int m_area, m_length;

    void Area();    // ����
    void Length();  // �ѷ�

    Rectangle();
    ~Rectangle();

};

