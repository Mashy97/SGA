#include "stdafx.h"
#include "Rectangle.h"

int main()
{	
	Rectangle m_rect;		// 하나의 변수, 배열, 포인터 생성 가능
	Rectangle a_rect[2];	// 배열 형태로 생성

	m_rect.Init(5, 5);
	m_rect.Area();
	m_rect.Lenght();
	m_rect.PrintInfo();

	// 포인터 형태 생성
	Rectangle* p_rect = new Rectangle();	// 메모리 생성

	p_rect->Init(50, 10);
	p_rect->Area();
	p_rect->Lenght();
	p_rect->PrintInfo();

	delete p_rect;	// 메모리 해제

	// 배열 + 포인터
	Rectangle* pa_rect = new Rectangle[3];	// 메모리 생성 - pa_rect에 Rectangle 3개가 들어있는 메모리의 시작 주소를 지정
											
	for (int i = 0; i < 3; i++) {						// pa_rect는 Rectangle의 포인터 형태
		(pa_rect + i)->Init((i + 1) * 5, (i + 1) * 5);	// pa_rect[i].Init(a,b)는 배열을 직접 나타내며 값을 입력
		(pa_rect + i)->Area();							// (pa_rect + i)는 배열의 주소를 나타내며 해당 주소에 값을 입력
		(pa_rect + i)->Lenght();						
		(pa_rect + i)->PrintInfo();
	}

	delete[] pa_rect;	// 배열 형태 메모리 해제

	return 0;

}
