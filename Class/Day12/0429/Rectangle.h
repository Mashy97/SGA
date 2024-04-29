#pragma once
class Rectangle
{
private:
	int m_height;	// �ʱ�ȭ�� �����ڿ��� 
	int m_width;
	int m_area;
	int m_lenght;

	void PrintArea();	// �ܼ� ȭ�鿡 ������ ���
	void PrintLenght();	// �ܼ� ȭ�鿡 �ѷ��� ���
public:				// public ������ ���ٸ� �⺻ private 

	Rectangle();	// �Լ� ������
	~Rectangle();	// �Լ� �Ҹ���

	void Init(int width, int height);	// ���� �ʱ�ȭ

	void Area();	// ����
	void Lenght();	// �ѷ�

	void PrintInfo();	// �ܼ� ȭ�鿡 Rectangle�� ���� ���

};

