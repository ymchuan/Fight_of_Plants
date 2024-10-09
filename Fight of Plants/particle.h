#pragma once

#include "vector2.h"
#include "atlas.h"
#include "util.h"

class Particle
{
public:
	Particle() = default;
	Particle(const Vector2& position, Atlas* atlas, int lifespan)
		: position(position), atlas(atlas), lifespan(lifespan) { }
	~Particle() = default;

	void set_atlas(Atlas* new_atlas)
	{
		atlas = new_atlas;
	}

	void set_position(const	Vector2& new_postion)
	{
		position = new_postion;
	}

	void set_lifespan(int ms)
	{
		lifespan = ms;
	}

	bool check_valid() const 
	{
		return valid;
	}

	void on_update(int delta)
	{
		timer += delta;
		if (timer >= lifespan)
		{
			timer = 0;
			idx_frame++;
			if (idx_frame >= atlas->get_size())
			{
				idx_frame = atlas->get_size() - 1;
				valid = false;
			}
		}
	}

	void on_draw(const Camera& camera) const
	{
		putimage_alpha(camera, position.x, position.y, atlas->get_image(idx_frame));
	}
private: 
	int timer = 0;
	int idx_frame = 0;
	int lifespan = 0; // ��֡���Ӷ�������ʱ��
	Vector2 position;
	bool valid = true;
	Atlas* atlas = nullptr; // ���Ӷ���ͼ��
};