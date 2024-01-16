//���� ������������������ ����������� �����{ aj }j = 1...n(n <= 10000).
//���� � ������������������ ���� ���� �� ���� �����, ������������ ������ 1,
//����������� ������������������ �� ����������.

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
    // ���� ������������������
    int n;
    cout << "������� ���������� ����� � ������������������: ";
    cin >> n;
    cout << "������� ����� ������������������:\n";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num; 
        sequence.push_back(num);
    }
    // ��������, �������� �� ������������������ �����, ������������ � 1
    bool containsOne = false;
    for (int num : sequence) {
        if (startsWithOne(num)) {
            containsOne = true;
            break;
        }
    }
    // ���� ������������������ �������� �����, ������������ � 1, ����������� ������������������ �� ����������
    if (containsOne) {
        sort(sequence.begin(), sequence.end());
        cout << "������������� ������������������:\n";
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << endl;
    }
    else {
        cout << "� ������������������ ��� �����, ������������ � 1.\n";
    }
    return 0;
}