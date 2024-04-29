#pragma once
class Rectangle
{
private:
	int m_height;	// 초기화는 생성자에서 
	int m_width;
	int m_area;
	int m_lenght;

	void PrintArea();	// 콘솔 화면에 면적을 출력
	void PrintLenght();	// 콘솔 화면에 둘레를 출력
public:				// public 선언이 없다면 기본 private 

	Rectangle();	// 함수 생성자
	~Rectangle();	// 함수 소멸자

	void Init(int width, int height);	// 변수 초기화

	void Area();	// 넓이
	void Lenght();	// 둘레

	void PrintInfo();	// 콘솔 화면에 Rectangle의 정보 출력

};

