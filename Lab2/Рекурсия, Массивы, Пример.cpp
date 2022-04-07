// Суммирование массива методом сдваивания
# include <iostream>

using namespace std;

int foo(int arr[], int n) {

    int arr_[n];

    // Условие для выхода из рекурсии
    if (n == 1)
        return arr[0];

    int j = 0;
    for (int i = 0; i < n; i = i + 2) {
        if (i + 1 == n) {
            arr_[j] = arr[i];
        }else{
            arr_[j] = arr[i] + arr[i + 1];
        }

        j++;
    }

    return foo(arr_, j);

}

int main() {

    setlocale(LC_ALL, "rus");

    int n = 12, result = 0;
    int an_array[n]{1,2,3,4,5,6,7,8,9,10,11,12};
    result = foo(an_array, n);

    cout << result << endl;

    return 0;

}
