/*
��� ���������� ����� ������������ ���������� ��������. �� ��� ����� ������ �� ������������.
����� ���������, ��� ����� �� �������� ���� ������, ��� �� ���������, ��������� ����������� �����-�������.
���� �����-������� ����� ����� �����, �� ���������� �� ���� ��������, ������������������ ���������.
���� �� ����� ����� �� ����������, �� ���-�� ��� ������������...
����: N -- ����� ��������-������������, N ��� ����� -- ���� (������, �����) ��� �������.
�����: ���� ������������������ ���������, �� ������� YES, ����� -- NO. ����� ������������� ��������� �� ����� ������.
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Sections {
    int x1, x2;
};

using namespace std;

int main() {

    setlocale(LC_ALL,"rus");

    int n;
    vector <vector <int>> vec;

    cout << "������� ����� ��������-������������" << endl;
    cin >> n;

    // �� ������ ��������� Sections ������� ��������� �� ������ Sections
    Sections *st = new Sections [n];

    for (int i = 0; i != n; i++) {
        cout << "������� ������ � ����� �������: " << endl;
        cin >> st[i].x1;
        cin >> st[i].x2;
    }

    for (int i = 0; i != n; i++) {
        vector <int> temp;
        for (int j = st[i].x1; j != st[i].x2 + 1; j++) temp.push_back(j);

        vec.push_back(temp);

    }

    cout << "������� ��������� �������:" << endl;

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "------------------------------------------";
    cout << endl;

    int k = 0;
    for (int i = 1; i < vec.size(); i++) {
        int k_ = 0;
        for (int j = 0; j < vec[i].size(); j++) {
            // ���������� �������� � ������� ���������� ��������. ���� �� �����������, ���������� �������� �� �����
            if (std::find(vec[0].begin(), vec[0].end(), vec[i][j]) != vec[0].end()) k_++;
        }

        if (k_ > 0) k++;

    }

    if (k == n - 1) {
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    delete[] st;

    return 0;

}
