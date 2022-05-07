#include <iostream>

using namespace std;

int main()
{
    cout << "Year: ";
    int y;
    cin >> y;
    if ((y % 4 == 0) && (y % 100 != 0)) {
        cout << "YES";
    }
    else if (y % 400 == 0) {
        cout << "YES";
    }
    else cout << "NO";

    return 0;

}
