#include "Bullet.h"


Bullet::Bullet(Point pos):pos(pos)
{
}
void Bullet::draw()
{
	putimage(pos.m_x, pos.m_y, &Res::instance->m_bullImg[0][0], NOTSRCERASE);
	putimage(pos.m_x, pos.m_y, &Res::instance->m_bullImg[0][1], SRCINVERT);
}
Bullet::~Bullet()
{
}
