#include "EnemyPlance.h"

EnemyPlance::EnemyPlance():
	AirPlance(Point(Res::getWidth() / 2,Res::getHeight() - Res::instance->m_roleImg[0][0].getheight()),3)
{
}

EnemyPlance::EnemyPlance(Point pos,int hp):AirPlance(pos,hp)
{
}
void EnemyPlance::drawImg()
{
	putimage(pos.m_x, pos.m_y, &Res::instance->m_enemyImg[0][0], NOTSRCERASE);
	putimage(pos.m_x, pos.m_y, &Res::instance->m_enemyImg[0][1], SRCINVERT);
}
int EnemyPlance::getW()
{
	return Res::instance->m_enemyImg[0][0].getwidth();
}
int EnemyPlance::getH()
{
	return Res::instance->m_enemyImg[0][0].getheight();
}

EnemyPlance::~EnemyPlance()
{
	//delete[] m_bull;
}
