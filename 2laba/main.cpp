#include <iostream>
#include <cmath>

class Square {
private:
    float side_length;

public:
    Square(float side) {
        side_length = side;
    }

    float calculateArea() {
        return side_length * side_length;
    }

    float calculatePerimeter() {
        return 4 * side_length;
    }

    float calculateDiagonalLength() {
        return sqrt(2) * side_length;
    }
};

int main() {
    Square square1(10);
    std::cout << "Area: " << square1.calculateArea() << std::endl;
    std::cout << "Perimeter: " << square1.calculatePerimeter() << std::endl;
    std::cout << "Diagonal length: " << square1.calculateDiagonalLength() << std::endl;
    return 0;
}