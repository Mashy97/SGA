#include "Util.h"

void Util::myprint()
{
    string username;
    username = "ȫ�浿";

    cout << username << endl;

#ifdef _DEBUG   // ���� Debug ���� �� �̶��
    cout << "Hello World!\n";
#endif
}
