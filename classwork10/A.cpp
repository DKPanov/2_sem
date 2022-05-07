#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// uint64_t - ���� "unsigned int", 64 ����
uint64_t qty_i(int i, int* result){    //����������� �������: ���������� ��������� ���-�� �������� ������� ������� (i+1)
    if (result[i] != -1){
        return result[i];
    }
    result[i] = qty_i(i-1, result) + qty_i(i-2, result) + qty_i(i-3, result); //���-�� �������� ����� �� (i+1)-� ���������
    return result[i];
}


uint64_t qty(int N){   //�������, ����������� ���-�� �������� ������� ������� N
    int* result = new int[N];
    for (int i = 0; i < N; i++){
        result[i] = -1;
    }
    result[0] = 1;    //������� ������� result[i] - ���-�� �������� ����� �� (i+1)-� ���������
    result[1] = 1;
    result[2] = 2;    //���-�� �������� ����� �� ���� ��������� ���� ����� �� ���� ���� ��������, ���� ��� ����
    uint64_t answer = qty_i(N - 1, result); //���������� �������� ����� �� ��������� N

    delete[] result;

    return answer;
}



int main() {

    int N;
    cin >> N;


    cout << qty(N + 1);

    return 0;
}
