/* ����������� ��������� Students � ������ ���, ������� ����.
�� ���� �������� N -- ����� ���������. � ����� ����� M -- ��������� ����.
������� ��� ���������, ������� ����� ������� ���� ���� M. */

#include <iostream>

using namespace std;

struct Students {
    string name;
    int mark;
};

int main() {

    setlocale(LC_ALL,"rus");

    int n;
    cout << "������� ���������� ���������" << endl;
    cin >> n;

    // �� ������ ��������� Students ������� ��������� �� ������ Students
    Students *st = new Students [n];

    for (int i = 0; i != n; i++) {

        cout << "������� ���: "<< endl;
        cin >> st[i].name;
        cout << "������� ������� ����: " << endl;
        cin >> st[i].mark;

        cout << endl;
    }

    int M;
    cout << "������� ��������� ����: " << endl;
    cin >> M;

    cout << "------------------------------------------";
    cout << endl;

    for (int i = 0; i != n; i++) {
        if (st[i].mark > M) {
            cout << st[i].name << st[i].mark << endl;
        }
    }

    delete[] st;

  return 0;
}
