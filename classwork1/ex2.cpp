#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    double x1, x2, x;
    cin >> a >> b >> c;

    if (a != 0) {
        if (b*b - 4*a*c < 0) {
            cout << "No real solutions";
        }
        else if (b*b - 4*a*c == 0){
            cout << "Solution: " << (-b)/(2*a);
        }
        else if (b*b - 4*a*c > 0){
            x1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
            x2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
            cout << "Solution: " << x2 << " " << x1;
        }

    }
    else if ((a == 0) && (b != 0)) {
        cout << "Solution: " << -c/b;
    }
    else if ((a == 0) && (b == 0)) {
        cout << "No solutions: " ;
    }
}

