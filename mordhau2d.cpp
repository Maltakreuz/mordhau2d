#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_ttf.h>
#include "lib/LvichkiEngine.h"
#include <iostream>
#include <vector>
using namespace std;
using namespace lvichki;


// TODO:
// - legs and walking
// - make other decorative body parts
// - enemy
// - hit detection
// - block
// - hp and stamina and death
// - sound
// - idle anim
// - feint and Q only in first phase, then cancelation is not possible anymore
// - stab and morphing attacks
// - make 3 attacks: up, middle, down
//
// - this type of game needs solid foundation in hierchical parts and animation editor, but this will take much longer as MVP itself. Currently only 3 levels of hierarchy supported (shoulder -> arm -> sword).


float WIND_UP_TIME = 0.8f;
float ATTACK_TIME = 0.2f;
float RECOVERY_TIME = 0.7f;

float MOVEMENT_SPEED = 300;

SDL_Texture* body_sprite = nullptr;
SDL_Texture* head_sprite = nullptr;
SDL_Texture* shoulder_L_sprite = nullptr;
SDL_Texture* arm_L_sprite = nullptr;
SDL_Texture* sword_sprite = nullptr;
SDL_Texture* shin_L_sprite = nullptr;
SDL_Texture* leg_L_sprite = nullptr;
SDL_Texture* shin_R_sprite = nullptr;
SDL_Texture* leg_R_sprite = nullptr;
SDL_Texture* hand_R_sprite = nullptr;


SDL_Texture* load_sprite(const char* path) {
    SDL_Texture* tex = IMG_LoadTexture(renderer, path);
    if (!tex) {
        cout << "Failed to load texture " << path << ": " << SDL_GetError() << endl;
    }
    return tex;
}

