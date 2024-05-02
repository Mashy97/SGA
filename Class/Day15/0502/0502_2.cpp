#include "stdafx.h"

// ���� �������� protected�� �ش� ��� ������ �Լ��� ��ӹ޴� �ڽ� Ŭ�������� ������ �� ������
// �ܺο����� ���� ������ �� ������ ���� 
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
	// child.prot_Var = 10;		// ���� �߻� - access �Ұ�
	child.setProtVar(100);
	child.displayProt();
	child.accessProt(50);
	child.displayProt();
	
}