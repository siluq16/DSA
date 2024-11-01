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
    void themHangHoa(const HangHoa &hang)
    {
        for (auto it = danhSachHang.begin(); it != danhSachHang.end(); ++it)
        {
            if ((*it).getTenHang() == hang.getTenHang()) 
            {
                (*it).tangSoLuong(hang.getSoLuong());
                return;
            }
        }
        danhSachHang.addLast(hang);
    }

    void botHangHoa(const string& tenHang, int soLuong) {
        for (auto it = danhSachHang.begin(); it != danhSachHang.end(); ++it) {
            if ((*it).getTenHang() == tenHang) { 
                (*it).giamSoLuong(soLuong);
                if ((*it).getSoLuong() <= 0) {
                    danhSachHang.remove(*it);
                }
                return;
            }
        }
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
        for (auto it = danhSachHang.begin(); it != danhSachHang.end(); ++it)
        {
            (*it).xuatThongTin(); 
            cout << "\n";
        }
        cout << "Tong tien: " << tinhTongTien() << "\n";
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
