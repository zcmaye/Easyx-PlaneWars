#include "AirPlance.h"



AirPlance::AirPlance()
{
	//�����಻��Ҫ��ʼ�������Գ�ʼ�����������
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

