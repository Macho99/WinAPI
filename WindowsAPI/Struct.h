#pragma once

struct Vec2
{
	float x;
	float y;

	Vec2() : x(0), y(0) {}

	Vec2(float x, float y) : x(x), y(y) {}

	void Normalize() {
		float magnitude = Magnitude();

		if (magnitude == 0) return;

		x /= magnitude;
		y /= magnitude;
	}

	Vec2 Normalized() {
		float magnitude = Magnitude();

		if (magnitude == 0) return Vec2(0, 0);

		return Vec2(x / magnitude, y / magnitude);
	}

	float Length() {
		return Magnitude();
	}

	float Magnitude() {
		return sqrtf(x * x + y * y);
	}

	// 루트 연산이 오버헤드가 크므로 
	// 거리 비교연산 등에서 루트 연산을 쓰지 않을 수 있으면 이걸 사용
	float SqrMagnitude() {
		return x * x + y * y;
	}

	Vec2 operator+(const Vec2& other)
	{
		return Vec2(x + other.x, y + other.y);
	}

	Vec2& operator+=(const Vec2& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	Vec2 operator-(const Vec2& other)
	{
		return Vec2(x - other.x, y - other.y);
	}

	Vec2& operator-=(const Vec2& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}

	template <typename T>
	Vec2 operator*(const T& num)
	{
		return Vec2(x * num, y * num);
	}

	template <typename T>
	Vec2& operator*=(const T& num)
	{
		x *= num;
		y *= num;

		return *this;
	}

	template <typename T>
	Vec2 operator/(const T& num)
	{
		assert(0 != num && "Vector cannot divide by 0");
		return Vec2(x / num, y / num);
	}

	template <typename T>
	Vec2& operator/=(const T& num)
	{
		assert(0 != num && "Vector cannot divide by 0");
		x /= num;
		y /= num;

		return *this;
	}
};