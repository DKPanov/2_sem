// Бинарный поиск

# include <iostream>

using namespace std;

bool SearchValue (int value, int array[], int count) {

    int firstValue = 0, secondValue = count - 1, i = 0;
    if (count < 1 || !array) return false;

    while (firstValue <= secondValue) {
        i = (firstValue + secondValue) / 2;
        if (array[i] == value) return true;
        else if (array[i] < value) firstValue = i + 1;
        else if (array[i] > value) secondValue = i - 1;
    }

    return false;

}

int main() {

    setlocale (LC_ALL, "rus");

    int an_array[] = {18,22,41,44,52,55,59,60,64,67,75,76,76,82,85,93};
    int i = 0;

    // Длина массива
    const int SIZE = sizeof(an_array)/sizeof(*an_array);

    cout << "Массив чисел:" << "\n";
    for (const int &n : an_array) {
        cout << n << " | ";
    }

	cout << "\n\nВведите любое число для поиска из чисел в массиве: ";
	cin >> i;

    if (SearchValue(i, an_array, SIZE)) {
        cout << "Число " << i << " в массиве найдено";
    }else{
        cout << "Числа " << i << " в массиве нет";
    }

    return 0;

}
