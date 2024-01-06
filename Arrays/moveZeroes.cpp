#include <vector>
//Program to move the zeroes to the end of the array
std::vector<int> moveZeros(int n, std::vector<int> a) {
    int j = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }
    if (j == -1) {
        return a;
    }
    for (int i = j + 1; i < n; i++) {
        if (a[i] != 0) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j++;
        }
    }

    return a;
}
