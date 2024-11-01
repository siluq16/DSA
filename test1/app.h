#ifndef APP_H
#define APP_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Nhanvien.h"
#include "Cinema.h"
#include "schedule.h"
#include "Movie.h"

using namespace std;

class App
{
private:
    vector<NhanVien> employees;
    vector<Rap> cinemas;
    vector<Phim> movies;
    vector<LichChieu> schedules;

public:
    void menu()
    {
        int choice;
        do
        {
            cout << "\n----- Menu -----\n";
            cout << "1. Quản lý nhân viên\n";
            cout << "2. Quản lý rạp\n";
            cout << "3. Quản lý phim\n";
            cout << "4. Quản lý lịch chiếu\n";
            cout << "5. Quản lý doanh thu\n";
            cout << "0. Thoát\n";
            cout << "Chọn: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                manageEmployees();
                break;
            case 2:
                manageCinemas();
                break;
            case 3:
                manageMovies();
                break;
            case 4:
                manageSchedules();
                break;
            case 5:
                manageRevenue();
                break;
            case 0:
                cout << "Thoát chương trình.\n";
                break;
            default:
                cout << "Lựa chọn không hợp lệ. Vui lòng thử lại.\n";
            }
        } while (choice != 0);
    }

    void manageEmployees();

    void manageCinemas();

    void manageMovies();

    void manageSchedules();

    void manageRevenue();
};

