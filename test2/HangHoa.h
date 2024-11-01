#ifndef HANGHOA_H
#define HANGHOA_H

#include <iostream>
#include <string>
using namespace std;

class HangHoa {
private:
    string tenHang;
    int soLuong;
    double donGia;

public:
    HangHoa() : tenHang(""), soLuong(0), donGia(0.0) {}

    void nhapThongTin() {
        cout << "Nhap ten hang: ";
        cin >> tenHang;
        cout << "Nhap so luong: ";
        cin >> soLuong;
        cout << "Nhap don gia: ";
        cin >> donGia;
    }

    void xuatThongTin() const {
        cout << "Ten hang: " << tenHang << "\n"
             << "So luong: " << soLuong << "\n"
             << "Don gia: " << donGia << "\n";
    }

    bool operator==(const HangHoa& other) const {
        return tenHang == other.tenHang; // So sánh theo tên hàng
    }

    string getTenHang() const { return tenHang; }
    int getSoLuong() const { return soLuong; }
    double getDonGia() const { return donGia; }

    void tangSoLuong(int sl) { soLuong += sl; }
    void giamSoLuong(int sl) { soLuong -= sl; }
};

#endif
