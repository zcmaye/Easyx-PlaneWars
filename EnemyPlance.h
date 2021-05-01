#pragma once
#include "AirPlance.h"
#include"Res.h"
/*µ–ª˙¿‡*/
class EnemyPlance :
	public AirPlance
{
public:
	EnemyPlance();
	EnemyPlance(Point pos,int hp=1);
	~EnemyPlance();
	virtual void drawImg();				//ªÊ÷∆Õº∆¨
	virtual int getW();
	virtual int getH();
private:
};

