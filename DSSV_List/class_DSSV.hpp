#pragma once
#include <string>
#include <iostream>
using namespace std;

class DSSV {
	class SV {
	public:
		string Name;
		string MSSV;
		int NamSinh;
		double GPA;
		SV* Next;
	public:
		SV(const string& name, const string& mssv, const int& nam_sinh, const double& gpa) {
			Name = name;
			MSSV = mssv;
			NamSinh = nam_sinh;
			GPA = gpa;
			Next = 0;
		}
	};

	SV* firstSV;

public:
	DSSV() { firstSV = 0; }
	~DSSV() {
		while (firstSV) {
			SV* p = firstSV;
			firstSV = p->Next;
			delete p;
		}
	}

public:
	// Chieu dai danh sach:
	int DSSV_length() {
		SV* p = firstSV;
		int count = 0;
		while (p) {
			count++;
			p = p->Next;
		}
		return count;
	}
	// Them vao dau danh sach:
	void addFirst(const string& name, const string& mssv, const int& nam_sinh, const double& gpa) {
		SV* p = new SV(name, mssv, nam_sinh, gpa);
		if (!firstSV) firstSV = p;
		else {
			p->Next = firstSV;
			firstSV = p;
		}
	}
	// Them vao cuoi danh sach:
	void addLast(const string& name, const string& mssv, const int& nam_sinh, const double& gpa) {
		SV* p = new SV(name, mssv, nam_sinh, gpa);
		if (!firstSV) {
			firstSV = p;
			return;
		}

		SV* last = firstSV;
		while (last->Next) last = last->Next;
		last->Next = p;
	}

	// In danh sach thong tin sinh vien: 
	void SV_print() {
		SV* p = firstSV;
		int k = DSSV_length();
		cout << "\n Do dai danh sach la: " << k << endl;
		if (k == 0) cout << "Danh sach rong" << endl;
		else {
			while (p) {
				cout << "Sinh vien thu " << k << " : " << endl;
				cout << "  Ho va ten: " << p->Name << endl;
				cout << "  MSSV: " << p->MSSV << endl;
				cout << "  Nam sinh: " << p->NamSinh << endl;
				cout << "  GPA: " << p->GPA << endl;
				p = p->Next;
				k--;
			}
		}
	}

	// So luong sinh vien co GPA tren 3.2: 
	int Good_SV() {
		SV* p = firstSV;
		int count = 0;
		while (p) {
			if (p->GPA > 3.2) count++;
			p = p->Next;
		}
		return count;
	}
	
	// Tron 2 danh sach da duoc sap xep: 
	SV* mergeTwoSV(SV* a, SV* b) {
		if (a == 0) return b;
		if (b == 0) return a;
		if (a->GPA <= b->GPA) {
			a->Next = mergeTwoSV(a->Next, b);
			return a;
		}
		else {
			b->Next = mergeTwoSV(a, b->Next);
			return b;
		}
	}
	// Tim sinh vien o giua danh sach bat ky:
	SV* findMid(SV* first) {
		if (first == 0) return first;
		SV* tur = first;
		SV* rab = first;
		while (rab->Next && rab->Next->Next) {
			tur = tur->Next;
			rab = rab->Next->Next;
		}
		return tur;
	}
	// Sap xep tron tren list bat ky
	SV* mergeSort(SV* first) {
		if (first == 0 || first->Next == 0) return first;
		
		SV* mid = findMid(first);
		SV* right = mid->Next;
		mid->Next = 0;

		// De quy:
		SV* left_SV = mergeSort(first);
		SV* right_SV = mergeSort(right);

		return mergeTwoSV(left_SV, right_SV);
	}
	// Sap xep theo thu tu tang dan GPA:
	void sorting_GPA() {
		firstSV = mergeSort(firstSV);
	}

	
	// Chen them sinh vien duoc 2.4 GPA vao dung vi tri:
	void Add_sv() {
		SV* p = new SV("PVM", "2024", 2006, 2.4);
		if (firstSV == 0) {
			firstSV = p;
			return;
		}
		// Sap xep lai danh sach
		sorting_GPA();

		if (p->GPA <= firstSV->GPA) {
			p->Next = firstSV;
			firstSV = p;
			return;
		}
		SV* prev = firstSV;
		SV* next = firstSV->Next;
		while (next && next->GPA < p->GPA) {
			prev = prev->Next;
			next = next->Next;
		}
		p->Next = prev->Next;
		prev->Next = p;
	}



}; 