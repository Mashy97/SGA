#include <iostream>
#include <string>
#include <vector>
// Template

// 더하기 a + b = c
/*
int Add(int a, int b)       // int add
{
    int c = a + b;
    return c;
}

float Add(float a, float b)     // float add
{
    float c = a + b;
    return c;
}

double Add(double a, double b)  // double add
{
    double c = a + b;
    return c;
}
*/

// Template - 데이터 타입에 독립적인 함수를 작성하는 방식  
// Template 생성 
// 함수 호출 시 컴파일러가 타입을 추론하여 인스턴스화
template<typename T>
T Add(T a, T b) {
    T c = a + b;
    return c;
}

// Template class
// template <typename T1, typename T2> 등으로 다른 변수형태를 사용해야 할 경우
// T1, T2 등 여러개를 생성하여 사용이 가능하다.
template<typename T>
class MyClass
{
private:
    T data;
public:
    MyClass(T d) : data(d) {}
    ~MyClass() {}
    T getData() { return data; }
};


int main()
{
    
    int Itemp = Add(50, 100);                   // template를 사용하여 int, float, double 등을 선언하여 정의하지 않아도
    float Ftemp = Add(10.3f, 12.3f);            // 원하는 형태로 사용, 변형이 가능하다.
    double Dtemp = Add(12.13215, 15.132132);
    
    
    MyClass<int> intObj(5);
    std::cout << intObj.getData() << std::endl;
    MyClass<std::string> strObj("str");
    std::cout << strObj.getData() << std::endl;


    // Lambda - 익명 함수를 생성하고 전달하는데 사용되는 함수형
    // 간결하게 표현하고	코드를 간소화 하는데 활용

    // 간단한 정수를 더하는 람다 함수
    // [&], [=] 등 캡쳐 표현식
    // 즉, 람다 함수에서 외부변수를 변경할 수 있다.
    
    // 람다 선언, 사용 예시
    // 1. [&] 외부 변수를 람다함수 내에세 참조하여 캡쳐한다.
    // 외부 변수 값 변경 가능
    int temp = 5;
    auto add = [&](int a, int b) -> int {
        temp++;
        a += temp;
        return a + b;
        };
    int result = add(10, 20);
    std::cout << result << std::endl;
    
    // 2. [=] 외부 변수를 함수내로 가져와 사용하는 것 , 일기 전용
    // 외부 변수 값 변경 불가능
    auto x = 5;
    auto Lambda = [=]() -> int {
        int y = x * 2;
        return y;
        };

    int lambda = Lambda();

    std::cout << lambda << std::endl;


    return 0;
}
