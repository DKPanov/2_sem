#include <iostream>
#include <iomanip>

using namespace std;

int** solution(int** matrix, int N, int M){

    int** answer = new int* [N];
    for (int i = 0; i < N; i++){
        answer[i] = new int[M];
        for (int j = 0; j < M; j++){
            answer[i][j] = 0;
        }
    }

    int k = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (matrix[i][j] == 1){
                matrix[i][j] = 0;
                matrix[j][i] = 0;
                answer[i][k] = 1;
                answer[j][k] = 1;
                k++;
            }
        }
     }

     return answer;
}

int main() {
    setlocale (LC_ALL, "rus");

    int N;
    int M = 0; //число ребер
    cin >> N; //число вершин

    int** matrix = new int* [N];

    int count = 0;
    for (int i = 0; i < N; i++){
        matrix[i] = new int[N];
        for (int j = 0; j < N; j++){
            cin >> matrix[i][j];
            if (matrix[i][j] == 1){
                count++;
            }
        }
    }

    M = count / 2;

    int** answer = solution(matrix, N, M);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }



    for (int i = 0; i < N; i++){
            delete[] answer[i];
            delete[] matrix[i];
    }

    delete[] answer;
    delete[] matrix;

    return 0;
}
