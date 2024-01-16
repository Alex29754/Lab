//ƒана последовательность натуральных чисел{ aj }j = 1...n(n <= 10000).
//≈сли в последовательности есть хот€ бы одно число, начинающеес€ цифрой 1,
//упор€дочить последовательность по неубыванию.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool startsWithOne(int number) {
    while (number >= 10) {
        number /= 10;
    }
    return number == 1;
}
int main() {
    vector<int> sequence;
    setlocale(LC_ALL, "Russian");
    // ¬вод последовательности
    int n;
    cout << "¬ведите количество чисел в последовательности: ";
    cin >> n;
    cout << "¬ведите числа последовательности:\n";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num; 
        sequence.push_back(num);
    }
    // ѕроверка, содержит ли последовательность число, начинающеес€ с 1
    bool containsOne = false;
    for (int num : sequence) {
        if (startsWithOne(num)) {
            containsOne = true;
            break;
        }
    }
    // ≈сли последовательность содержит число, начинающеес€ с 1, упор€дочить последовательность по неубыванию
    if (containsOne) {
        sort(sequence.begin(), sequence.end());
        cout << "”пор€доченна€ последовательность:\n";
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << endl;
    }
    else {
        cout << "¬ последовательности нет чисел, начинающихс€ с 1.\n";
    }
    return 0;
}