#include "fps.h"

void Fps::increaseSpeed() {
    if (this->target_delay.count() > 8) {
        this->target_delay /= 2;
    }
}

void Fps::decreaseSpeed() {
    if (this->target_delay.count() < 1024) {
        this->target_delay *= 2;
    }
}

double Fps::getDelay() { return this->target_delay.count(); }

void Fps::toggleFps() {
    if (this->enable_fps) {
        this->enable_fps = false;
    } else {
        this->enable_fps = true;
        this->frames = 0;
        this->last_fps = std::chrono::steady_clock::now();
        this->carry_delay = std::chrono::duration<double, std::milli>(0.0);
    }
}

void Fps::show_fps() {
    if (this->enable_fps) {
        auto current_fps_time = std::chrono::steady_clock::now();
        if (current_fps_time >= this->last_fps + this->fps_delay) {
            std::cout << this->frames << std::endl;
            this->last_fps = this->last_fps + this->fps_delay;
            this->frames = 0;
        }
        this->frames++;
    }
}

void Fps::update() {
    this->current_time = std::chrono::steady_clock::now();
    this->first_elapsed = this->current_time - this->last_time;
    auto sleep_duration = std::chrono::duration_cast<std::chrono::milliseconds>(
        this->target_delay - this->first_elapsed + this->carry_delay);

    if (sleep_duration.count() > 0) {
        std::this_thread::sleep_for(sleep_duration);
    }

    this->current_time = std::chrono::steady_clock::now();
    this->second_elapsed = this->current_time - this->last_time;

    this->dt = this->second_elapsed.count() / 1000;

    this->carry_delay =
        this->target_delay - this->second_elapsed + this->carry_delay;
    if (this->carry_delay > this->max_delay) {
        this->carry_delay = this->max_delay;
    } else if (this->carry_delay < -(this->max_delay)) {
        this->carry_delay = -(this->max_delay);
    }
    this->last_time = this->current_time;

    this->show_fps();
}
