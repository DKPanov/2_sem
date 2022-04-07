/* Реализовать структуру Students с полями имя, средний балл.
На ввод подается N -- число студентов. В конце число M -- пороговый балл.
Вывести тех студентов, которые имеют средний балл выше M. */

#include <iostream>

using namespace std;

struct Students {
    string name;
    int mark;
};

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

    for (int i = 0; i != n; i++) {
        if (st[i].mark > M) {
            cout << st[i].name << st[i].mark << endl;
        }
    }

    delete[] st;

  return 0;
}
