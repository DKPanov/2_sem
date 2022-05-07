#include <iostream>

using namespace std;

void QuickSort(int *arr, int first, int last)
{
    int el, value;
    int f = first, l = last;

    // �������� ������� ������� (�������� ����� ������ �������)
    el = arr[l];
    while (f < l) {

        while (arr[f] < el) f++;
        while (arr[l] > el) l--;

        // ������������ �������� � �������
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
    cout << "������� ������ ������� n " << endl;
    cin >> n;

    int an_array[n];
    cout << "������� ������������������ n ����� " << endl;
    for (int i = 0; i < n; i++) cin >> an_array[i];

    QuickSort(an_array, 0, n - 1);
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << an_array[i] << " ";
    }

    return 0;
}
