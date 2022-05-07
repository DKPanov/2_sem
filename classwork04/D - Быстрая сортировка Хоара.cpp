#include <iostream>

using namespace std;

void QuickSort(int *arr, int first, int last)
{
    int el, value;
    int f = first, l = last;

    // Выбираем опорный элемент (например самый правый элемент)
    el = arr[l];
    while (f < l) {

        while (arr[f] < el) f++;
        while (arr[l] > el) l--;

        // Переставляем элементы в массиве
        if (f <= l) {
            value = arr[f];
            arr[f] = arr[l];
            arr[l] = value;
            f++;
            l--;
        }
    }

    if (first < l) QuickSort(arr, first, l);
    if (f < last) QuickSort(arr, f, last);
}

int main(){

    setlocale(LC_ALL, "rus");

    int n;
    cout << "Введите размер массива n " << endl;
    cin >> n;

    int an_array[n];
    cout << "Введите последовательность n чисел " << endl;
    for (int i = 0; i < n; i++) cin >> an_array[i];

    QuickSort(an_array, 0, n - 1);
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << an_array[i] << " ";
    }

    return 0;
}
