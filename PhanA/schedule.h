#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include <string>
using namespace std;

class LichChieu {
private:
    string scheduleID;
    string movieID;
    string cinemaID;
    string showTime;
    float ticketPrice;
    int seatsSold;  


public:
    LichChieu() {}
    LichChieu(string sid, string mid, string cid, string stime, float price, int sold) 
        : scheduleID(sid), movieID(mid), cinemaID(cid), showTime(stime), ticketPrice(price), seatsSold(sold) {}

    friend istream& operator>>(istream& is, LichChieu& lc) {
        cout << "Nhập mã lịch chiếu: "; is >> lc.scheduleID;
        cout << "Nhập mã phim: "; is >> lc.movieID;
        cout << "Nhập mã rạp: "; is >> lc.cinemaID;
        cout << "Nhập thời gian chiếu (YYYY-MM-DD HH:MM): "; is.ignore(); getline(is, lc.showTime);
        cout << "Nhập giá vé: "; is >> lc.ticketPrice;
        cout << "Nhập số ghế đã bán: "; is >> lc.seatsSold;  
        return is;
    }

    friend ostream& operator<<(ostream& os, LichChieu& lc) {
        os << "Mã lịch chiếu: " << lc.scheduleID << ", Mã phim: " << lc.movieID 
           << ", Mã rạp: " << lc.cinemaID << ", Thời gian chiếu: " << lc.showTime 
           << ", Giá vé: " << lc.ticketPrice << ", Số ghế đã bán: " << lc.seatsSold << endl;
        return os;
    }

    float calculateRevenue() { return ticketPrice * seatsSold; }

    float getTicketPrice() { return ticketPrice; }
    string getMovieID() { return movieID; }
    string getCinemaID() { return cinemaID; }
    int getSeatsSold() { return seatsSold; }
    string getScheduleID() { return scheduleID; }
};

#endif 
