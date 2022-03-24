// Дислокация в квадратной области

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

// Печать текущего состояния массива
void PrintArray(int n, int a[]) {

  for(int i = 0; i < n; i++)
    for (int j = 0; j < n || (puts(""), 0); j++)
      cout << a[i * n + j] << " | ";
}

int main() {

  setlocale(LC_ALL, "rus");
  int n;


//переменные, чтобы менялся seed
  int p = 0;
  int h = 1;
//Суммарное количество шагов
  int iter = 0;


  string transfer[] = {"вверх", "вниз", "влево", "вправо"};

  cout << "Введите размер кристалла n " << endl;
  cin >> n;
  int an_array[n][n];

  for (int i = 1; i <= 100000; i++){
//      cout << "\n-----------------------------------------\n";
//      cout << "Опыт " << i << endl;

      int border = 0;
      int iter_ = 0;
      int k = RandomNumber(1,n-2, p);
      int t = RandomNumber(1,n-2, h);
      p+=1;
      h+=129;

      for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
              if (i == k && j == t) {
              an_array[i][j] = 1;
              }else{
              an_array[i][j] = 0;
              }
          }
      }

//      PrintArray(n, &an_array[0][0]);

//      cout << "\n-----------------------------------------\n";

      if (CheckBorder(n, &an_array[0][0])) {
          cout << "Граница"  << endl;
          cout << "Количество шагов:" << iter_ << endl;
          cout << "Общее количество шагов:" << iter << endl;
          border = 1;
      }

      if (border == 0) {

        iter_ = 0;

        while (1) {

            if (border != 0) {
                iter += iter_;
//                cout << "Граница"  << endl;
//                cout << "Количество шагов:" << iter_ << endl;
//                cout << "Общее количество шагов:" << iter << endl;
                break;
            }

            // Перемещение
            int shift = RandomNumber(0,3, iter_);

            // флаг для отслеживания, было ли перемещение
            int a = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (an_array[i][j] == 1 && a == 0) {
                        // вверх
                        if (shift == 0  && i !=0 && i!= n-1 && j!= 0 && j!= n-1) {
                            an_array[i-1][j] = 1;
                            iter_++;
                        // вниз
                        }else if (shift == 1 && i !=0 && i!= n-1 && j!= 0 && j!= n-1) {
                            an_array[i+1][j] = 1;
                            iter_++;
                        // влево
                        }else if (shift == 2 && i !=0 && i!= n-1 && j!= 0 && j!= n-1) {
                            an_array[i][j-1] = 1;
                            iter_++;
                        // вправо
                        }else if (shift == 3 && i !=0 && i!= n-1 && j!= 0 && j!= n-1) {
                            an_array[i][j+1] = 1;
                            iter_++;
                        }else{
                            border = 1;
                        }

                        // предыдущее положение дислокации заполняем нулем
                        an_array[i][j] = 0;
                        a = 1;

                        }
                    }
                }


          if (border == 0){
//          cout << "перемещение " << transfer[shift] << endl;
//          PrintArray(n, &an_array[0][0]);
          }



//          cout << "\n-----------------------------------------\n";

        }

      }


  }

  cout << "Среднее количество шагов: " << iter*0.00001 << endl;
  return 0;
}
