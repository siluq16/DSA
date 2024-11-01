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
    Rap() : cinemaID(""), cinemaName(""), seatCount(0), revenue(0.0f) {}
    Rap(string id, string name, int seats) : cinemaID(id), cinemaName(name), seatCount(seats), revenue(0.0f) {}

    friend istream& operator>>(istream& is, Rap& r) {
        cout << "Nhập mã rạp: "; is >> r.cinemaID;
        cout << "Nhập tên rạp: "; is.ignore(); getline(is, r.cinemaName);
        cout << "Nhập số ghế: "; is >> r.seatCount;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Rap& r) {
        os << "Mã rạp: " << r.cinemaID << ", Tên rạp: " << r.cinemaName 
           << ", Số ghế: " << r.seatCount << ", Doanh thu: " << r.revenue << endl;
        return os;
    }

    bool operator<(const Rap& other) const {
        return revenue < other.revenue;
    }

    void updateRevenue(float amount) { revenue += amount; }

    float getRevenue() const { return revenue; }
    string getCinemaID() const { return cinemaID; }
    string getCinemaName() const { return cinemaName; }
    int getSeatCount() const { return seatCount; }

};

#endif 