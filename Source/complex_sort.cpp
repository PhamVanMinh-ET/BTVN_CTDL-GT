#include <iostream>
#include <algorithm>
#include "../Header/complex_sort.hpp"
using namespace std;

// Sắp xếp nhanh:
void chia_vung(int* nums, int left, int right, int n) {
    if (left >= right) return;

    int c = nums[left];  // pivot
    int i = left + 1, j = right;

    while(i <= j) {
        // i trỏ tới phần tử lớn hơn pivot thì dừng lại
        while(i <= j && nums[i] < c) i++;

        // j trỏ tới phần tử nhỏ hơn pivot thì dừng lại
        while(i <= j && nums[j] > c) j--;
        
        // chuyển phần tử nhỏ hơn pivot về bên trái và ngược lại
        if (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    
    for (int k = 0; k < n; k++) {
        cout << nums[k] << " ";
    }
    cout << endl;
    // đưa phần tử pivot về đúng vị trí của nó
    swap(nums[left], nums[j]);

    // Đệ quy
    chia_vung(nums, left, j - 1, n);
    chia_vung(nums, j + 1, right, n);
}
void Quick_Sort(int* nums, int n) {
    chia_vung(nums, 0, n - 1, n);
}

// Sắp xếp trộn
void Merge(int* nums, int left, int mid, int right) {
    int* a = new int[right - left + 1];   // mảng trung gian
    int k = 0;
    int i = left, j = mid + 1;

    // sắp xếp các phần tử vào mảng trung gian
    while(i <= mid && j <= right) {
        if(nums[i] < nums[j]) a[k++] = nums[i++];
        else a[k++] = nums[j++];
    }
    while(i <= mid) a[k++] = nums[i++];
    while(j <= right) a[k++] = nums[j++];

    // sao chép giá trị của mảng trung gian về mảng ban đầu
    for (int u = 0; u < k; u++) {
        nums[left + u] = a[u];
    }

    // in mảng sau mỗi lần sắp xếp
    for (int u = left; u <= right; u++) {
        cout << nums[u] << " ";
    }
    cout << endl;

    delete[] a;
}
void Merge_Sort(int* nums, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;

    // đệ quy
    Merge_Sort(nums, left, mid);
    Merge_Sort(nums, mid + 1, right);
    Merge(nums, left, mid, right);
}