void load_textures() {
    body_sprite = load_sprite("content/lizard/body.png");
    head_sprite = load_sprite("content/lizard/head.png");
    shoulder_L_sprite = load_sprite("content/lizard/shoulder_L.png");
    arm_L_sprite = load_sprite("content/lizard/arm_L.png");
    sword_sprite = load_sprite("content/lizard/two_sword_3.png");
    shin_L_sprite = load_sprite("content/lizard/shin_L.png");
    leg_L_sprite = load_sprite("content/lizard/leg_L.png");
    shin_R_sprite = load_sprite("content/lizard/shin_R.png");
    leg_R_sprite = load_sprite("content/lizard/leg_R.png");
    hand_R_sprite = load_sprite("content/lizard/hand_R.png");
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
    head.pos = {0, 0};
    head.sprite = head_sprite;
    head.size = {118, 95};
    head.parent = &body;
    head.parent_offset = -130;
    head.parent_offset_x = 35.0f;

    Part shoulder_L;
    shoulder_L.pos = {0, 0};
    shoulder_L.sprite = shoulder_L_sprite;
    shoulder_L.size = {56, 138};
    shoulder_L.pivot = {0.4f, 0.15f};
    shoulder_L.parent = &body;
    shoulder_L.angle = -25.0f;
    shoulder_L.parent_offset = -35.0f;
    shoulder_L.parent_offset_x = 20.0f;

    Part arm_L;
    arm_L.pos = {600, 500};
    arm_L.sprite = arm_L_sprite;
    arm_L.size = {48, 112};
    arm_L.pivot = {0.5f, 0.9f};
    arm_L.parent = &shoulder_L;
    arm_L.angle = 135.0f;

    Part sword;
    sword.pos = {450, 400};
    sword.sprite = sword_sprite;
    sword.size = {58, 480};
    sword.pivot = {0.5f, 0.9f};
    sword.parent = &arm_L;
    sword.angle = -90.0f;
    sword.parent_offset = -120.0f;
    sword.angle = -90.0f;

    Part hand_R;
    hand_R.pos = {0, 0};
    hand_R.sprite = hand_R_sprite;
    hand_R.size = {129, 269};
    hand_R.pivot = {0.5f, 0.1f};
    hand_R.parent = &body;
    hand_R.parent_offset = -35.0f;
    hand_R.parent_offset_x = -70.0f;

    Part shin_L;
    shin_L.pos = {0, 0};
    shin_L.sprite = shin_L_sprite;
    shin_L.size = {122, 193};
    shin_L.pivot = {0.25f, 0.1f};
    shin_L.parent = &body;
    shin_L.angle = 0.0f;

    Part leg_L;
    leg_L.pos = {0, 0};
    leg_L.sprite = leg_L_sprite;
    leg_L.size = {122, 237};
    leg_L.pivot = {0.5f, 0.1f};
    leg_L.parent = &shin_L;
    leg_L.angle = 0.0f;
    leg_L.parent_offset = 160.0f;
    leg_L.parent_offset_x = 50.0f;

    Part shin_R;
    shin_R.pos = {0, 0};
    shin_R.sprite = shin_R_sprite;
    shin_R.size = {122, 193};
    shin_R.pivot = {0.5f, 0.1f};
    shin_R.parent = &body;
    shin_R.angle = 0.0f;
    shin_R.parent_offset_x = -25.0f;

    Part leg_R;
    leg_R.pos = {0, 0};
    leg_R.sprite = leg_R_sprite;
    leg_R.size = {122, 237};
    leg_R.pivot = {0.75f, 0.1f};
    leg_R.parent = &shin_R;
    leg_R.angle = 0.0f;
    leg_R.parent_offset = 180.0f;
    leg_R.parent_offset_x = -40.0f;



    vector<Part*> parts;
    parts.push_back(&shoulder_L);
    parts.push_back(&arm_L);
    parts.push_back(&sword);
    parts.push_back(&leg_L);
    parts.push_back(&shin_L);
    parts.push_back(&body);
    parts.push_back(&leg_R);
    parts.push_back(&shin_R);
    parts.push_back(&head);
    parts.push_back(&hand_R);


    FloatAnimator2 shoulder_L_anim(&shoulder_L.angle,
        -25, RECOVERY_TIME,
        -210, WIND_UP_TIME,
        -80, ATTACK_TIME
    );
    
    FloatAnimator2 arm_L_anim(&arm_L.angle,
        135, RECOVERY_TIME,
        90, WIND_UP_TIME,
        230, ATTACK_TIME
    );
    FloatAnimator2 sword_anim(&sword.angle,
        -90, RECOVERY_TIME,
        -50, WIND_UP_TIME,
        -50, ATTACK_TIME
    );

    vector<FloatAnimator2*> high_slash;
    high_slash.emplace_back(&shoulder_L_anim);
    high_slash.emplace_back(&arm_L_anim);
    high_slash.emplace_back(&sword_anim);

    FloatAnimator2 leg_L_anim(&leg_L.angle,
        0, .005f,
        -30, .25f,
        0, .5f
    );
    FloatAnimator2 shin_L_anim(&shin_L.angle,
        0, .005f,
        30, .5f,
        0, .25f
    );
    
    FloatAnimator2 shin_R_anim(&shin_R.angle,
        0, .005f,
        -30, .15f,
        0, .6f
    );
    FloatAnimator2 leg_R_anim(&leg_R.angle,
        0, .005f,
        30, .4f,
        0, .33f
    );

    FloatAnimator2 hand_R_anim(&hand_R.angle,
        0, .005f,
        -10, .37f,
        0, .44f
    );

    leg_L_anim.loop = true;
    shin_L_anim.loop = true;
    leg_R_anim.loop = true;
    shin_R_anim.loop = true;
    hand_R_anim.loop = true;

    vector<FloatAnimator2*> walk_anim;
    walk_anim.emplace_back(&leg_L_anim);
    walk_anim.emplace_back(&shin_L_anim);
    walk_anim.emplace_back(&leg_R_anim);
    walk_anim.emplace_back(&shin_R_anim);
    walk_anim.emplace_back(&hand_R_anim);

    for (auto& anim : walk_anim) {
        anim->play();
    }

    game.on_update = [&]() {
        auto keyStates = SDL_GetKeyboardState(nullptr);
        bool moving = false;
        if( keyStates[SDL_SCANCODE_A] == true) {
            body.pos.x -= MOVEMENT_SPEED * game.fixed_dt;
            moving = true;
        } else if( keyStates[SDL_SCANCODE_D] == true) {
            body.pos.x += MOVEMENT_SPEED * game.fixed_dt;
            moving = true;
        }

        for (auto& part : parts) {
            part->update();
        }
        for (auto& anim : high_slash) {
            anim->update(game.fixed_dt);
        }

        if (moving) {
            for (auto& anim : walk_anim) {
                anim->update(game.fixed_dt);
            }
        }
    };
    game.on_draw = [&]() {
        if (dbg_draw) {
            draw_grid(game.width, game.height, 100, CLR_DARK_GRAY);
        }

        for (auto& part : parts) {
            part->draw();
        }

        game.draw_text("left click - attack, Q or <Space> cancel attack (feint), a/d move", 230, 30, CLR_DARK_ORANGE);
        int mouse_x, mouse_y;
        SDL_GetMouseState(&mouse_x, &mouse_y);
        //game.draw_text(("mouse x, y: " + to_string(mouse_x) + ", " + to_string(mouse_y)).c_str(), 30, 130, CLR_DARK_ORANGE);
    };
    
    game.on_event = [&](const SDL_Event& e) {
        if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
            for (auto& anim : high_slash) {
                anim->play();
            }
        }
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_F5) {
            dbg_draw = !dbg_draw;
        }

        if (e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_q || e.key.keysym.sym == SDLK_SPACE)) {
            for (auto& anim : high_slash) {
                anim->reset(0.3f);
            }
        }


        
    };

    game.run();
    return 0;
}
