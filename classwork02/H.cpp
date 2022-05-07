# include <iostream>
# include <cmath>

using namespace std;

int Palindrom(int d, int x){
    int t = 0, y = x;

    while (d != 0) {
        t += (x % 10) * pow(10, d - 1);
        x /= 10;
        d--;
    }


    if (t == y)
        return 1;
    else
        return t;
}

int main()
{
    int dim, n;
    cin >> dim >> n;
    cout << Palindrom(dim, n) << endl;
    return 0;
}
