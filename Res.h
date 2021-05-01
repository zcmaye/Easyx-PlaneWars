#ifndef _RES_H_
#define _RES_H_
#include"Geometry.h"
#include<time.h>
#include<graphics.h>
#include<string>
#include<deque>
#include<iostream>
using std::string;
/*------取消UNICODE字符集-------*/
#ifdef UNICODE
#undef UNICODE
#endif
/*------取消UNICODE字符集-------*/

/*资源类*/
class Res
{
	Res(string BkImg,string(*rolePath)[2], int roleNum, string(*bullpaht)[2], int bullNum, string(*m_enemyPath)[2] = NULL, int enemyNum = 0);
public:
	~Res();
	static Res* CreateRes();
	//获取窗口宽度
	int getWindWidth()
	{
		return m_bkImg->getwidth();
	}
	//获取窗口高度
	int getWindHeight()
	{
		return m_bkImg->getheight();
	}
	static int getWidth()
	{
		return instance->getWindWidth();
	}
	static int getHeight()
	{
		return instance->getWindHeight();
	}

public:
	//子弹资源
	int		m_bullNum;
	IMAGE	(*m_bullImg)[2];
	//地图资源
	IMAGE *m_bkImg;	//背景图片
	//玩家资源
	int		m_roleNum;
	IMAGE	(*m_roleImg)[2];
	//敌机资源
	int		m_enemyNum;
	IMAGE	(*m_enemyImg)[2];

	static Res * instance;
};


#endif // !_RES_H_



