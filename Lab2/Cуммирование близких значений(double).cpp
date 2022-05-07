#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double mean(double G[], double const dv, unsigned size) {

    //G_[] - произведение функций G := psi_ * f_
    double G_[size];

    // Условие для выхода из рекурсии
    if (size == 1)
        return G[0] * dv;

    int j = 0;
    for (int i = 0; i < size; i = i + 2) {
        if (i + 1 == size) {
            G_[j] = G[i];
        }else{
            G_[j] = G[i] + G[i + 1];
        }

        j++;
    }

    return mean(G_, dv, j);

}


int main()
{
    setlocale(LC_ALL, "rus");

    unsigned n = 10000;

    cout << "Введите параметр T: ";
    double T;
    cin >> T;
    double sigma, dx;

    //dx - шаг разбиения
    sigma = sqrt(T) / sqrt(2);
    dx = 10 * sigma / n;

    //Выделяем пямять под массивы значений функций psi и f
    double *psi = new double[n];
    double *pdf = new double[n];

    for (int i = 0; i < n; i++)
    {
        double x = -5 * sigma + i * dx;
        psi[i] = fabs(x);
        pdf[i] = exp(-x * x / T) / sqrt(M_PI * T);
    }

    //G - произведение функций G := psi * f
    double G[n];
    for (int i = 0; i < n; i++)
    {
        G[i] = pdf[i] * psi [i];
    }


    //Рекурсивно выводим сумму psi[i] * pdf[i] * dv
    cout << setprecision(20)  << mean(G, dx, n) << endl;
    delete[] psi;
    delete[] pdf;

    //Проверяем результат вычислением интеграла с помощью цикла
    double I = 0;
    for (int i = 0; i < n; i++)
    {
        I += psi[i] * pdf[i] * dx;
    }
    cout << setprecision(20) << I;

    return 0;
}
