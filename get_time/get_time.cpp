#include <string>
#include <chrono>


std::string get_time_now() {
    auto time_now = std::chrono::system_clock::now();
    std::time_t time_now_t = std::chrono::system_clock::to_time_t(time_now);
    std::string res = std::ctime(&time_now_t);
    res.pop_back();
    return res;
}

