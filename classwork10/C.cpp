#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int64_t INF = 9999999999;

int bin_poisk(int N, int64_t* arr, int k){ //ищем  первый элемент массива, >=k
    int left = -1;
    int right = N;
    while (true){
        int mid = (left + right)/2;
        if (arr[mid] < k){   //поэтому положим -INF в last_elements[0]
            left = mid;
            continue;
        }

        if (arr[mid-1] < k){ //nr gjlgjck cnhjuj djphfcn
            return mid;
        }

        right = mid;
    }

}

int subsequence(int N, int* arr){
    int64_t* last_elements = new int64_t[N + 1];
    int answer = 0;

    last_elements[0] = -INF;
    for(int i = 1; i < N + 1; i++){
        last_elements[i] = INF; //число, кот меньше лежащего в данной €чейке сейчас, но больше числа в предыдущей €чейке
    }

    for(int i = 0; i < N; i++){
        int pos = bin_poisk(N+1, last_elements, arr[i]); //подпосл-ть какой длины arr[i] может улучшить
        if (last_elements[pos] == INF){
            answer++;
        }
        last_elements[pos] = arr[i];
    }

    delete[] last_elements;

    return answer;

}

int main() {

    int N;
    cin >> N;

    int* arr = new int[N];

    for (int i=0; i < N; i++){
        cin >> arr[i];
    }

    cout << subsequence(N, arr);

    delete[] arr;

    return 0;
}
