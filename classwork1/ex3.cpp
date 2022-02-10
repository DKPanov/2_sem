#include <iostream>

using namespace std;

int main()
{
    int n, m;
    m = 1;
    cout << "n = ";
    cin >> n;
    for (int i = 1; i < n + 1; i++){
        m = m * i;
    }
    cout << "n! = " << m;
}
