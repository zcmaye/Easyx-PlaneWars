#pragma once
#include "AirPlance.h"
/*��ҷɻ���*/
class Role :
	public AirPlance
{
public:
	Role(int hp = 0);
	~Role();
	virtual void drawImg();		//����ͼƬ
	virtual int getW();
	virtual int getH();
	deque<Bullet>& getBull()
	{
		return m_bull;
	}	
private:
};

