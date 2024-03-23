#include <iostream>
#include <string>

class MyString {
private:
    std::string str;

public:
    MyString(const std::string& s) : str(s) {}

    MyString(const MyString& other) : str(other.str) {}

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            str = other.str;
        }
        return *this;
    }

    ~MyString() {
    }

    void print() {
        std::cout << str << std::endl;
    }
};

int main() {
    MyString str1("Hello");
    MyString str2 = str1; // Copy constructor
    MyString str3("World");
    str3 = str2; // Copy assignment operator

    str1.print();
    str2.print();
    str3.print();

    return 0;
}