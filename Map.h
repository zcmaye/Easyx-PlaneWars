#pragma once
#include"Res.h"
using std::string;
/*��ͼ�࣬�������Ʊ���ͼ*/
class Map
{
public:
	Map();
	~Map();
	void mapDraw();
private:
	Res *m_pres;
};

