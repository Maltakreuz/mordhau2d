#pragma once
#include <ostream>

struct v2 {
    float x, y;

    v2() : x(0), y(0) {}
    v2(float x_, float y_) : x(x_), y(y_) {}

    v2 operator+(const v2& other) const {
        return v2(x + other.x, y + other.y);
    }

    v2 operator-(const v2& other) const {
        return v2(x - other.x, y - other.y);
    }

    v2 operator*(float scalar) const {
        return v2(x * scalar, y * scalar);
    }

    v2& operator+=(const v2& other) {
        x += other.x; y += other.y;
        return *this;
    }

    v2& operator-=(const v2& other) {
        x -= other.x; y -= other.y;
        return *this;
    }
    
    v2& operator+=(float value) {
        x += value; y += value;
        return *this;
    }
    
    v2& operator*=(float value) {
        x *= value; y *= value;
        return *this;
    }

    float dot(const v2& other) const {
        return x * other.x + y * other.y;
    }

    float length_squared() const {
        return x * x + y * y;
    }

    float length() const {
        return sqrt(length_squared());
    }
    
    v2 operator/(float scalar) const {
        if (scalar == 0) return v2(0, 0);
        return v2(x / scalar, y / scalar);
    }

    bool operator==(const v2& other) const {
        return x == other.x && y == other.y;
    }

    v2 operator-() const {
        return v2(-x, -y);
    }

    v2 normalized() const {
        float len = length();
        return (len > 0) ? v2(x / len, y / len) : v2(0, 0);
    }
    
    void normalize() {
        float len = length();
        if (len > 0) {
            x /= len;
            y /= len;
        } else {
            x = y = 0;
        }
    }

    v2 operator*(const v2& other) const {
        return {x * other.x, y * other.y};
    }

    v2 operator/(const v2& other) const {
        return {x / other.x, y / other.y};
    }
};

inline std::ostream& operator<<(std::ostream& os, const v2& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

// Функция для преобразования диапазона (как map() в Arduino или Processing)
float mapValue(float val, float in_min, float in_max, float out_min, float out_max) {
    // Ограничиваем входное значение, чтобы цвет не "сломался" за пределами диапазона
    if (val < in_min) val = in_min;
    if (val > in_max) val = in_max;
    return out_min + (out_max - out_min) * ((val - in_min) / (in_max - in_min));
}