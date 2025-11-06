#include <iostream>
#include "../Header/basic_sort.hpp"
using namespace std;

void swap(int& x, int& y) {
    int z = x;
    x = y;
    y = z;
}
// Sắp xếp lựa chọn: 
void selection(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if(a[min] > a[j]) min = j;
        }
        swap(a[i], a[min]);
        cout << "Step " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}

// Sắp xếp nổi bọt: 
void bubble(int* a, int n) {
    for (int i = 0; i < n - 1; i++) {
        // Đưa phần tử bé nhất lên đầu:
        for (int j = n - 1; j > i; j--) {
            // phần tử liền sau mà bé hơn phần tử liền trước thì đổi chỗ 2 phần tử:
            if (a[j] < a[j - 1]) swap(a[j], a[j - 1]);
        }
        cout << "Step " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}

// Sắp xếp chèn:
void insertion(int* a, int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key) {
            swap(a[j + 1], a[j]);
            j--;
        }
        cout << "Step " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}