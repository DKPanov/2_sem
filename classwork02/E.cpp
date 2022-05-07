#include <iostream>

using namespace std;

int main()
{
    int x;
    int maximum = -2147483648;
    int k = 0;
    cin >> x;

    while (x != 0) {
        if (x > maximum) {
            maximum = x;
            k = 1;
        }
        else if (x == maximum){
            k++;
            cout << k << " ";
        }
        cin >> x;
    }

    cout << "The number of elements  which equal to the maximum " << k;

    return 0;
}
