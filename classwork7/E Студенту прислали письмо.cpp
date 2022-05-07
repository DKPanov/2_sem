/*
Для шифрования писем используется сложнейший алгоритм. Но еще более сложно их расшифровать.
Чтобы убедиться, что никто не прочитал ваше письмо, или же сообщение, создаются специальные ключи-отрезки.
Если ключи-отрезки имеют общую точку, то шифрование не было нарушено, конфиденциальность сохранена.
Если же такой точки не существует, то кто-то вас прослушивает...
Ввод: N -- число отрезков-шифрователей, N пар чисел -- пара (начало, конец) для отрезка.
Вывод: если конфиденциальность сохранена, то вывести YES, иначе -- NO. Вывод заканчивается переносом на новую строку.
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

    cout << "Введите число отрезков-шифрователей" << endl;
    cin >> n;

    // На основе структуры Sections создаем указатель на объект Sections
    Sections *st = new Sections [n];

    for (int i = 0; i != n; i++) {
        cout << "Введите начало и конец отрезка: " << endl;
        cin >> st[i].x1;
        cin >> st[i].x2;
    }

    for (int i = 0; i != n; i++) {
        vector <int> temp;
        for (int j = st[i].x1; j != st[i].x2 + 1; j++) temp.push_back(j);

        vec.push_back(temp);

    }

    cout << "Введены следующие отрезки:" << endl;

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
            // Возвращает итератор к первому найденному элементу. Если он отсутствует, возвращает итератор на конец
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