void App::manageEmployees()
{
    int choice;
    do
    {
        cout << "\n--- Quản lý Nhân viên ---\n";
        cout << "1. Thêm nhân viên\n";
        cout << "2. Sửa thông tin nhân viên\n";
        cout << "3. Xóa nhân viên\n";
        cout << "4. Xem danh sách nhân viên\n";
        cout << "0. Quay lại\n";
        cout << "Chọn: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            NhanVien nv;
            cin >> nv;
            employees.push_back(nv);
            cout << "Đã thêm nhân viên có mã: " << nv.getEmployeeID() << endl;
            break;
        }
        case 2:
        {
            string id;
            cout << "Nhập mã nhân viên cần sửa: ";
            cin >> id;
            bool found = false; 
            for (auto &nv : employees)
            {
                if (nv.getEmployeeID() == id)
                {
                    cout << "Sửa thông tin nhân viên:\n";
                    cin >> nv;
                    cout << "Đã sửa thông tin nhân viên có mã: " << id << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Không tìm thấy nhân viên có mã: " << id << endl;
            }
            break;
        }
        case 3:
        {
            string id;
            cout << "Nhập mã nhân viên cần xóa: ";
            cin >> id;
            auto it = remove_if(employees.begin(), employees.end(),
                                [&id](NhanVien &nv) { return nv.getEmployeeID() == id; });
            if (it != employees.end())
            {
                employees.erase(it, employees.end());
                cout << "Đã xóa nhân viên có mã: " << id << endl;
            }
            else
            {
                cout << "Không tìm thấy nhân viên có mã: " << id << endl;
            }
            break;
        }
        case 4:
            if (employees.empty())
            {
                cout << "Chưa có nhân viên nào.\n"; 
            }
            else
            {
                for (const auto &nv : employees)
                {
                    cout << nv;
                }
            }
            break;
        case 0:
            break;
        default:
            cout << "Lựa chọn không hợp lệ.\n";
        }
    } while (choice != 0);
}
void App::manageCinemas()
{
    int choice;
    do
    {
        cout << "\n--- Quản lý Rạp ---\n";
        cout << "1. Thêm rạp\n";
        cout << "2. Sửa thông tin rạp\n";
        cout << "3. Xóa rạp\n";
        cout << "4. Xem danh sách rạp\n";
        cout << "5. Tìm rạp có doanh thu cao/thấp nhất\n";
        cout << "0. Quay lại\n";
        cout << "Chọn: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Rap r;
            cin >> r;
            cinemas.push_back(r);
            cout << "Đã thêm rạp có mã: " << r.getCinemaID() << endl;
            break;
        }
        case 2:
        {
            string id;
            cout << "Nhập mã rạp cần sửa: ";
            cin >> id;
            bool found = false;
            for (auto &r : cinemas)
            {
                if (r.getCinemaID() == id)
                {
                    cout << "Sửa thông tin rạp:\n";
                    cin >> r;
                    cout << "Đã sửa thông tin rạp có mã: " << id << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Không tìm thấy rạp có mã: " << id << endl;
            }
            break;
        }
        case 3:
        {
            string id;
            cout << "Nhập mã rạp cần xóa: ";
            cin >> id;
            auto it = remove_if(cinemas.begin(), cinemas.end(), [&id](Rap &r) { return r.getCinemaID() == id; });
            if (it != cinemas.end())
            {
                cinemas.erase(it, cinemas.end());
                cout << "Đã xóa rạp có mã: " << id << endl;
            }
            else
            {
                cout << "Không tìm thấy rạp có mã: " << id << endl;
            }
            break;
        }
        case 4:
            if (cinemas.empty())
            {
                cout << "Chưa có rạp nào.\n"; 
            }
            else
            {
                for (const auto &r : cinemas)
                {
                    cout << r;
                }
            }
            break;
        case 5:
        {
            if (!cinemas.empty())
            {
                auto maxCinema = max_element(cinemas.begin(), cinemas.end(),
                                             [](Rap &a, Rap &b) { return a.getRevenue() < b.getRevenue(); });
                auto minCinema = min_element(cinemas.begin(), cinemas.end(),
                                             [](Rap &a, Rap &b) { return a.getRevenue() < b.getRevenue(); });

                cout << "Rạp có doanh thu cao nhất:\n" << *maxCinema;
                cout << "Rạp có doanh thu thấp nhất:\n" << *minCinema;
            }
            else
            {
                cout << "Chưa có rạp nào.\n";
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Lựa chọn không hợp lệ.\n";
        }
    } while (choice != 0);
}


void App::manageMovies()
{
    int choice;
    do
    {
        cout << "\n--- Quản lý Phim ---\n";
        cout << "1. Thêm phim\n";
        cout << "2. Sửa thông tin phim\n";
        cout << "3. Xóa phim\n";
        cout << "4. Xem danh sách phim\n";
        cout << "5. Tìm phim có doanh thu cao/thấp nhất\n";
        cout << "0. Quay lại\n";
        cout << "Chọn: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Phim p;
            cin >> p;
            movies.push_back(p);
            cout << "Đã thêm phim có mã: " << p.getMovieID() << endl;
            break;
        }
        case 2:
        {
            string id;
            cout << "Nhập mã phim cần sửa: ";
            cin >> id;
            bool found = false; 
            for (auto &p : movies)
            {
                if (p.getMovieID() == id)
                {
                    cout << "Sửa thông tin phim:\n";
                    cin >> p;
                    cout << "Đã sửa thông tin phim có mã: " << id << endl;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Không tìm thấy phim có mã: " << id << endl;
            }
            break;
        }
        case 3:
        {
            string id;
            cout << "Nhập mã phim cần xóa: ";
            cin >> id;
            auto it = remove_if(movies.begin(), movies.end(),
                                [&id](Phim &p) { return p.getMovieID() == id; });
            if (it != movies.end())
            {
                movies.erase(it, movies.end());
                cout << "Đã xóa phim có mã: " << id << endl;
            }
            else
            {
                cout << "Không tìm thấy phim có mã: " << id << endl;
            }
            break;
        }
        case 4:
            if (movies.empty())
            {
                cout << "Chưa có phim nào.\n";
            }
            else
            {
                for (const auto &p : movies)
                {
                    cout << p;
                }
            }
            break;
        case 5:
        {
            if (!movies.empty())
            {
                auto maxMovie = max_element(movies.begin(), movies.end(),
                                            [](Phim &a, Phim &b) { return a.getRevenue() < b.getRevenue(); });
                auto minMovie = min_element(movies.begin(), movies.end(),
                                            [](Phim &a, Phim &b) { return a.getRevenue() < b.getRevenue(); });

                cout << "Phim có doanh thu cao nhất:\n" << *maxMovie;
                cout << "Phim có doanh thu thấp nhất:\n" << *minMovie;
            }
            else
            {
                cout << "Chưa có phim nào.\n";
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Lựa chọn không hợp lệ.\n";
        }
    } while (choice != 0);
}

void App::manageSchedules()
{
    int choice;
    do
    {
        cout << "\n--- Quản lý Lịch Chiếu ---\n";
        cout << "1. Thêm lịch chiếu\n";
        cout << "2. Sửa lịch chiếu\n";
        cout << "3. Xóa lịch chiếu\n";
        cout << "4. Xem danh sách lịch chiếu\n";
        cout << "0. Quay lại\n";
        cout << "Chọn: ";
        cin >> choice;

        switch (choice)
        {
        case 1: 
        {
            LichChieu lc;
            cin >> lc;

            bool movieExists = any_of(movies.begin(), movies.end(),
                                       [&lc](const Phim &p) { return p.getMovieID() == lc.getMovieID(); });
            if (!movieExists)
            {
                cout << "Mã phim không tồn tại: " << lc.getMovieID() << endl;
                break; 
            }

            bool cinemaExists = any_of(cinemas.begin(), cinemas.end(),
                                       [&lc](const Rap &r) { return r.getCinemaID() == lc.getCinemaID(); });
            if (!cinemaExists)
            {
                cout << "Mã rạp không tồn tại: " << lc.getCinemaID() << endl;
                break; 
            }

            schedules.push_back(lc);
            cout << "Đã thêm lịch chiếu cho phim: " << lc.getMovieID() << " tại rạp: " << lc.getCinemaID() << endl;
            break;
        }
        case 2:
        {
            string id;
            cout << "Nhập mã lịch chiếu cần sửa: ";
            cin >> id;

            auto it = find_if(schedules.begin(), schedules.end(),
                              [&id](const LichChieu &lc) { return lc.getScheduleID() == id; });

            if (it != schedules.end())
            {
                cout << "Sửa thông tin lịch chiếu:\n";
                cin >> *it; 
                cout << "Đã sửa lịch chiếu với mã: " << id << endl;
            }
            else
            {
                cout << "Không tìm thấy lịch chiếu với mã: " << id << endl;
            }
            break;
        }
        case 3: 
        {
            string id;
            cout << "Nhập mã lịch chiếu cần xóa: ";
            cin >> id;

            auto it = remove_if(schedules.begin(), schedules.end(),
                                [&id](const LichChieu &lc) { return lc.getScheduleID() == id; });

            if (it != schedules.end())
            {
                schedules.erase(it, schedules.end());
                cout << "Đã xóa lịch chiếu với mã: " << id << endl;
            }
            else
            {
                cout << "Không tìm thấy lịch chiếu với mã: " << id << endl;
            }
            break;
        }
        case 4: 
            if (schedules.empty())
            {
                cout << "Chưa có lịch chiếu nào.\n"; 
            }
            else
            {
                for (const auto &lc : schedules)
                {
                    cout << lc;
                }
            }
            break;
        case 0: 
            break;
        default:
            cout << "Lựa chọn không hợp lệ.\n";
        }
    } while (choice != 0);
}

void App::manageRevenue()
{
    int choice;
    do
    {
        cout << "\n--- Quản lý Doanh thu ---\n";
        cout << "1. Tìm phim có doanh thu cao/thấp nhất\n";
        cout << "2. Tìm rạp có doanh thu cao/thấp nhất\n";
        cout << "3. Hiển thị danh sách phim theo doanh thu\n";
        cout << "4. Hiển thị danh sách rạp theo doanh thu\n";
        cout << "0. Quay lại\n";
        cout << "Chọn: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (!movies.empty())
            {
                auto maxMovie = max_element(movies.begin(), movies.end(),
                                            [](const Phim &a, const Phim &b)
                                            { return a.getRevenue() < b.getRevenue(); });
                auto minMovie = min_element(movies.begin(), movies.end(),
                                            [](const Phim &a, const Phim &b)
                                            { return a.getRevenue() < b.getRevenue(); });

                cout << "Phim có doanh thu cao nhất:\n" << *maxMovie;
                cout << "Phim có doanh thu thấp nhất:\n" << *minMovie;
            }
            else
            {
                cout << "Chưa có phim nào.\n";
            }
            break;
        }
        case 2:
        {
            if (!cinemas.empty())
            {
                auto maxCinema = max_element(cinemas.begin(), cinemas.end(),
                                             [](const Rap &a, const Rap &b)
                                             { return a.getRevenue() < b.getRevenue(); });
                auto minCinema = min_element(cinemas.begin(), cinemas.end(),
                                             [](const Rap &a, const Rap &b)
                                             { return a.getRevenue() < b.getRevenue(); });

                cout << "Rạp có doanh thu cao nhất:\n" << *maxCinema;
                cout << "Rạp có doanh thu thấp nhất:\n" << *minCinema;
            }
            else
            {
                cout << "Chưa có rạp nào.\n";
            }
            break;
        }
        case 3:
        {
            if (!movies.empty())
            {
                sort(movies.begin(), movies.end(),
                     [](const Phim &a, const Phim &b)
                     { return a.getRevenue() > b.getRevenue(); });

                cout << "\nDanh sách phim theo doanh thu (giảm dần):\n";
                for (const auto &p : movies)
                {
                    cout << p;
                }
            }
            else
            {
                cout << "Chưa có phim nào để hiển thị.\n";
            }
            break;
        }
        case 4:
        {
            if (!cinemas.empty())
            {
                sort(cinemas.begin(), cinemas.end(),
                     [](const Rap &a, const Rap &b)
                     { return a.getRevenue() > b.getRevenue(); });

                cout << "\nDanh sách rạp theo doanh thu (giảm dần):\n";
                for (const auto &r : cinemas)
                {
                    cout << r;
                }
            }
            else
            {
                cout << "Chưa có rạp nào để hiển thị.\n";
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Lựa chọn không hợp lệ.\n";
        }
    } while (choice != 0);
}


#endif 
