# Hướng Dẫn Sử Dụng Chương Trình Sắp Xếp

Chương trình này cho phép bạn chạy nhiều thuật toán sắp xếp khác nhau trên các bộ **test vector** được chuẩn bị sẵn trong dự án.

## 1. Cách Chạy Chương Trình

### Cách 1: Chạy bằng `run.bat`

Nhấp đúp chuột hoặc chạy trong PowerShell:

```
./run.bat
```

Chương trình sẽ tự động biên dịch và chạy.

### Cách 2: Tự biên dịch bằng g++

Vào thư mục `Source` và chạy:

```
g++ main.cpp basic_sort.cpp complex_sort.cpp test_vector.cpp -I ../Header -o run.exe
./run.exe
```

## 2. Chọn Thuật Toán Sắp Xếp

Khi chương trình chạy, bạn sẽ chọn một trong các phương pháp sau:

| Số | Tên Thuật Toán |
| -- | -------------- |
| 1  | Selection Sort |
| 2  | Bubble Sort    |
| 3  | Insertion Sort |
| 4  | Quick Sort     |
| 5  | Merge Sort     |

Nhập số tương ứng và nhấn Enter.

## 3. Bộ Test Vector Hoạt Động Như Thế Nào?

Các mảng dữ liệu kiểm thử được định nghĩa trong file:

```
Header/test_vector.hpp
Source/test_vector.cpp
```

Mỗi bộ test sẽ tự động được gửi vào thuật toán bạn chọn.

## 4. Xuất Kết Quả

Chương trình sẽ:

* In mảng **trước khi sắp xếp**
* In **kết quả từng bước xử lý** (để quan sát cách thuật toán hoạt động)

## 5. Ghi Chú Quan Trọng

* Đảm bảo đã cài `g++` trước khi chạy.
* Nếu lỗi biên dịch, hãy kiểm tra lại đường dẫn thư mục hoặc file header.

---


