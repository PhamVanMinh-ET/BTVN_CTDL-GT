#include <iostream>
#include "../Header/basic_sort.hpp"
#include "../Header/complex_sort.hpp"
#include "../Header/test_vector.hpp"
using namespace std;

int main() {
    int choose;
    cout << "Choose your sorting algorithm: \n"
        << "1. Selection Sort \n"
        << "2. Bubble Sort \n"
        << "3. Insertion Sort \n"
        << "4. Quick Sort \n"
        << "5. Merge Sort \n";
    cout << "Your choice: "; cin >> choose;
    
    for (int i = 0; i < nums_count; i++) {
        int* arr = new int[nums_size[i]];
        for (int j = 0; j < nums_size[i]; j++) {
            arr[j] = nums[i][j];
        }

        cout << "\n Your array before sorting: ";
        for (int j = 0; j < nums_size[i]; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;

        switch(choose) {
            case 1:
                cout << "Selection Sort: " << endl;
                selection(arr, nums_size[i]);
                break;
            
            case 2:
                cout << "Bubble Sort: " << endl;
                bubble(arr, nums_size[i]);
                break;

            case 3:
                cout << "Insertion Sort: " << endl;
                insertion(arr, nums_size[i]);
                break;
            
            case 4:
                cout << "Quick Sort: " << endl;
                Quick_Sort(arr, nums_size[i]);
                break;

            case 5:
                cout << "Merge Sort: " << endl;
                Merge_Sort(arr, 0, nums_size[i] - 1);
                break;

            default: 
                cout << "Error" << endl;
                break;

        }
        delete[] arr;

    }
    return 0;
}