#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    while (n != m){
        if (n > m) {
            n = n - m;
        }
        else if (n < m) {
            m = m - n;
        }
    }
    cout << "The greatest common divisor: " << n;

}
