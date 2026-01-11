#pragma once
#include <SDL2/SDL.h>

namespace lvichki {

void draw_circle(int cx, int cy, int radius, SDL_Color color) {
    int segments = std::fmax(6, radius);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    float angle_step = 2.0f * M_PI / segments;

    for (int i = 0; i < segments; ++i) {
        float a0 = i * angle_step;
        float a1 = (i + 1) * angle_step;

        int x0 = cx + (int)(cosf(a0) * radius);
        int y0 = cy + (int)(sinf(a0) * radius);
        int x1 = cx + (int)(cosf(a1) * radius);
        int y1 = cy + (int)(sinf(a1) * radius);

        SDL_RenderDrawLine(renderer, x0, y0, x1, y1);
    }
}

void draw_line(v2 a, v2 b, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    int x0 = (int) a.x;
    int y0 = (int) a.y;
    int x1 = (int) b.x;
    int y1 = (int) b.y;
    SDL_RenderDrawLine(renderer, x0, y0, x1, y1);
}

void draw_rect(v2 center, v2 half_size, float angle_deg, SDL_Color color, v2 pivot = {0.5f, 0.5f}) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    
    float angle_rad = angle_deg * (M_PI / 180.0f);
    float c = cosf(angle_rad);
    float s = sinf(angle_rad);

    // смещаем углы с учётом pivot
    v2 offset = {half_size.x * (pivot.x * 2 - 1), half_size.y * (pivot.y * 2 - 1)};

    v2 corners[4] = {
        {-half_size.x - offset.x, -half_size.y - offset.y},
        { half_size.x - offset.x, -half_size.y - offset.y},
        { half_size.x - offset.x,  half_size.y - offset.y},
        {-half_size.x - offset.x,  half_size.y - offset.y}
    };

    v2 world[4];
    for (int i = 0; i < 4; i++) {
        world[i] = {
            center.x + corners[i].x * c - corners[i].y * s,
            center.y + corners[i].x * s + corners[i].y * c
        };
    }

    for (int i = 0; i < 4; i++) {
        int j = (i + 1) % 4;
        SDL_RenderDrawLine(
            renderer,
            (int)world[i].x, (int)world[i].y,
            (int)world[j].x, (int)world[j].y
        );
    }
}

void draw_grid(int screen_width, int screen_height, int step, SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // вертикальные линии
    for (int x = 0; x <= screen_width; x += step) {
        SDL_RenderDrawLine(renderer, x, 0, x, screen_height);
    }

    // горизонтальные линии
    for (int y = 0; y <= screen_height; y += step) {
        SDL_RenderDrawLine(renderer, 0, y, screen_width, y);
    }
}

}