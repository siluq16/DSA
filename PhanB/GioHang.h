#ifndef GIOHANG_H
#define GIOHANG_H

#include <iostream>
#include <fstream>
#include <string>
#include "HangHoa.h"
#include "SingleList.h"
using namespace std;

class GioHang
{
private:
    SingleList<HangHoa> danhSachHang;

public:
    void themHangHoa(HangHoa &hang)
{
    for (auto it = danhSachHang.begin(); it != danhSachHang.end(); ++it)
    {
        if (*it == hang)  
        {
            (*it).tangSoLuong(hang.getSoLuong());
            return;
        }
    }
    danhSachHang.push_back(hang);
}


    void botHangHoa(int& maHang, int soLuong) {
        for (auto it = danhSachHang.begin(); it != danhSachHang.end(); ++it) {
            if ((*it).getMaHang() == maHang ) { 
                (*it).giamSoLuong(soLuong);
                if ((*it).getSoLuong() <= 0) {
                    danhSachHang.erase(*it);
                }
                return;
            }
        }
    }

    bool checkMa(int& maHang) {
        for (auto it = danhSachHang.begin(); it != danhSachHang.end(); ++it) {
            if ((*it).getMaHang() == maHang ) { 
                return true;
            }
        }
        return false;
    }

    double tinhTongTien() const
    {
        double tong = 0;
        for (auto it = danhSachHang.begin(); it != danhSachHang.end(); ++it)
        {
            tong += (*it).getSoLuong() * (*it).getDonGia(); 
        }
        return tong;
    }

    void xuatGioHang() const
    {
        if (danhSachHang.empty()){
            cout << "Gio Hang Trong" << endl;
        }
        else {
            for (auto it = danhSachHang.begin(); it != danhSachHang.end(); ++it)
        {
            (*it).xuatThongTin(); 
            cout << "<------------------->\n";
        }
        cout << "Tong tien: " << tinhTongTien() << "\n";
        }
    }

    void xuatHoaDon() const
    {
        ofstream file("hoadon.txt");
        if (file.is_open())
        {
            for (auto it = danhSachHang.begin(); it != danhSachHang.end(); ++it)
            {
                file << "Ten hang: " << (*it).getTenHang() << "\n"; 
                file << "So luong: " << (*it).getSoLuong() << "\n"; 
                file << "Don gia: " << (*it).getDonGia() << "\n\n"; 
            }
            file << "Tong tien: " << tinhTongTien() << "\n";
            file.close();
        }
        else
        {
            cerr << "Khong the mo file hoadon.txt\n";
        }
    }
};

#endif
