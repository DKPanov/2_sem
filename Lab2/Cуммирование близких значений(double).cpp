#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double mean(double psi[], double pdf[], double const dv, unsigned size) {

    double psi_[size];
    double pdf_[size];

    // ������� ��� ������ �� ��������
    if (size == 1)
        return psi[0] * pdf[0] * dv;

    int j = 0;
    for (int i = 0; i < size; i = i + 2) {
        if (i + 1 == size) {
            psi_[j] = psi[i];
            pdf_[j] = pdf[i];
        }else{
            psi_[j] = psi[i] + psi[i + 1];
            pdf_[j] = pdf[i] + pdf[i + 1];
        }

        j++;
    }

    return mean(psi_, pdf_, dv, j);

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

    for (int i = 0; i < n; i++)
    {
        cout << psi[i] <<'\t' << pdf[i]<< endl;
    }

    //���������� ������� ����� psi[i] * pdf[i] * dv
    cout << setprecision(20)  << mean(psi, pdf, dx, n) << "---------------" << endl;
    delete[] psi;
    delete[] pdf;

    //��������� ��������� ����������� ��������� � ������� �����
    double I = 0;
    for (int i = 0; i < n; i++)
    {
        I = I + psi[i] * pdf[i] * dx;
    }
    cout << setprecision(20) << I;
}
