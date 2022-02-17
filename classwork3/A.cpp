#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int array[N];

    for (int i = 0; i < N; i++){  //¬водим данные, записываем в массив
        cin >> array[i];
    }

    cout << "Source array: ";
    for (int i = 0; i < N; i++){
        cout << array[i] << " ";
    }

    int x = 0;
    int i = 1;
    while (i < N) {
        if (array[i-1] <= array[i]) {
            i++;
        } else {
            x = array[i];
            array[i] = array[i-1];
            array[i - 1] = x;
            }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < N; i++){
        cout << array[i] << " ";
    }

    return 0;

}
