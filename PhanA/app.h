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

template <typename T>
void manageEntities(vector<T> &entities,
                    const string &entityName,
                    function<void(T &)> inputFunction,
                    function<string(const T &)> getIDFunction,
                    function<double(const T &)> getSortValueFunction)
{
    int choice;
    do
    {
        cout << "\n--- Quản lý " << entityName << " ---\n";
        cout << "1. Thêm " << entityName << "\n";
        cout << "2. Sửa thông tin " << entityName << "\n";
        cout << "3. Xóa " << entityName << "\n";
        cout << "4. Xem danh sách " << entityName << "\n";
        cout << "5. Sắp xếp danh sách " << entityName << "\n";
        cout << "0. Quay lại\n";
        cout << "Chọn: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            T entity;
            inputFunction(entity);
            entities.push_back(entity);
            cout << "Đã thêm " << entityName << " có mã: " << getIDFunction(entity) << endl;
            break;
        }
        case 2:
        {
            string id;
            cout << "Nhập mã " << entityName << " cần sửa: ";
            cin >> id;

            auto it = find_if(entities.begin(), entities.end(),
                              [&id, &getIDFunction](const T &entity)
                              { return getIDFunction(entity) == id; });

            if (it != entities.end())
            {
                cout << "Sửa thông tin " << entityName << ":\n";
                inputFunction(*it);
                cout << "Đã sửa thông tin " << entityName << " có mã: " << id << endl;
            }
            else
            {
                cout << "Không tìm thấy " << entityName << " có mã: " << id << endl;
            }
            break;
        }
        case 3:
        {
            string id;
            cout << "Nhập mã " << entityName << " cần xóa: ";
            cin >> id;
            auto it = remove_if(entities.begin(), entities.end(),
                                [&id, &getIDFunction](T &entity)
                                { return getIDFunction(entity) == id; });
            if (it != entities.end())
            {
                entities.erase(it, entities.end());
                cout << "Đã xóa " << entityName << " có mã: " << id << endl;
            }
            else
            {
                cout << "Không tìm thấy " << entityName << " có mã: " << id << endl;
            }
            break;
        }
        case 4:
        {
            if (entities.empty())
            {
                cout << "Chưa có " << entityName << " nào.\n";
            }
            else
            {
                for (const auto &entity : entities)
                {
                    cout << entity;
                }
            }
            break;
        }
        case 5:
        {
            cout << "Sắp xếp danh sách " << entityName << ":\n";
            cout << "1. Từ cao đến thấp\n";
            cout << "2. Từ thấp đến cao\n";
            int sortChoice;
            cin >> sortChoice;

            if (sortChoice == 1)
            {
                sort(entities.begin(), entities.end(),
                     [&getSortValueFunction](const T &a, const T &b)
                     { return getSortValueFunction(a) > getSortValueFunction(b); });
            }
            else if (sortChoice == 2)
            {
                sort(entities.begin(), entities.end(),
                     [&getSortValueFunction](const T &a, const T &b)
                     { return getSortValueFunction(a) < getSortValueFunction(b); });
            }
            cout << "Danh sách " << entityName << " sau khi sắp xếp:\n";
            for (const auto &entity : entities)
            {
                cout << entity;
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
    manageEntities<NhanVien>(
        employees,
        "Nhân viên",
        [](NhanVien &nv)
        { cin >> nv; },
        [](const NhanVien &nv)
        { return nv.getEmployeeID(); },
        [](const NhanVien &nv)
        { return nv.getSalary(); });
}
void App::manageCinemas()
{
    manageEntities<Rap>(
        cinemas,
        "Rạp",
        [](Rap &r)
        { cin >> r; },
        [](const Rap &r)
        { return r.getCinemaID(); },
        [](const Rap &r)
        { return r.getRevenue(); });
}

void App::manageMovies()
{
    manageEntities<Phim>(
        movies,
        "Phim",
        [](Phim &p)
        { cin >> p; },
        [](const Phim &p)
        { return p.getMovieID(); },
        [](const Phim &p)
        { return p.getRevenue(); });
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
                                      [&lc](const Phim &p)
                                      { return p.getMovieID() == lc.getMovieID(); });
            if (!movieExists)
            {
                cout << "Mã phim không tồn tại: " << lc.getMovieID() << endl;
                break;
            }

            bool cinemaExists = any_of(cinemas.begin(), cinemas.end(),
                                       [&lc](const Rap &r)
                                       { return r.getCinemaID() == lc.getCinemaID(); });
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
                              [&id](const LichChieu &lc)
                              { return lc.getScheduleID() == id; });

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
                                [&id](const LichChieu &lc)
                                { return lc.getScheduleID() == id; });

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

                cout << "Phim có doanh thu cao nhất:\n"
                     << *maxMovie;
                cout << "Phim có doanh thu thấp nhất:\n"
                     << *minMovie;
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

                cout << "Rạp có doanh thu cao nhất:\n"
                     << *maxCinema;
                cout << "Rạp có doanh thu thấp nhất:\n"
                     << *minCinema;
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
