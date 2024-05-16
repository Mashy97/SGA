#include "stdafx.h"

// namespace, 변수 
// namespace - 코드에서 이름 충돌을 방지하기 위해 사용
/*
namespace 변수명{


}
*/

namespace MyNameSpace { // namespace
    int value = 1000;   
}
int value = 3000;

using namespace MyNameSpace;
int main(){
    // local, global, namespace 확인
    int value = 4000;   // local 변수

    std::cout << "Local Value : " << value << std::endl;    // 로컬 변수 출력 - 4000
    std::cout << "Global Value : " << ::value << std::endl;     // 전역 변수 출력 - 3000 
    std::cout << "NameSpace Value : " << MyNameSpace::value << std::endl;   // namespace 출력 - 1000

    return 0;
}
