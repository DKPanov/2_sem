/* –еализовать структуру Time, котора€ хранит три пол€: часы, минуты, секунды.
Ќа вход подаетс€ шесть чисел:
перва€ тройка -- текущее врем€ в формате часы, минуты, секунды
втора€ тройка -- врем€ до конца пары
¬ывод: врем€ окончани€ пары в формате час:минута:секунда в 24-часовом формате. */

#include <iostream>
#include <cmath>

using namespace std;

struct Line {
    int x, y;

};

int main() {

    setlocale(LC_ALL,"rus");

    int n = 2;

    Line *a = new Line [2];

    cout << "¬едите координаты начала первой улицы" << endl;
    cin >> a[0].x >> a[0].y;
    cout << "¬едите координаты конца первой улицы" << endl;
    cin >> a[1].x >> a[1].y;

    Line *b = new Line [2];

    cout << "¬едите координаты начала второй улицы" << endl;
    cin >> b[0].x >> b[0].y;
    cout << "¬едите координаты конца второй улицы" << endl;
    cin >> b[1].x >> b[1].y;

    cout << "------------------------------------------";
    cout << endl;

    // ≈сли координаты совпадают
    int check = 0;
    for (int i = 0; i != n; i++) {
        for (int j = 0; j != n; j++) {
            if (a[i].x == b[j].x && a[i].y == b[j].y) {
                check = 1;
            }
        }
    }

    int v1 = (b[1].x-b[0].x)*(a[0].y-b[0].y)-(b[1].y-b[0].y)*(a[0].x-b[0].x);
    int v2 = (b[1].x-b[0].x)*(a[1].y-b[0].y)-(b[1].y-b[0].y)*(a[1].x-b[0].x);
    int v3 = (a[1].x-a[0].x)*(b[0].y-a[0].y)-(a[1].y-a[0].y)*(b[0].x-a[0].x);
    int v4 = (a[1].x-a[0].x)*(b[1].y-a[0].y)-(a[1].y-a[0].y)*(b[1].x-a[0].x);

    // ѕересекаютс€ ли 2 отрезка?
    if (check == 1) {
        cout << "NO" << endl;

    }else {
        if (v1 * v2 < 0 && v3 * v4 < 0) {
            cout << "NO" << endl;

        }else {
            cout << "YES" << endl;
        }
    }

    delete[] a;
    delete[] b;

    return 0;

}
