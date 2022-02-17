#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    double s1 = 1;
    for (double i = 2; i < n + 1; i++) {
        s1 += 1/(i * i);
    }
    cout.precision(20);
    cout << "Double: " << s1*2 << endl;

    float s2 = 1;
    for (float i = 2; i < n + 1; i++) {
        s2 += 1/(i * i);
    }

    cout.precision(20);
    cout << "Float: " << s2*2;

    return 0;
}

