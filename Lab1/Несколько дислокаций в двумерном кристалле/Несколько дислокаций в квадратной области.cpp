// ���������� � ���������� �������

#include <random>
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

// ����� ���������� ��������
int RandomNumber(int a, int b, int c = 0) {

  mt19937 generator((time(NULL) * 1000) + c);
  uniform_int_distribution<int> distr(a, b);

  return distr(generator);

}

// �������� �� �������
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

// ����� �� ����� �������� ��������� �������
void PrintArray(int n, int a[]) {

  for(int i = 0; i < n; i++)
    for (int j = 0; j < n || (puts(""), 0); j++)
      cout << a[i * n + j] << " | ";
}

int main() {

  setlocale(LC_ALL, "rus");
  int n, qty;

  // ��������� ���������� �����
  int iter = 0;

  // ���������� ��� ��������� seed
  int m, mm;

  string transfer[] = {"�����", "����", "�����", "������"};

  cout << "������� ������ ��������� " << endl;
  cin >> n;
  cout << "������� ���-�� ���������� " << endl;
  cin >> qty;

  for (int i = 1; i <= 3; i++){
    cout << "\n-----------------------------------------\n";
    cout << "���� " << i << endl;

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

    // ��� ����������� ��������� ���������� ���������� � ���������� ������
    // �-��� RandomNumber �� ������ �����

    cout << "��������� ���������� ����������: " << endl;
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
        cout << "����" << endl;
        cout << "���������� �����:" << iter_ << endl;
        cout << "����� ���������� �����:" << iter << endl;
        break;
      }

      int shift = 0;
      int flag = 0;

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (an_array[i][j] == 1) {

            // �������� �� ������� (���������� ����� ������������, ���� ��� �� �� �������)
            if (i != 0 && j != 0 && i != n - 1 && j != n - 1) {
              // �������� �� �������: ������, �����, �����, ������
              if (an_array[i-1][j] != 1 && an_array[i+1][j] != 1 && an_array[i][j-1] != 1 && an_array[i][j+1] != 1){


                flag = 1;
                // �����������
                shift = RandomNumber(0,3, m);
                cout << "i=" << i << " j=" << j << " ����������� ";

                // �����
                if (shift == 0) {
                  an_array[i-1][j] = 2;
                  cout << "�����" << endl;
                }
                // ����
                if (shift == 1) {
                  an_array[i+1][j] = 2;
                  cout << "����" << endl;
                }
                // �����
                if (shift == 2) {
                  an_array[i][j-1] = 2;
                  cout << "�����" << endl;
                }
                // ������
                if (shift == 3) {
                  an_array[i][j+1] = 2;
                  cout << "������" << endl;
                }

                an_array[i][j] = 0;
              }
            }
          }

          // ��� ��������� seed
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

  //cout << "������� ���������� �����: " << iter*0.001 << endl;
  return 0;
}
