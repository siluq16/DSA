#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
using namespace std;

class Phim {
private:
    string movieID;
    string movieName;
    string genre;
    float revenue;

public:
    Phim() : movieID(""), movieName(""), genre(""), revenue(0.0f) {}
    Phim(string id, string name, string g) : movieID(id), movieName(name), genre(g), revenue(0.0f) {}

    friend istream& operator>>(istream& is, Phim& p) {
        cout << "Nhập mã phim: "; is >> p.movieID;
        cout << "Nhập tên phim: "; is.ignore(); getline(is, p.movieName);
        cout << "Nhập thể loại phim: "; getline(is, p.genre);
        return is;
    }

    friend ostream& operator<<(ostream& os, const Phim& p) {
        os << "Mã phim: " << p.movieID << ", Tên phim: " << p.movieName 
           << ", Thể loại: " << p.genre << ", Doanh thu: " << p.revenue << endl;
        return os;
    }

    bool operator<(const Phim& other) const {
        return revenue < other.revenue;
    }

    void updateRevenue(float amount) { revenue += amount; }

    string getMovieID() const { return movieID; }
    string getMovieName() const { return movieName; }
    float getRevenue() const { return revenue; }

};

#endif
