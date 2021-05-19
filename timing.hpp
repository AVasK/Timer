#pragma once

#include <chrono>
#include <iostream>

namespace timing {
    
    template <typename Clock, typename unit>
    class TimerBase;

    using namespace std::chrono;
    using ms = milliseconds;
    using ns = nanoseconds;

    template <typename Units =milliseconds>
    using Timer = TimerBase<high_resolution_clock, Units>;

    using msTimer = Timer<milliseconds>;
    using nsTimer = Timer<nanoseconds>;

    
    // Conversion for output
    template <typename T>
    struct convert {};

    template<>
    struct convert<milliseconds>
    {
        static constexpr char prefix = 'm';
    };

    template<>
    struct convert<nanoseconds>
    {
        static constexpr char prefix = 'n';
    };

    template<>
    struct convert<seconds>
    {
        static constexpr char prefix = ' ';
    };


    // Clumsy Timer template with all the settings
    template <typename Clock, typename unit =nanoseconds>
    class TimerBase {
    public:
        TimerBase(const char* _name="unnamed")
        : start_time {Clock::now()}
        , name{_name} {}
        
        void time(const char* _caption = "") {
            auto curr_time = Clock::now();
            auto elapsed = duration_cast<unit>(curr_time - start_time).count();
            if (*_caption != '\0')
                std::cout << name << " timer @ [" << _caption << "] time: "
                          << elapsed << " " << convert<unit>::prefix<<"s\n";
            else
                std::cout << name << " timer time: "
                          << elapsed << " " << convert<unit>::prefix<<"s\n";
        }
        
        ~TimerBase() {
            time();
        }
        
    private:
        time_point<Clock> start_time;
        const char* name;
    };

}; // ~timing
