#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

uint64_t value_ij(int i, int j, int** result, int* arr){ //рекурсивная функция: считаем мин цену, чтобы распилить брусок ij, где i,j - рисочки
    if (result[i][j] != -1){
        return result[i][j];
    }
    if (j == i + 1){
        result[i][j] = 0;
        return result[i][j];
    }

    int min = -1; //мин из возможных цен, мин сумма чтобы допилить бруски кот получатся после распила ij на две части
    for (int w = i + 1; w < j; w++){
        int current = value_ij(i, w, result, arr) + value_ij(w, j, result, arr);  //сумма для допила каждой из рисочек получившихся кусков
        if (min == -1 || min > current){
            min = current;
        }
    }

    result[i][j] = arr[j] - arr[i] + min;

    return result[i][j];
}


uint64_t value(int N, int M, int* arr){

    int** result = new int*[M+2];   //result[i][j] - кол-во способов распилить от i до j; размер массива M+2, тк включили границы доски
    for (int i = 0; i < M + 2; i++){
        result[i] = new int[M+2];
        for (int j = 0; j < M + 2; j++){
            result[i][j] = -1;
        }
    }

    int* correct_arr = new int[M + 2]; // Поместим координаты рисочек и границ
    correct_arr[0] = 0;   //correct_arr[i] - i-я метка (нумерация с 0)
    for (int i = 1; i < M + 1; i++){
        correct_arr[i] = arr[i - 1];
    }
    correct_arr[M + 1] = N;

    int answer = value_ij(0, M + 1, result, correct_arr);

    for (int i = 0; i < M + 2; i++){
        delete[] result[i];
    }

    delete[] result;

    delete[] correct_arr;

    return answer;
}



int main() {

    int N;
    cin >> N;

    int M;
    cin >> M;

    int* arr = new int[M];

    for (int i = 0; i < M; i++){
        cin >> arr[i];
    }

    cout << value(N, M, arr);

    delete[] arr;

    return 0;
}
