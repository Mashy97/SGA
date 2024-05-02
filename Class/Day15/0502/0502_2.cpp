#include "stdafx.h"

// 접근 제어자인 protected는 해당 멤버 변수나 함수를 상속받는 자식 클래스에서 접근할 수 있지만
// 외부에서는 직접 접근할 수 없도록 설정 
class Parent {
protected:
	int prot_Var;

public:
	Parent()
		: prot_Var(0) {

	}

	void setProtVar(int value) {
		prot_Var = value;
	}

	int getProtVar() const {
		return prot_Var;
	}
};
class Child : public Parent {
public:
	void accessProt(int value) {
		prot_Var = value;
	}

	void displayProt() {
		cout << "Protected variable: " << prot_Var << endl;
	}

};


int main() {
	Child child;
	// child.prot_Var = 10;		// 에러 발생 - access 불가
	child.setProtVar(100);
	child.displayProt();
	child.accessProt(50);
	child.displayProt();
	
}