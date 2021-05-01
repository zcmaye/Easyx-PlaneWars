#include "Map.h"


Map::Map()
{
	m_pres = Res::CreateRes();
}
Map::~Map()
{
	m_pres = nullptr;
}
void Map::mapDraw()
{
	putimage(0, 0, m_pres->m_bkImg);
}
