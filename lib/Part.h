#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "LvichkiEngine.h"
#include <iostream>

namespace lvichki {

struct Part {
    v2 pos = {0.0f, 0.0f};
    v2 size = {10.0f, 10.0f};
    v2 pivot = {0.5f, 0.5f};
    float angle = 0.0f;
    SDL_Texture* sprite;

    void update() {
    }

    void draw() {
        SDL_Rect dst;
        SDL_QueryTexture(sprite, NULL, NULL, &dst.w, &dst.h);
        dst.x = (int)(pos.x - dst.w * pivot.x);
        dst.y = (int)(pos.y - dst.h * pivot.y);
        SDL_Point center = {(int)(dst.w * pivot.x), (int)(dst.h * pivot.y)};
        SDL_RenderCopyEx(renderer, sprite, NULL, &dst, angle, &center, SDL_FLIP_NONE);

        if (!dbg_draw) return;
        draw_rect(pos, size * 0.5f, angle, CLR_ROYAL_BLUE, pivot);
        draw_circle((int)pos.x, (int)pos.y, 3, CLR_RED);
    }
};

}