#ifndef HANGHOA_H
#define HANGHOA_H

#include <iostream>
#include <string>
using namespace std;

class HangHoa {
private:
    int maHang;
    string tenHang;
    int soLuong;
    double donGia;

public:
    HangHoa() {}

    void nhapThongTin() {
        cout << "Nhap ma hang: ";
        cin >> maHang;
        cout << "Nhap ten hang: ";
        cin.ignore(); 
        getline(cin, tenHang);
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cout << "Nhap don gia: ";
        cin >> donGia;
    }

    void xuatThongTin() {
        cout << "Ma hang: " << maHang << "\n"
             << "Ten hang: " << tenHang << "\n"
             << "So luong: " << soLuong << "\n"
             << "Don gia: " << donGia << "\n";
    }

    bool operator==(HangHoa& other) {
        return maHang == other.maHang; 
    }

    int getMaHang() { return maHang; }
    string getTenHang() { return tenHang; }
    int getSoLuong() { return soLuong; }
    double getDonGia() { return donGia; }

    void tangSoLuong(int sl) { soLuong += sl; }
    void giamSoLuong(int sl) { soLuong -= sl; }
};

#endif
