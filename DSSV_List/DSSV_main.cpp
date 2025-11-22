#include "class_DSSV.hpp"

int main() {
    DSSV ds;

    // Thêm sinh viên để test
   
    ds.addLast("Dat",   "202001", 2002, 3.1);
    ds.addLast("Vu", "202002", 2003, 2.0);
    ds.addLast("Minh",  "202003", 2001, 3.7);

    ds.addFirst("Duy", "202004", 2000, 1.8);

    cout << "\n Danh sach ban dau \n";
    ds.SV_print();

    // Sắp xếp danh sách theo GPA tăng dần
    ds.sorting_GPA();
    cout << "\n Sau khi sap xep tang dan theo GPA\n";
    ds.SV_print();

    // Thêm sinh viên GPA = 2.4
    cout << "\n Sau khi them sinh vien GPA = 2.4 \n";
    ds.Add_sv();
    ds.SV_print();

    // In số lượng SV có GPA > 3.2
    cout << "\nSo sinh vien GPA > 3.2 la: " 
         << ds.Good_SV() << endl;

    return 0;
}
