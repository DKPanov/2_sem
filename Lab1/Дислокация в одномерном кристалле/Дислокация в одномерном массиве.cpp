// Дислокация в одномерном массиве,
// предельный случай одномерного кристалла.

#include <random>
#include <iostream>
#include <chrono>

using namespace std;

// Поиск случайного значения
int RandomNumber(int a, int b, int c = 0) {

    mt19937 generator((time(NULL) * 1000) + c);
    uniform_int_distribution<int> distr(a, b);

    return distr(generator);

}

int main() {

    setlocale(LC_ALL, "rus");

    const int N = 10;

    int k = 0, iter = 0;
    int j = 0, jj = 0;

    // Итерации
    for (int i = 1; i <= 100; i++) {

        // Создаем дислокацию
        int an_array[N] = {0};
        an_array[RandomNumber(0, 9, k)] = 1;

        cout << "Кристалл " << i << ":\n";
        for (int i = 0; i < N; ++i) {
            cout << an_array[i] << " | ";
            if (an_array[i] == 1) j = i;
        }

        cout << "\n-----------------------------------------\n";

        int iter_ = 0;

        while (1) {
            if (j == 0 || j == N - 1) break;

            // Случайное значение для перемещения - влево, вправо
            jj = RandomNumber(0,1, iter_);
            if (jj == 1) {
                j = j + 1;
                an_array[j] = 1;
                an_array[j - 1] = 0;

            }else{
                j = j - 1;
                an_array[j] = 1;
                an_array[j + 1] = 0;
            }


            for (const int &n : an_array) {
                cout << n << " | ";
            }

            cout << "\n";
            iter_++;

        }

        cout << "\nКол-во итераций по перемещению дислокации " << iter_ << "\n";

        iter = iter + iter_;
        cout << "\nОбщее кол-во итераций с перемещениями дислокации " << iter << "\n";
        cout << "\n----------------------------------------------------------------------------------\n";

        k++;

    }

    cout << "Итого среднее: " << iter / k << "\n";

    return 0;
}
