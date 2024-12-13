#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <filesystem>
using namespace std;

// Funkcja do porownywania cyfr
bool compareDigits(char a, char b) {
    return a > b; // Porownujemy cyfry w odwrotnej kolejnosci (wieksza cyfra pierwsza)
}

// Funkcja do tworzenia najwiekszej liczby z cyfr (algorytm 1)
string findLargestNumberFromDigits(int arr[], int size) {
    string digits = ""; // Tworzymy pusty ciag do przechowywania wszystkich cyfr
    for (int i = 0; i < size; ++i) {
        string strNum = to_string(arr[i]);
        digits += strNum; // Dodajemy wszystkie cyfry liczby do ciagu
    }
    sort(digits.begin(), digits.end(), compareDigits);

    if (digits[0] == '0') {
        return "0"; // Jesli pierwsza cyfra to '0', zwracamy "0"
    }
    return digits; // Zwracamy wynik jako posortowany ciag
}

// Funkcja do tworzenia najwiekszej liczby z tablicy liczb (algorytm 2)
string findLargestNumberFromArray(vector<int>& arr) {
    vector<char> digits; // Wektor do przechowywania wszystkich cyfr
    for (int num : arr) {
        string strNum = to_string(num);
        for (char digit : strNum) {
            digits.push_back(digit); // Dodajemy kazda cyfre osobno
        }
    }
    sort(digits.begin(), digits.end(), compareDigits);

    if (digits[0] == '0') {
        return "0"; // Jesli pierwsza cyfra to '0', zwracamy "0"
    }

    string result = "";
    for (char digit : digits) {
        result += digit;
    }

    return result;
}

// Funkcja do testowania algorytmu 1 z tablica
void benchmarkAlgorithm1Array() {
    string path = "result_array_algorithm1.csv";
    ofstream file(path);
    if (!file.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku do zapisu: " << path << endl;
        return;
    }

    file << "n,t" << endl;

    for (int n = 1000; n <= 80000; n += 1000) {
        int* arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % 10000;
        }

        auto start = chrono::high_resolution_clock::now();
        findLargestNumberFromDigits(arr, n);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        file << n << "," << duration.count() << endl;

        delete[] arr; // Usuwamy dynamicznie przydzielona tablice
    }

    file.close();
    cout << "Wyniki zapisane do pliku " << path << endl;
}

// Funkcja do testowania algorytmu 2 z tablica
void benchmarkAlgorithm2Array() {
    string path = "result_array_algorithm2.csv";
    ofstream file(path);
    if (!file.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku do zapisu: " << path << endl;
        return;
    }

    file << "n,t" << endl;

    for (int n = 1000; n <= 80000; n += 1000) {
        int* arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % 10000;
        }

        auto start = chrono::high_resolution_clock::now();
        findLargestNumberFromDigits(arr, n);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        file << n << "," << duration.count() << endl;

        delete[] arr; // Usuwamy dynamicznie przydzielona tablice
    }

    file.close();
    cout << "Wyniki zapisane do pliku " << path << endl;
}

// Funkcja do testowania algorytmu 1 z wektorem
void benchmarkAlgorithm1Vector() {
    string path = "result_vector_algorithm1.csv";
    ofstream file(path);
    if (!file.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku do zapisu: " << path << endl;
        return;
    }

    file << "n,t" << endl;

    for (int n = 1000; n <= 80000; n += 1000) {
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i] = rand() % 10000;
        }

        auto start = chrono::high_resolution_clock::now();
        findLargestNumberFromArray(vec);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        file << n << "," << duration.count() << endl;
    }

    file.close();
    cout << "Wyniki zapisane do pliku " << path << endl;
}

// Funkcja do testowania algorytmu 2 z wektorem
void benchmarkAlgorithm2Vector() {
    string path = "result_vector_algorithm2.csv";
    ofstream file(path);
    if (!file.is_open()) {
        cerr << "Nie udalo sie otworzyc pliku do zapisu: " << path << endl;
        return;
    }

    file << "n,t" << endl;

    for (int n = 1000; n <= 80000; n += 1000) {
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i] = rand() % 10000;
        }

        auto start = chrono::high_resolution_clock::now();
        findLargestNumberFromArray(vec);
        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> duration = end - start;
        file << n << "," << duration.count() << endl;
    }

    file.close();
    cout << "Wyniki zapisane do pliku " << path << endl;
}

int main() {
    // Deklaracja zmiennych arr i size dla algorytmu 1
    const int size = 5; // Mozesz ustawic inna wielkosc
    int arr[size] = { 9, 81, 10, 8, 2 }; // Przykladowe dane do algorytmu 1

    // Deklaracja zmiennej vecArr dla algorytmu 2
    vector<int> vecArr = { 9, 81, 10, 8, 2 }; // Przykladowe dane do algorytmu 2

    string largestNumber1 = findLargestNumberFromDigits(arr, size);
    cout << "Najwieksza liczba z cyfr (Algorytm 1): " << largestNumber1 << endl;

    string largestNumber2 = findLargestNumberFromArray(vecArr);
    cout << "Najwieksza liczba z tablicy (Algorytm 2): " << largestNumber2 << endl;

    benchmarkAlgorithm1Array();
    benchmarkAlgorithm2Array();
    benchmarkAlgorithm1Vector();
    benchmarkAlgorithm2Vector();

    // Usuwanie nie jest potrzebne, bo uzywamy zmiennych lokalnych (na stosie)
    return 0;
}

