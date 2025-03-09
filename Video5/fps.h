#ifndef FPS_H
#define FPS_H

#include "main.h"

class Fps {
    public:
        Fps()
            : dt{0},
              target_delay{TARGET_DELAY},
              max_delay{50.0},
              last_time{std::chrono::steady_clock::now()},
              carry_delay{0},
              first_elapsed{0},
              second_elapsed{0},
              last_fps{std::chrono::steady_clock::now()},
              fps_delay{std::chrono::seconds(1)},
              frames{0},
              enable_fps{false} {}

        void increaseSpeed();
        void decreaseSpeed();
        void update();
        void toggleFps();

        double dt;

    private:
        void show_fps();

        std::chrono::duration<double, std::milli> target_delay;
        const std::chrono::duration<double, std::milli> max_delay;
        std::chrono::time_point<std::chrono::steady_clock> last_time;
        std::chrono::time_point<std::chrono::steady_clock> current_time;
        std::chrono::duration<double, std::milli> carry_delay;
        std::chrono::duration<double, std::milli> first_elapsed;
        std::chrono::duration<double, std::milli> second_elapsed;
        std::chrono::time_point<std::chrono::steady_clock> last_fps;
        const std::chrono::steady_clock::duration fps_delay;
        unsigned int frames;
        bool enable_fps;
};

#endif
