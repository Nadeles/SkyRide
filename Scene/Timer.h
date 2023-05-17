#pragma once

#include <iostream>
#include <chrono>

class Timer {
public:
    Timer();
    // обновляет delta_time_ и last_update_time_
    void Update();
    // возвращает delta_time_
    float GetDelta() const;
    // возвращает время, прошедшее с момента запуска таймера
    float GetTime() const;
private:
    std::chrono::time_point<std::chrono::steady_clock> start_time_;
    std::chrono::time_point<std::chrono::steady_clock> last_update_time_;
    std::chrono::microseconds delta_time_{};
};
