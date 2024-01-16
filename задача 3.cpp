//Дана целочисленная матрица{ Aij }i = 1..n, j = 1..m(n, m <= 100).
//Найти строку, сумма элементов которой наиболее близка к 0, и заменить все элементы этой строки числом 0.

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

int main() {
    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    int closestRow = 0;
    int minSumDiff = numeric_limits<int>::max();

    for (int i = 0; i < rows; ++i) {
        int sum = 0;
        for (int j = 0; j < cols; ++j) {
            sum += matrix[i][j];
        }
        int sumDiff = abs(sum);
        if (sumDiff < minSumDiff) {
            closestRow = i;
            minSumDiff = sumDiff;
        }
    }

    for (int j = 0; j < cols; ++j) {
        matrix[closestRow][j] = 0;
    }

    cout << "Измененная матрица:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}