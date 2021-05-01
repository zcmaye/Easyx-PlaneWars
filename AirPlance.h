#pragma once
#include"Map.h"
#include"Bullet.h"
#include"Res.h"
using std::deque;
/*���зɻ�����*/
class AirPlance
{
public:
	AirPlance();
	AirPlance(Point pos, int hp) :pos(pos), m_live(true), m_hp(hp) {};
	virtual ~AirPlance();

	virtual void drawImg() = 0;			//����ͼƬ
	virtual int getW() = 0;
	virtual int getH() = 0;
	int& getHp();		//����Ѫ��
	bool& getLive();	//���ô��״̬



protected:
	bool	m_live;			//�Ƿ���  true flase
	int		m_hp;			//Ѫ��

	deque<Bullet> m_bull;	//�ӵ�����
public:
	Size size;			//��С
	Point pos;			//����
};

