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

    Part* parent = nullptr;
    float parent_offset = 100.0f;

    float parent_offset_x = 0.0f;

    void update() {
        if (!parent) return;

        float parent_angle = parent->angle;
        if (parent->parent) {
            parent_angle += parent->parent->angle;
            if (parent->parent->parent) {
                parent_angle += parent->parent->parent->angle;
            }
        }
        v2 offset = {cosf((parent_angle + 90) * DEG2RAD), sinf((parent_angle + 90) * DEG2RAD)};
        v2 offset_x = {cosf((parent_angle + 0) * DEG2RAD), sinf((parent_angle + 0) * DEG2RAD)};
        pos = parent->pos + offset * parent_offset + offset_x * parent_offset_x;
    }

    void draw() {
        SDL_Rect dst;
        SDL_QueryTexture(sprite, NULL, NULL, &dst.w, &dst.h);
        dst.x = (int)(pos.x - dst.w * pivot.x);
        dst.y = (int)(pos.y - dst.h * pivot.y);
        SDL_Point center = {(int)(dst.w * pivot.x), (int)(dst.h * pivot.y)};

        float parent_angle = parent ? parent->angle : 0.0f;
        if (parent && parent->parent) {
            parent_angle += parent->parent->angle;
            if (parent->parent->parent) {
                parent_angle += parent->parent->parent->angle;
            }
        }
        float a = angle + parent_angle;
        SDL_RenderCopyEx(renderer, sprite, NULL, &dst, a, &center, SDL_FLIP_NONE);

        if (!dbg_draw) return;
        draw_rect(pos, size * 0.5f, a, CLR_ROYAL_BLUE, pivot);
        draw_circle((int)pos.x, (int)pos.y, 3, CLR_RED);
    }
};

}