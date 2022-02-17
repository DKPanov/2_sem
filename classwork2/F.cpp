#include <iostream>

using namespace std;

int main()
{
    int n;
    int f = 0;
    cout << "Please enter a natural number (greater than 1): ";
    cin >> n;

    for (int i = 2; i < n; i++) {
        if (n % i == 0){
            f = 1;
            break;
        }
    }
    if (f == 0){
        cout << "YES";
    }

    else cout << "NO";

    return 0;
}
