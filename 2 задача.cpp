#include <iostream>
#include <vector>
#include <algorithm>

// Функция для получения суммы цифр числа
int getDigitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Функция для сравнения чисел при сортировке
bool compareNumbers(int a, int b) {
    int firstDigitA = a, firstDigitB = b;

    while (firstDigitA >= 10) {
        firstDigitA /= 10;
    }
    while (firstDigitB >= 10) {
        firstDigitB /= 10;
    }

    if (firstDigitA != firstDigitB) {
        return firstDigitA < firstDigitB;
    }
    else {
        int sumA = getDigitSum(a);
        int sumB = getDigitSum(b);
        if (sumA != sumB) {
            return sumA < sumB;
        }
        else {
            return a < b;
        }
    }
}

int main() {
    int n;
    std::cout << "Введите количество чисел: ";
    std::cin >> n;

    std::vector<int> numbers(n);

    std::cout << "Введите последовательность чисел:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    // Сортировка чисел
    std::sort(numbers.begin(), numbers.end(), compareNumbers);

    // Вывод отсортированной последовательности
    std::cout << "Отсортированная последовательность:\n";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}