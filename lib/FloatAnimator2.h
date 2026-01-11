#pragma once

class FloatAnimator2 {
public:

    bool loop = false;

    FloatAnimator2(
        float* target,
        float start,
        float time3,
        float target1,
        float time1,
        float target2,
        float time2
    )
        : target(target),
          start(start),
          t1(target1),
          t2(target2),
          d1(time1),
          d2(time2),
          d3(time3)
    {
        *target = start;
    }

    void play() {
        phase = Phase::ToTarget1;
        elapsed = 0.0f;
        from = *target;
        to = t1;
        duration = d1;
        playing = true;
    }

    void update(float delta_time) {
        if (!playing && !loop) return;

        elapsed += delta_time;
        float progress = duration > 0.0f ? elapsed / duration : 1.0f;
        if (progress > 1.0f) progress = 1.0f;

        *target = from + (to - from) * progress;

        if (elapsed >= duration) {
            advance_phase();
        }
    }

    void reset(float seconds) {
        phase = Phase::Reset;
        elapsed = 0.0f;
        from = *target;
        to = start;
        duration = seconds;
        playing = true;
    }

    bool is_playing() const {
        return playing;
    }

private:
    enum class Phase {
        None,
        ToTarget1,
        ToTarget2,
        ToStart,
        Reset
    };

    void advance_phase() {
        elapsed = 0.0f;

        switch (phase) {
            case Phase::ToTarget1:
                phase = Phase::ToTarget2;
                from = *target;
                to = t2;
                duration = d2;
                break;

            case Phase::ToTarget2:
                phase = Phase::ToStart;
                from = *target;
                to = start;
                duration = d3;
                break;

            case Phase::ToStart:
            case Phase::Reset:
                playing = false;
                phase = Phase::None;
                break;
            case Phase::None:
                if (loop) {
                    play();
                }
                break;
        }
    }

private:
    float* target;

    float start;
    float t1;
    float t2;

    float d1;
    float d2;
    float d3;

    float from = 0.0f;
    float to = 0.0f;
    float duration = 0.0f;
    float elapsed = 0.0f;

    bool playing = false;
    Phase phase = Phase::None;
};
