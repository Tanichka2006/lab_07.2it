#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void Create(int** a, const int rows, const int cols, const int Low, const int High);
void Print(int** a, const int rows, const int cols);
void SwapMinMaxInColumns(int** a, const int rows, const int cols);

int main() {
    srand((unsigned)time(NULL));
    const int rows = 5;
    const int cols = 6;
    const int Low = -10;
    const int High = 20;

    int** a = new int* [rows];
    for (int i = 0; i < rows; i++)
        a[i] = new int[cols];

    Create(a, rows, cols, Low, High);
    cout << "Initial Matrix:" << endl;
    Print(a, rows, cols);

    SwapMinMaxInColumns(a, rows, cols);
    cout << "Modified Matrix:" << endl;
    Print(a, rows, cols);

    for (int i = 0; i < rows; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

// Функція створення матриці
void Create(int** a, const int rows, const int cols, const int Low, const int High) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Функція для виведення матриці
void Print(int** a, const int rows, const int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// Функція для обміну мінімального елемента парного стовпця з максимальним у попередньому непарному
void SwapMinMaxInColumns(int** a, const int rows, const int cols) {
    for (int j = 1; j < cols; j += 2) {
        int minRow = 0, maxRow = 0;
        for (int i = 1; i < rows; i++) {
            if (a[i][j] < a[minRow][j])
                minRow = i;
            if (a[i][j - 1] > a[maxRow][j - 1])
                maxRow = i;
        }
        // Обмін значень
        int temp = a[minRow][j];
        a[minRow][j] = a[maxRow][j - 1];
        a[maxRow][j - 1] = temp;
    }
}
