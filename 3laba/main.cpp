#include <iostream>
#include <cstring>
using namespace std;
class String {
private:
    char* str;

public:
    String(const char* s = "") {
        str = new char[strlen(s) + 1];
        copy(s, s + strlen(s) + 1, str);
    }

    String(const String& other) : String(other.str) {}

    String& operator=(const String& other) {
    if (this != &other) {
        delete[] str;
        str = new char[strlen(other.str) + 1];
        copy(other.str, other.str + strlen(other.str) + 1, str);
        }
        return *this;
    }

    ~String() {
        delete[] str;
    }

    void print() {
        cout << str << std::endl;
    }
};

int main() {
    String s1("Hello, world!!!");
    String s2 = s1; // »спользование конструктора копировани€
    s2.print();

    String s3;
    s3 = s1; // »спользование оператора присваивани€ копировани€
    s3.print();

    return 0;
}