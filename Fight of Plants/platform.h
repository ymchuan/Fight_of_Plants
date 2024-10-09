#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include "util.h"
#include "camera.h"

extern bool is_debug;

class Platform
{
public:
	struct Collision_shape
	{
		float y;
		float left, right;
	};
public:
	Collision_shape shape;
	IMAGE* img = nullptr;
	POINT render_position = { 0 };

public:
	Platform() = default;
	~Platform() = default;

	void on_draw(const Camera& camera) const
	{
		putimage_alpha(camera, render_position.x, render_position.y, img);

		if (is_debug)
		{
			setlinecolor(RGB(255, 0, 0));
			line(camera, (int)shape.left, (int)shape.y, (int)shape.right, (int)shape.y);
			

		}
	}
private:

};
#endif // !_PLATFORM_H_
