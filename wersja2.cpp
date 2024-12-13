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
string findLargestNumberFromArray(vector<int>& arr) {
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
    int size;
    cout << "Ile liczb chcesz wprowadzic? ";
    cin >> size;

    int arr[size]; // Tablica do przechowywania liczb
    vector<int> vecArr; // Wektor do drugiego algorytmu
    // Wprowadzamy liczby
    for (int i = 0; i < size; ++i) {
        cout << "Wprowadz liczbe #" << (i + 1) << ": ";
        cin >> arr[i];
        vecArr.push_back(arr[i]); // Dodajemy liczbę do wektora
    }
    // Wywołujemy pierwszy algorytm2

    string largestNumber1 = findLargestNumberFromDigits(arr, size);
    cout << "Najwieksza liczba z cyfr (Algorytm 1): " << largestNumber1 << endl;
    // Wywołujemy drugi algorytm
    string largestNumber2 = findLargestNumberFromArray(vecArr);
    cout << "Najwieksza liczba z tablicy (Algorytm 2): " << largestNumber2 << endl;

    return 0;
}
