#ifndef _PLATFORM_H_
#define _PLATFORM_H_

#include "util.h"
#include "camera.h"

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
	}
private:

};
#endif // !_PLATFORM_H_
