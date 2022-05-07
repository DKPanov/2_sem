// Гномья сортировка

# include <iostream>
# include <algorithm>

using namespace std;

//void Swap (int & a, int & b) {
//    int temp = a;
//    a = b;
//    b = temp;
//}

int main() {

    setlocale (LC_ALL, "rus");

    int i = 1, j = 2;
    int an_array[] = {4, 2, 7, 9};

    cout << "Массив до сортировки:" << "\n";
    for (const int &n : an_array) {
        cout << n << " | ";
    }

    // Длина массива
    const int SIZE = sizeof(an_array)/sizeof(*an_array);

    while (i < SIZE) {
        if (an_array[i - 1] > an_array[i]) { //для сортировки по возрастанию нужно поменять знак сравнения на <
            i = j;
            j = j + 1;

        }else{
            swap(an_array[i - 1], an_array[i]);
            i = i - 1;

            if (i == 0) {
                i = j;
                j = j + 1;
            }
        }
    }

    cout << "\n\n" << "Массив после сортировки:" << "\n";
    for (const int &n : an_array) {
        cout << n << " | ";
    }

    return 0;

}
