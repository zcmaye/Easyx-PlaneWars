#pragma once
#include"Map.h"
#include"Res.h"
/*×Óµ¯Àà*/
class Bullet
{
public:
	Bullet(Point pos);
	~Bullet();
	void draw();
public:
	Point pos;
};

