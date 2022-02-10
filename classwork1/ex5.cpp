#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cout << "n = ";
    cin >> n;
    int a = n;
    cout << "m = ";
    cin >> m;
    int b = m;
    while (n != m){
        if (n > m) {
            n = n - m;
        }
        else if (n < m) {
            m = m - n;
        }
    }
    cout << "The smallest common multiple: " << a * b / n;
}
