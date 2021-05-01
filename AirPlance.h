#pragma once
#include"Map.h"
#include"Bullet.h"
#include"Res.h"
using std::deque;
/*所有飞机基类*/
class AirPlance
{
public:
	AirPlance();
	AirPlance(Point pos, int hp) :pos(pos), m_live(true), m_hp(hp) {};
	virtual ~AirPlance();

	virtual void drawImg() = 0;			//绘制图片
	virtual int getW() = 0;
	virtual int getH() = 0;
	int& getHp();		//设置血量
	bool& getLive();	//设置存活状态



protected:
	bool	m_live;			//是否存活  true flase
	int		m_hp;			//血量

	deque<Bullet> m_bull;	//子弹数组
public:
	Size size;			//大小
	Point pos;			//坐标
};

