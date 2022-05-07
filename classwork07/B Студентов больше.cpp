/* Реализовать структуру Students с полями имя, средний балл.
На ввод подается N -- число студентов. Затем подаются данные N студентов -- имя и балл. В конце число M -- пороговый балл.
Вывести тех студентов, которые имеют средний балл выше M в порядке возрастания (если балл одинаковый, то сравниваем их имена)! */

#include <iostream>

using namespace std;

struct Students {
    string name;
    int mark;
};

void SortInt(Students *studs, int &len) {
    for(int i = 0; i < len - 1; i++) {
        for(int j = i + 1; j < len; j++) {
            if (studs[i].mark > studs[j].mark) {
                Students buf = studs[i];
                studs[i] = studs[j];
                studs[j] = buf;
            }
        }
    }
}

int main() {

    setlocale(LC_ALL,"rus");

    int n;
    cout << "Введите количество студентов" << endl;
    cin >> n;

    // На основе структуры Students создаем указатель на объект Students
    Students *st = new Students [n];

    for (int i = 0; i != n; i++) {

        cout << "Введите Имя: "<< endl;
        cin >> st[i].name;
        cout << "Введите средний балл: " << endl;
        cin >> st[i].mark;

        cout << endl;
    }

    int M;
    cout << "Введите пороговый балл: " << endl;
    cin >> M;

    cout << "------------------------------------------";
    cout << endl;

    // Сортировка по баллам
    SortInt(st, n);

    for (int i = 0; i != n; i++) {
        if (st[i].mark > M) {
            cout << st[i].name << st[i].mark << endl;
        }
    }

    delete[] st;

  return 0;
}
