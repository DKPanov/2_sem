#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale (LC_ALL, "rus");

    int N, M, k;
    cin >> N;
    cin >> M;
    cin >> k;

    int start = 0;
    int prev = -1;
    int next;

    if (M >= N){
        cout << 0;
        return 0;
    }

    int count;

    for (int i = 0; i < k; i++){
        cin >> next;
        if (M < next - start && prev == -1){
            cout << -1;
            return 0;
        }

        if (M < next - start){
            count++;
            start = prev;
            if (N - start <= M){
                cout << count;
                return 0;
            }
            prev = -1;
        }
        else{
            prev = next;
        }
    }

    count++;
    if (M >= N - next){
        cout << count;
    }else{
        cout << -1;
    }

    return 0;
}
