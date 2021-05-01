#include "AirPlance.h"



AirPlance::AirPlance()
{
	//抽象类不需要初始化，所以初始化在子类完成
	m_hp = 0;
	m_live = false;
}
AirPlance:: ~AirPlance()
{

}

int& AirPlance::getHp()
{
	return m_hp;
}

bool& AirPlance::getLive()
{
	return m_live;
}

