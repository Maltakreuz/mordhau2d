#pragma once

class FloatAnimator {
public:
    FloatAnimator(float* target, float start, float end, float duration)
        : target(target), start(start), end(end), duration(duration), elapsed(0.0f) {
        *target = start;
    }

    void update(float delta_time) {
        if (elapsed >= duration) return;
        
        elapsed += delta_time;
        if (elapsed > duration) elapsed = duration;
        
        float progress = elapsed / duration;
        *target = start + (end - start) * progress;
    }

    bool is_complete() const {
        return elapsed >= duration;
    }

    void reset() {
        elapsed = 0.0f;
        *target = start;
    }

private:
    float* target;
    float start;
    float end;
    float duration;
    float elapsed;
};
