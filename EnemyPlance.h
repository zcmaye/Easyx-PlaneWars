#pragma once
#include "AirPlance.h"
#include"Res.h"
/*�л���*/
class EnemyPlance :
	public AirPlance
{
public:
	EnemyPlance();
	EnemyPlance(Point pos,int hp=1);
	~EnemyPlance();
	virtual void drawImg();				//����ͼƬ
	virtual int getW();
	virtual int getH();
private:
};

