#ifndef CINEMA_H
#define CINEMA_H

#include <iostream>
#include <string>

using namespace std;

class Rap {
private:
    string cinemaID;
    string cinemaName;
    int seatCount;
    float revenue;

public:
    Rap() {}
    Rap(string id, string name, int seats) : cinemaID(id), cinemaName(name), seatCount(seats), revenue(0.0f) {}

    friend istream& operator>>(istream& is, Rap& r) {
        cout << "Nhập mã rạp: "; is >> r.cinemaID;
        cout << "Nhập tên rạp: "; is.ignore(); getline(is, r.cinemaName);
        cout << "Nhập số ghế: "; is >> r.seatCount;
        return is;
    }

    friend ostream& operator<<(ostream& os, Rap& r) {
        os << "Mã rạp: " << r.cinemaID << ", Tên rạp: " << r.cinemaName 
           << ", Số ghế: " << r.seatCount << ", Doanh thu: " << r.revenue << endl;
        return os;
    }

    bool operator<(Rap& other) {
        return revenue < other.revenue;
    }

    void updateRevenue(float amount) { revenue += amount; }

    float getRevenue() { return revenue; }
    string getCinemaID() { return cinemaID; }
    string getCinemaName() { return cinemaName; }
    int getSeatCount() { return seatCount; }

};

#endif 