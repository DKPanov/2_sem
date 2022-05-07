#include <iostream>

using namespace std;

int main()
{
    int x;
    int n = -2147483648;
    cin >> x;

    while (x != 0) {
        if ((x % 2 == 0) && (x > n)) {
            n = x;
        }
        cin >> x;
    }

    if (n != 0) {
        cout << "Maximum even number: " << n;
    }
    else cout << '\n';
    return 0;
}
