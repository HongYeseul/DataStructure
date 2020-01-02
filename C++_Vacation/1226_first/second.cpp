#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
    cout << "Hello World" << endl; //yy 한줄 복사 
    cout << "Hello World\n"; // same

    std::cout << "Hello World" << std::endl; // using namespace없을 때 사용 
    //scope 연산자 std에 정의돼있는 cout을 사용해라
    
    string s1("hello");
    string s2("world");
    string s3 = s1+s2;
    cout << s3 << endl;
    //shitf + i 제일 앞 글씨 
    //소문자 o 기능은 다음줄
    //shift + o 전줄


    return 0;
}
