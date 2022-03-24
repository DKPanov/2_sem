// Дислокация в квадратной области

#include <random>
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

// Поиск случайного значения
int RandomNumber(int a, int b, int c = 0) {

  mt19937 generator((time(NULL) * 1000) + c);
  uniform_int_distribution<int> distr(a, b);

  return distr(generator);

}

// Проверка на границу
bool CheckBorder(int n, int a[]) {

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i * n + j] == 1) {
        if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
          return true;
        }else {
          return false;
        }
      }
    }
  }
}

// Вывод на экран текущего состояния массива
void PrintArray(int n, int a[]) {

  for(int i = 0; i < n; i++)
    for (int j = 0; j < n || (puts(""), 0); j++)
      cout << a[i * n + j] << " | ";
}

int main() {

  setlocale(LC_ALL, "rus");
  int n, qty;

  // Суммарное количество шагов
  int iter = 0;

  // Переменная для изменения seed
  int m, mm;

  string transfer[] = {"вверх", "вниз", "влево", "вправо"};

  cout << "Введите размер кристалла " << endl;
  cin >> n;
  cout << "Введите кол-во дислокаций " << endl;
  cin >> qty;

  for (int i = 1; i <= 3; i++){
    cout << "\n-----------------------------------------\n";
    cout << "Опыт " << i << endl;

    int an_array[n][n];
    int shift_ = 0;
    int iter_ = 0;

    vector <vector <int>> vec;

    for (int k = 0; k < qty; k++) {

      vector <int> temp;

      int x = RandomNumber(1,n-2, m);
      int y = RandomNumber(1,n-2, mm);
      m += 11;
      mm += 29;

      temp.push_back(x);
      temp.push_back(y);

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (i == x && j == y) {
            an_array[i][j] = 1;
          }else{
            if (an_array[i][j] != 1) an_array[i][j] = 0;
          }
        }
      }

      vec.push_back(temp);

    }

    PrintArray(n, &an_array[0][0]);

    cout << "\n-----------------------------------------\n";

    // Для визуализаии координат дислокаций полученных в результате работы
    // ф-ции RandomNumber на первом этапе

    cout << "Начальные координаты дислокаций: " << endl;
    for (int i = 0; i < vec.size(); i++) {
      cout << "(";
      for (int j = 0; j < 2; j++) {
        cout << vec[i][j];
        if(j == 0) cout << "-";
      }
      cout << ") ";
    }

    cout << "\n-----------------------------------------\n";

    while (1) {
      if (shift_ == 1) {
        iter += iter_;
        cout << "Стоп" << endl;
        cout << "Количество шагов:" << iter_ << endl;
        cout << "Общее количество шагов:" << iter << endl;
        break;
      }

      int shift = 0;
      int flag = 0;

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (an_array[i][j] == 1) {

            // Проверка на границу (дислокация может перемещаться, если она не на границе)
            if (i != 0 && j != 0 && i != n - 1 && j != n - 1) {
              // Проверка на элемент: вверху, внизу, слева, справа
              if (an_array[i-1][j] != 1 && an_array[i+1][j] != 1 && an_array[i][j-1] != 1 && an_array[i][j+1] != 1){


                flag = 1;
                // Перемещение
                shift = RandomNumber(0,3, m);
                cout << "i=" << i << " j=" << j << " Перемещение ";

                // вверх
                if (shift == 0) {
                  an_array[i-1][j] = 2;
                  cout << "вверх" << endl;
                }
                // вниз
                if (shift == 1) {
                  an_array[i+1][j] = 2;
                  cout << "вниз" << endl;
                }
                // влево
                if (shift == 2) {
                  an_array[i][j-1] = 2;
                  cout << "влево" << endl;
                }
                // вправо
                if (shift == 3) {
                  an_array[i][j+1] = 2;
                  cout << "вправо" << endl;
                }

                an_array[i][j] = 0;
              }
            }
          }

          // Для изменения seed
          m += 100;
        }
      }

      if (flag == 1) iter_++;

      for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
          if (an_array[i][j] == 2) an_array[i][j] = 1;

      if (flag == 1) PrintArray(n, &an_array[0][0]);


      cout << "\n-----------------------------------------\n";

      if (shift == 0) shift_ = 1;

    }
  }

  //cout << "Среднее количество шагов: " << iter*0.001 << endl;
  return 0;
}
