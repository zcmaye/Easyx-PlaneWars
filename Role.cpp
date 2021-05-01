#include "Role.h"
Role::Role(int hp ) :
	AirPlance(Point(Res::getWidth() / 2, 
		Res::getHeight() - Res::instance->m_roleImg[0][0].getheight()),hp)
{
}

Role::~Role()
{
	//delete[] m_bull;
}
void Role::drawImg()
{
	if (this->m_live)
	{
		putimage(pos.m_x, pos.m_y, &Res::instance->m_roleImg[0][0], NOTSRCERASE);
		putimage(pos.m_x, pos.m_y, &Res::instance->m_roleImg[0][1], SRCINVERT);
	}
}
int Role::getW()
{
	return Res::instance->m_roleImg[0][0].getwidth();
}
int Role::getH()
{
	return Res::instance->m_roleImg[0][0].getheight();
}