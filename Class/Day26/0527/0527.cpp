#include <iostream>
#include <map>
#include <string>
/*
    map<Key(first),Value>  
    std::map <int, int> mapInt;     // Map 선언   

    // 선언 및 초기화
    std::map <int, std::string> mapString = {{1,"Hello"}, {2, "World"}, {30, "Hello World"}};

    // 접근 방법
    mapInt[Key] = Value;        // mapInt의 key에 value값 저장
    int temp = mapInt[Key];     // 

    // 요소 삭제
    map.erase(Key)       // Key에 해당하는 데이터 삭제 
    mapString.erase(1);  // {1,"Hello"} 삭제


*/

std::map <int, int> mapInt;
std::map <int, std::string> mapString;


int main(){

    mapString[1] = "Hello";
    mapString[2] = "World";
    mapString[10] = "Hello, ";
    mapString[20] = " World";

    for(auto it = mapString.begin(); it != mapString.end(); ++it){
        std::cout << "Key : " << it->first << ", Value : " << it->second << std::endl;
    }

    mapString.erase(10);

    std::cout << "============ erase ============" << std::endl;
    for (auto it = mapString.begin(); it != mapString.end(); ++it) {
        std::cout << "Key : " << it->first << ", Value : " << it->second << std::endl;
    }
}
