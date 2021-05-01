#pragma once
#include "AirPlance.h"
/*玩家飞机类*/
class Role :
	public AirPlance
{
public:
	Role(int hp = 0);
	~Role();
	virtual void drawImg();		//绘制图片
	virtual int getW();
	virtual int getH();
	deque<Bullet>& getBull()
	{
		return m_bull;
	}	
private:
};

