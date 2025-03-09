#include "game.h"

Game::~Game() {
    this->message.reset();
    this->fps.reset();
    this->board.reset();

    this->renderer.reset();
    this->window.reset();

    TTF_Quit();
    SDL_Quit();

    std::cout << "all clean!" << std::endl;
}

void Game::init() {
    this->init_sdl();

    this->board.reset(new Board(this->renderer));
    this->board->init();

    this->fps.reset(new Fps());

    this->message.reset(new Message(this->renderer));
    this->message->init(this->is_paused, this->fps->getDelay());
}

void Game::togglePause() {
    this->is_paused = !is_paused;
    this->message->update(this->is_paused, this->fps->getDelay());
}

void Game::increaseSpeed() {
    this->fps->increaseSpeed();
    this->message->update(this->is_paused, this->fps->getDelay());
}

void Game::decreaseSpeed() {
    this->fps->decreaseSpeed();
    this->message->update(this->is_paused, this->fps->getDelay());
}

void Game::events() {
    while (SDL_PollEvent(&this->event)) {
        switch (this->event.type) {
        case SDL_EVENT_QUIT:
            this->is_running = false;
            return;
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            if (event.button.button == SDL_BUTTON_LEFT) {
                this->board->edit(this->event.button.x, this->event.button.y);
            }
            break;
        case SDL_EVENT_KEY_DOWN:
            switch (this->event.key.scancode) {
            case SDL_SCANCODE_ESCAPE:
                this->is_running = false;
                break;
            case SDL_SCANCODE_SPACE:
                this->togglePause();
                break;
            case SDL_SCANCODE_UP:
                this->increaseSpeed();
                break;
            case SDL_SCANCODE_DOWN:
                this->decreaseSpeed();
                break;
            case SDL_SCANCODE_R:
                this->board->reset();
                break;
            case SDL_SCANCODE_C:
                this->board->clear();
                break;
            case SDL_SCANCODE_F:
                this->fps->toggleFps();
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void Game::update() {
    if (!is_paused) {
        this->board->update();
    }
}

void Game::draw() const {
    SDL_SetRenderDrawColor(this->renderer.get(), RENDERER_COLOR);
    SDL_RenderClear(this->renderer.get());

    this->board->draw();
    this->message->draw();

    SDL_RenderPresent(this->renderer.get());
}

void Game::run() {
    while (this->is_running) {
        this->events();

        this->update();

        this->draw();

        this->fps->update();
    }
}
