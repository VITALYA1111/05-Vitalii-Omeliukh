#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Funkcja do porównania cyfr
bool compareDigits(char a, char b) {
    return a > b; // Porównujemy cyfry w odwrotnej kolejności (większa cyfra pierwsza)
}
// Funkcja do stworzenia największej liczby z cyfr (algorytm 1)
string findLargestNumberFromDigits(int arr[], int size) {
    string digits = ""; // Tworzymy pusty ciąg znaków do przechowywania wszystkich cyfr
    // Przekształcamy każdą liczbę na cyfry i dodajemy je do ciągu
    for (int i = 0; i < size; ++i) {
        string strNum = to_string(arr[i]);
        digits += strNum; // Dodajemy wszystkie cyfry liczby do ciągu
    }
    // Sortujemy cyfry w odwrotnej kolejności
    sort(digits.begin(), digits.end(), compareDigits);

    // Jeśli pierwsza cyfra to '0', oznacza to, że wszystkie cyfry są zerami, więc zwracamy "0"
    if (digits[0] == '0') {
        return "0";
    }
    return digits; // Zwracamy wynik jako posortowany ciąg
}

// Funkcja do stworzenia największej liczby z liczb w tablicy (algorytm 2)
string findLargestNumberFromArray(const vector<int>& arr) {  // Zmieniamy na const reference
    vector<char> digits; // Wektor do przechowywania wszystkich cyfr
    // Przekształcamy każdą liczbę na cyfry i dodajemy je do wektora
    for (int num : arr) {
        string strNum = to_string(num);
        for (char digit : strNum) {
            digits.push_back(digit); // Dodajemy każdą cyfrę osobno
        }
    }
    // Sortujemy cyfry w odwrotnej kolejności
    sort(digits.begin(), digits.end(), compareDigits);

    // Jeśli pierwsza cyfra to '0', oznacza to, że wszystkie cyfry są zerami, więc zwracamy "0"
    if (digits[0] == '0') {
        return "0";
    }
    // Tworzymy wynik z posortowanych cyfr
    string result = "";
    for (char digit : digits) {
        result += digit;
    }
    return result;
}
int main() {
    // Test 1: Ciąg liczb z samymi zerami
    int test1[] = {0, 0, 0, 0};
    cout << "Test 1 (same zera): " << findLargestNumberFromDigits(test1, 4) << endl;
    cout << "Test 1 (same zera, algorytm 2): " << findLargestNumberFromArray(vector<int>{0, 0, 0, 0}) << endl;

    // Test 2: Ciąg liczb w porządku nierosnącym
    int test2[] = {987, 654, 321};
    cout << "Test 2 (nierosnace): " << findLargestNumberFromDigits(test2, 3) << endl;
    cout << "Test 2 (nierosnace, algorytm 2): " << findLargestNumberFromArray(vector<int>{987, 654, 321}) << endl;

    // Test 3: Ciąg liczb z powtarzającymi się cyframi
    int test3[] = {111, 222, 333};
    cout << "Test 3 (powtarzajace sie cyfry): " << findLargestNumberFromDigits(test3, 3) << endl;
    cout << "Test 3 (powtarzajace sie cyfry, algorytm 2): " << findLargestNumberFromArray(vector<int>{111, 222, 333}) << endl;
    return 0;
}

