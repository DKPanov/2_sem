#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float mean(float psi[], float pdf[], float const dv, unsigned size)
{
    if (size == 1)
    {
        return psi[0] * pdf[0] * dv;
    }
    else
    {
        return mean(psi, pdf, dv, size / 2) + mean(psi + size / 2, pdf + size/2, dv, size - size / 2);
    }
}


int main()
{
    setlocale(LC_ALL, "rus");

    unsigned n = 1000;
    const float pi = 3.14;

    cout << "Введите параметр T: ";
    float T;
    cin >> T;
    float sigma, dx;

    //dx - шаг разбиения
    sigma = T / sqrt(2);
    dx = 6 * sigma / n;

    //Выделяем пямять под массивы значений функций psi и f
    float *psi = new float[n];
    float *pdf = new float[n];

    for (int i = 0; i < n; i++)
    {
        float x = -3 * sigma + i * dx;
        psi[i] = fabs(x);
        pdf[i] = exp(-x * x / T) / sqrt(pi * T);
    }

/*  for (int i = 0; i < n; i++)
    {
        cout << psi[i] <<'\t' << pdf[i]<< endl;
    }
*/


    //Рекурсивно выводим сумму psi[i] * pdf[i] * dv
    cout << setprecision(20) << mean(psi, pdf, dx, n) << endl;
    delete[] psi;
    delete[] pdf;

    //Проверяем результат вычислением интеграла с помощью цикла
    float I = 0;
    for (int i = 0; i < n; i++)
    {
        I = I + psi[i] * pdf[i] * dx;
    }
    cout << setprecision(20) << I;
}
