#include "SDL2/SDL_video.h"
#include <SDL2/SDL.h>
#include <cstdio>
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define DELAY 16
#define GRAVITY -9.8

enum PlayerState {
  IDLE,
  MOVING_LEFT,
  MOVING_RIGHT,
  JUMPING,
};

class Player {
  double x, y;

  PlayerState state;
  Player() {
    x = 0;
    y = 0;
    state = IDLE;
  }

  void updateState(PlayerState state) {
    switch (state) {
    case IDLE:
      break;
    case MOVING_LEFT:
      x -= 1;
      break;
    case MOVING_RIGHT:
      x += 1;
      break;
    case JUMPING:
      y += GRAVITY;
      break;
    }
  }
};

void draw_square(int x, int y) {
  SDL_Rect rect;
  rect.x = x;
  rect.x = x;
}

int main(int argc, char *args[]) {
  SDL_Window *window = nullptr;
  SDL_Renderer *renderer = nullptr;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError()
              << std::endl;
    return 1;
  }

  window = SDL_CreateWindow("Double Buffer Example", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                            SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (window == nullptr) {
    std::cout << "Window could not be created! SDL_Error: " << SDL_GetError()
              << std::endl;
    return 1;
  }

  renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == nullptr) {
    std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError()
              << std::endl;
    return 1;
  }

  SDL_Rect rect = {0, 0, 50, 50};
  int direction = 1;
  bool quit = false;
  SDL_Event e;

  while (!quit) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        quit = true;
      }

      if (e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym) {
        case SDLK_LEFT:
          rect.x -= 1;
          break;
        case SDLK_RIGHT:
          rect.x += 1;
          break;
        case SDLK_UP:
          rect.y -= 1;
          break;
        case SDLK_DOWN:
          rect.y += 1;
          break;
        }
      }
    }

    // Clear the back buffer
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Draw on the back buffer
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rect);

    // Update rectangle position
    rect.x += direction;
    if (rect.x <= 0 || rect.x + rect.w >= SCREEN_WIDTH) {
      direction *= -1;
    }

    // Swap buffers (present the back buffer)
    SDL_RenderPresent(renderer);

    SDL_Delay(DELAY); // Cap at roughly 60 fps
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
