#include <iostream>

using namespace std;

int main()
{
    int n;
    int f = 0;
    cin >> n;

    for (int i = n - 1; i > 1; i--) {
        if (n % i == 0){
            f = 1;
            cout << i << " ";
        }
    }
    if (f == 0){
        cout << " ";
    }


    return 0;
}
