#pragma once
#include"Res.h"
using std::string;
/*地图类，用来绘制背景图*/
class Map
{
public:
	Map();
	~Map();
	void mapDraw();
private:
	Res *m_pres;
};

