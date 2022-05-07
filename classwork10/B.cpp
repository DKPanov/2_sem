#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

uint64_t value_i(int i, int* result, int* arr){
    if (result[i] != -1){
        return result[i];
    }
    result[i] = min(value_i(i-1, result, arr), min(value_i(i-2, result, arr), value_i(i-3, result, arr))) + arr[i]; //рекурсия: минимальная цена до (i+1)-ой ступеньки
    return result[i];
}


uint64_t value(int N, int* arr){   //минимальная цена, чтобы дойти до ступеньки N
    int* result = new int[N];
    for (int i = 0; i < N; i++){
        result[i] = -1;
    }
    result[0] = arr[0]; //первая ячейка
    result[1] = arr[1];
    result[2] = arr[2];
    uint64_t answer = value_i(N - 1, result, arr);

    delete[] result;

    return answer;
}



int main() {

    int N;
    cin >> N;

    int* arr = new int[N];

    for (int i = 0; i < N; i++){   //массив цен
        cin >> arr[i];
    }

    cout << value(N, arr);

    delete[] arr;

    return 0;
}
