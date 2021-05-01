#include "Res.h"

Res* Res::instance = nullptr;//分文件写静态变量时，必须写在源文件中
Res::Res(string BkImg,
	string(*rolePath)[2],int roleNum, 
	string(*bullpath)[2],int bullNum, 
	string(*enemyPath)[2],int enemyNum)
{
	//地图
	this->m_bkImg = new IMAGE;
	loadimage(m_bkImg, BkImg.data());
	//玩家
	this->m_roleNum = roleNum;
	this->m_roleImg = new IMAGE[m_roleNum][2];
	for (int i = 0; i < m_roleNum; i++)
	{
		loadimage(&m_roleImg[i][0], rolePath[i][0].data());
		loadimage(&m_roleImg[i][1], rolePath[i][1].data());
	}
	//敌机
	this->m_enemyNum = enemyNum;
	this->m_enemyImg = new IMAGE[enemyNum][2];
	for (int i = 0; i < m_enemyNum; i++)
	{
		loadimage(&m_enemyImg[i][0], enemyPath[i][0].data());
		loadimage(&m_enemyImg[i][1], enemyPath[i][1].data());
	}
	//子弹
	this->m_bullNum = bullNum;
	this->m_bullImg = new IMAGE[bullNum][2];
	for (int i = 0; i < bullNum; i++)
	{
		loadimage(&m_bullImg[i][0], bullpath[i][0].data());
		loadimage(&m_bullImg[i][1], bullpath[i][1].data());
	}

}
Res* Res::CreateRes()
{
	string bkImg = "./images/background.jpg";
	string roleImg[][2] = { "./images/planeNormal_1.jpg","./images/planeNormal_2.jpg" ,
				"./images/planeExplode_1.jpg" ,"./images/planeExplode_2.jpg" };
	string bullImg[][2] = { "./images/bullet1.jpg","./images/bullet2.jpg" };
	string enemyImg[][2] = { "./images/enemy_1.jpg","./images/enemy_2.jpg" ,
				"./images/enemyPlane1.jpg" ,"./images/enemyPlane2.jpg" };
	if (instance == nullptr)
	{
		instance = new Res(bkImg, roleImg, 2, bullImg, 1, enemyImg, 2);
	}
	return 	instance;
}

Res::~Res()
{
	delete m_bkImg;
	delete[] m_roleImg;
	delete[] m_enemyImg;
	delete[] m_bullImg;
}
