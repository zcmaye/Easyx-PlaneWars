#pragma once
#include"Map.h"
#include"Res.h"
/*�ӵ���*/
class Bullet
{
public:
	Bullet(Point pos);
	~Bullet();
	void draw();
public:
	Point pos;
};

