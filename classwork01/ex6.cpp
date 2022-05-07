# include <iostream>
# include <cmath>

using namespace std;

int NOD(int n, int m){
    while (n != m){
        if (n > m) {
            n = n - m;
        }
        else if (n < m) {
            m = m - n;
        }
    }
    return m;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a = n;
    int b = m;
    cout << "The greatest common divisor: " << NOD(n, m) << endl;  //„тобы перейти на новую строку, можно использовать << endl
    cout << "The smallest common multiple: " << a * b / NOD(m, n);

    return 0;
}
