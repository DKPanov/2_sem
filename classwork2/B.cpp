#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int x;
    cin >> x;

    while (x != 0) {
        if (x % 2 == 0) {
            n++;
        }
        cin >> x;
    }

    cout << "Number of even numbers: " << n;

    return 0;

}
