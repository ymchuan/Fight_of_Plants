#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vector2.h"
#include "timer.h"

class Camera
{
public:
	Camera()
	{
		timer_shake.set_one_shot(true);
		timer_shake.set_callback([&]()
			{
				is_shaking = false;
				reset();
			});
	}
	~Camera() = default;

	const Vector2& get_position() const
	{
		return position;
	}

	void reset()
	{
		position.x = 0;
		position.y = 0;
	}

	void shake(float strength, int duration)
	{
		is_shaking = true;
		shaking_strength = strength;

		timer_shake.set_wait_time(duration);
		timer_shake.restart();
	}
	void on_update(int delta)
	{
		timer_shake.on_update(delta);

		if (is_shaking)
		{
			position.x = (-50 + rand() % 100) / 50.0f * shaking_strength,
			position.y = (-50 + rand() % 100) / 50.0f * shaking_strength;
		}
	}
private:
	Vector2 position;
	Timer timer_shake; // �����������ʱ��
	bool is_shaking = false; // �Ƿ��ڶ���
	float shaking_strength = 0; // ��������
};

#endif // !_CAMERA_H_

