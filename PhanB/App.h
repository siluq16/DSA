#ifndef APP_H
#define APP_H

#include <iostream>
#include "GioHang.h"
#include "HangHoa.h"
using namespace std;

class App {
private:
    GioHang gioHang;

public:
    void run() {
        char choice;
        do {
            cout << "Chon thao tac:\n";
            cout << "1. Them hang hoa\n";
            cout << "2. Bot hang hoa\n";
            cout << "3. Xem gio hang\n";
            cout << "4. Xuat hoa don ra file\n";
            cout << "0. Thoat\n";
            cout << "Lua chon: ";
            cin >> choice;

            switch (choice) {
                case '1': {
                    HangHoa hang;
                    hang.nhapThongTin();
                    gioHang.themHangHoa(hang);
                    break;
                }
                case '2': {
                    int maHang;
                    int soLuong;
                    cout << "<------------------->\n";
                    cout << "Nhap ma hang: ";
                    cin >> maHang;
                    if (gioHang.checkMa(maHang)) {
                        cout << "Nhap so luong bot: ";
                        cin >> soLuong;
                        gioHang.botHangHoa(maHang, soLuong);
                        break;
                    }
                    else {
                        cout << "Ma hang khon ton tai !" << endl;
                        break;
                    }
                }
                case '3': {
                    cout << "Noi dung gio hang:\n";
                    cout << "<------------------->\n";
                    gioHang.xuatGioHang();
                    break;
                }
                case '4': {
                    gioHang.xuatHoaDon();
                    cout << "Da xuat hoa don ra file hoadon.txt\n";
                    break;
                }
                case '0':
                    cout << "Ket thuc chuong trinh.\n";
                    break;
                default:
                    cout << "Lua chon khong hop le!\n";
                    break;
            }
        } while (choice != '0');
    }
};

#endif
