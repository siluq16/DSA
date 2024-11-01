#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>
using namespace std;

class NhanVien {
private:
    string employeeID;
    string name;
    string position;
    float salary;

public:
    NhanVien() : employeeID(""), name(""), position(""), salary(0.0f) {}
    NhanVien(string id, string n, string p, float s) : employeeID(id), name(n), position(p), salary(s) {}

    friend istream& operator>>(istream& is, NhanVien& nv) {
        cout << "Nhập mã nhân viên: "; is >> nv.employeeID;
        cout << "Nhập tên nhân viên: "; is.ignore(); getline(is, nv.name);
        cout << "Nhập chức vụ: "; getline(is, nv.position);
        cout << "Nhập lương: "; is >> nv.salary;
        return is;
    }

    friend ostream& operator<<(ostream& os, const NhanVien& nv) {
        os << "Mã nhân viên: " << nv.employeeID << ", Tên: " << nv.name 
           << ", Chức vụ: " << nv.position << ", Lương: " << nv.salary << endl;
        return os;
    }

    bool operator<(const NhanVien& other) const {
        return salary < other.salary;
    }

    string getEmployeeID() const { return employeeID; }
    string getName() const { return name; }
    string getPosition() const { return position; }
    float getSalary() const { return salary; }

};

#endif