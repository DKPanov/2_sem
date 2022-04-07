#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double mean(double psi[], double pdf[], double const dv, unsigned size)
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
    {
        sum = fma(psi[i], pdf[i] * dv, sum);
    }
    return sum;
}

int main()
{
    setlocale(LC_ALL, "rus");

    unsigned n = 1000;
    const double pi = 3.14;

    cout << "������� �������� T: ";
    double T;
    cin >> T;
    double sigma, dx;

    //dx - ��� ���������
    sigma = T / sqrt(2);
    dx = 6 * sigma / n;

    //�������� ������ ��� ������� �������� ������� psi � f
    double *psi = new double[n];
    double *pdf = new double[n];

    for (int i = 0; i < n; i++)
    {
        double x = -3 * sigma + i * dx;
        psi[i] = fabs(x);
        pdf[i] = exp(-x * x / T) / sqrt(pi * T);
    }

//    for (int i = 0; i < n; i++)
//    {
//        cout << psi[i] <<'\t' << pdf[i]<< endl;
//    }


    //���������� ������� ����� psi[i] * pdf[i] * dv
    cout << setprecision(20) << mean(psi, pdf, dx, n) << endl;
    delete[] psi;
    delete[] pdf;

    //��������� ��������� ����������� ��������� � ������� �����
    double I = 0;
    for (int i = 0; i < n; i++)
    {
        I = I + psi[i] * pdf[i] * dx;
    }
    cout << I;
}