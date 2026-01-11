#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_ttf.h>
#include "lib/LvichkiEngine.h"
#include <iostream>
#include <vector>
using namespace std;
using namespace lvichki;


// TODO:
// - connect parts in hierarchy
// - make attack anim on mouse click

SDL_Texture* body_sprite = nullptr;
SDL_Texture* head_sprite = nullptr;
SDL_Texture* shoulder_L_sprite = nullptr;
SDL_Texture* arm_L_sprite = nullptr;

void load_textures() {
    body_sprite = IMG_LoadTexture(renderer, "content/lizard/body.png");
    head_sprite = IMG_LoadTexture(renderer, "content/lizard/head.png");
    shoulder_L_sprite = IMG_LoadTexture(renderer, "content/lizard/shoulder_L.png");
    arm_L_sprite = IMG_LoadTexture(renderer, "content/lizard/arm_L.png");
}

void draw_sprite(int x, int y, SDL_Texture* tex) {
    SDL_Rect dst = {x, y, 0, 0};
    SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopy(renderer, tex, NULL, &dst);
}

int main(int, char**) {
    Game game;
    load_textures();

    Part body;
    body.pos = {400, 400};
    body.sprite = body_sprite;
    body.size = {134, 350};

    Part head;
    head.pos = {430, 270};
    head.sprite = head_sprite;
    head.size = {118, 95};

    Part shoulder_L;
    shoulder_L.pos = {420, 363};
    shoulder_L.sprite = shoulder_L_sprite;
    shoulder_L.size = {56, 138};
    shoulder_L.pivot = {0.4f, 0.15f};

    Part arm_L;
    arm_L.pos = {600, 500};
    arm_L.sprite = arm_L_sprite;
    arm_L.size = {48, 112};
    arm_L.pivot = {0.5f, 0.9f};

    vector<Part*> parts;
    parts.push_back(&shoulder_L);
    parts.push_back(&arm_L);
    parts.push_back(&body);
    parts.push_back(&head);
    

    FloatAnimator shoulder_L_anim(&shoulder_L.angle, -45.0f, -90.0f, 1.0f);

    game.on_update = [&]() {
        for (auto& part : parts) {
            part->update();
        }
        
        shoulder_L_anim.update(game.fixed_dt);
    };
    game.on_draw = [&]() {
        if (dbg_draw) {
            draw_grid(game.width, game.height, 100, CLR_DARK_GRAY);
        }

        for (auto& part : parts) {
            part->draw();
        }

        game.draw_text(("HAND ANGLE " + to_string(shoulder_L.angle)).c_str(), 30, 70, CLR_DARK_ORANGE);
        game.draw_text(("Delta Time: " + to_string(game.dt)).c_str(), 30, 100, CLR_DARK_ORANGE);
        game.draw_text(("Fixed delta Time: " + to_string(game.fixed_dt)).c_str(), 30, 130, CLR_DARK_ORANGE);
        int mouse_x, mouse_y;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        game.draw_text(("mouse x, y: " + to_string(mouse_x) + ", " + to_string(mouse_y)).c_str(), 30, 160, CLR_DARK_ORANGE);
    };
    
    game.on_event = [&](const SDL_Event& e) {
        if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
            shoulder_L_anim.reset();
        }
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_F5) {
            dbg_draw = !dbg_draw;
        }
    };

    game.run();
    return 0;
}
