#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "lib/Game.h"
#include "lib/PrimitivePainter.h"
#include "lib/v2.h"
#include <iostream>
#include <vector>
using namespace std;
using namespace lvichki;

int main(int, char**) {
    lvichki::Game win;

    win.on_update = [&]() {
    };

    win.on_draw = [&]() {
        draw_rect({540, 670}, {100, 50}, SDL_GetTicks() / 1000.0f, {0, 128, 255, 255});
        win.draw_text("PREVED MEDVED!", 30, 70, {255, 255, 0, 255});
    };
    
    win.on_event = [&](const SDL_Event& e) {
        if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
            cout << "Mouse clicked at: " << e.button.x << ", " << e.button.y << endl;
        }
    };

    win.run();
    return 0;
}
