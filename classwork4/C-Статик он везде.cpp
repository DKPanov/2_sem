// ����������� ���� ���������� ������ ������� � �������������� static ����������.

# include <iostream>

using namespace std;

//static int count = 0;

void counter() {
    static int count = 0;
    cout << count;
    count++;
}

int main() {
    for (int i = 0; i < 5; ++i) counter();

    return 0;
}
