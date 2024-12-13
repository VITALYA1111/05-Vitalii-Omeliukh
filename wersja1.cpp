#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool compareDigits(char a, char b) {
    return a > b; // Порівнюємо цифри в зворотньому порядку
}
string findLargestNumber(int arr[], int size) {
    string digits = ""; // Створюємо порожній рядок для зберігання всіх цифр
    for (int i = 0; i < size; ++i) {
        string strNum = to_string(arr[i]);
        digits += strNum;
    }
    sort(digits.begin(), digits.end(), compareDigits);
    if (digits[0] == '0') {
        return "0";
    }

    return digits; // Повертаємо результат як відсортований рядок
}
int main() {
    int size;
    cout << "How many numbers do you want to input? ";
    cin >> size;

    int arr[size]; // Масив для зберігання чисел
    for (int i = 0; i < size; ++i) {
        cout << "Enter number #" << (i + 1) << ": ";
        cin >> arr[i];
    }
    string largestNumber = findLargestNumber(arr, size);
    cout << "The largest possible number is: " << largestNumber << endl;
    return 0;
}
