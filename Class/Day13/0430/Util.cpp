#include "Util.h"

void Util::myprint()
{
    string username;
    username = "홍길동";

    cout << username << endl;

#ifdef _DEBUG   // 만약 Debug 실행 중 이라면
    cout << "Hello World!\n";
#endif
}
