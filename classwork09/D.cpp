#include <iostream>
#include <iomanip>

using namespace std;

struct denom_array_t {
    unsigned int* arr;
    unsigned int sz;
};

denom_array_t egyptian_fractions(unsigned int num, unsigned int den) {
    unsigned int current_size = 5;
    unsigned int* arr = new unsigned int[current_size];
    unsigned int size = 0;
    while (den % num != 0) {
        if (size == current_size) {
            unsigned int* new_arr = new unsigned int[2 * current_size];
            for (unsigned int i = 0; i < size; i++) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
            current_size *= 2;
        }
        unsigned int dn = den / num;

        if (den % num != 0) {
            dn++;
        }
        arr[size] = dn;

        unsigned int new_num = num - den % num;
        den = den * dn;
        num = new_num;
        size++;

    }

    if (size == current_size) {
        unsigned int* new_arr = new unsigned int[2 * current_size];
        for (unsigned int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        current_size *= 2;
    }
    unsigned int dn = den / num;

    if (den % num != 0) {
        dn++;
    }
    arr[size] = dn;
    size++;

    unsigned int* result = new unsigned int[size];
    for (unsigned int i = 0; i < size; i++) {
        result[i] = arr[i];
    }
    delete[] arr;


    denom_array_t denom_array;
    denom_array.arr = result;
    denom_array.sz = size;

    return denom_array;
}

int main() {

    unsigned int x, y;
    cin >> x;
    cin >> y;

    auto del = egyptian_fractions(x, y);
    for (unsigned int i = 0; i < del.sz; i++) {
        cout << del.arr[i] << " ";
    }
    delete[] del.arr;


    return 0;
}
