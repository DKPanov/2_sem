#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// uint64_t - типа "unsigned int", 64 бита
uint64_t qty_i(int i, int* result){    //рекурсивная функция: рекурсивно вычисляем кол-во способов достичь ступень (i+1)
    if (result[i] != -1){
        return result[i];
    }
    result[i] = qty_i(i-1, result) + qty_i(i-2, result) + qty_i(i-3, result); //Кол-во способов дойти до (i+1)-й ступеньки
    return result[i];
}


uint64_t qty(int N){   //функция, вычисляющая кол-во способов достичь ступень N
    int* result = new int[N];
    for (int i = 0; i < N; i++){
        result[i] = -1;
    }
    result[0] = 1;    //элемент массива result[i] - кол-во способов дойти до (i+1)-й ступеньки
    result[1] = 1;
    result[2] = 2;    //кол-во способов дойти до след ступеньки есть сумма от трех пред ступенек, если они есть
    uint64_t answer = qty_i(N - 1, result); //количество способов дойти до ступеньки N

    delete[] result;

    return answer;
}



int main() {

    int N;
    cin >> N;


    cout << qty(N + 1);

    return 0;
}
