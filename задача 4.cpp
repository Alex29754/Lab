#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void duplicatePrimes(vector<int>& sequence) {
    vector<int> result;
    for (int num : sequence) {
        if (to_string(num).find('7') != string::npos && to_string(num).find('6') == string::npos) {
            continue;
        }
        if (isPrime(num)) {
            result.push_back(num);
        }
        result.push_back(num);
    }
    sequence = result;
}

int main() {
    int n;
    cout << "Enter the size of the sequence: ";
    cin >> n;

    vector<int> sequence(n);
    cout << "Enter the sequence: ";
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    duplicatePrimes(sequence);

    cout << "Modified sequence: ";
    for (int num : sequence) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
