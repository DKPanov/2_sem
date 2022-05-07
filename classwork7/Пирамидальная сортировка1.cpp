/* Общая идея пирамидальной сортировки заключается в том,
что сначала строится пирамида из элементов исходного массива,
а затем осуществляется сортировка элементов. */

#include <iostream>

using namespace std;

// Вывод массива на экран
void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << "\n";
}

// Функция для построения дерева
// Создает дерево так чтобы максимальный элемент оказался вверху пирамиды
void heapify(int arr[], int n, int root) {

    int largest = root; // Корневой элемент - самый большой элемент

    // Формируем двоичное дерево такое, что
    // a[i] ≤ a[2i+1];
    // a[i] ≤ a[2i+2]

    int l = 2*root + 1; // left = 2*root + 1
    int r = 2*root + 2; // right = 2*root + 2

    //cout << "l = " << l << " r = " << r << "---------" << endl;

    // Если левый дочерний элемент больше корневого
    if (l < n && arr[l] > arr[largest])
    largest = l;

    // Если правый дочерний элемент больше, чем самый большой на данный момент
    if (r < n && arr[r] > arr[largest])
    largest = r;

   // Если самый большой не является корневым
   if (largest != root) {
        // Меняем местами корневой и самый большой
        swap(arr[root], arr[largest]);

        // Рекурсивно создаем поддерево
        heapify(arr, n, largest);

    //PrintArray(arr, n);
    //cout << "-----------------------------------" << endl;
    }

}

// Реализация сортировки кучи
void heapSort(int arr[], int n) {
    // Создание кучи
    // Расположим элементы в виде исходной пирамиды
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Извлечение элементов из кучи один за другим
    for (int i = n - 1; i >= 0; i--) {
        // Перемещаем текущий элемент в конец
        swap(arr[0], arr[i]);

        // Повторный вызов max heapify для уменьшенной кучи
        heapify(arr, i, 0);

   }
}



int main() {

    setlocale(LC_ALL, "rus");

    int n = 6;
    int an_array[n] {4,17,3,12,9,6};

    cout << "Исходный массив" << endl;
    PrintArray(an_array,n);

    heapSort(an_array, n);

    cout << "Отсортированный массив "<<endl;
    PrintArray(an_array, n);

    return 0;

}
