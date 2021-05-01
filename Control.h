#pragma once
#include"Res.h"
#include"Map.h"
#include"Role.h"
#include"Bullet.h"
#include"EnemyPlance.h"
#include<list>
class Control
{
public:
	Control(Role* role);
	~Control();
	//��ʱ��
	bool Timer(clock_t ms, int id);
	//�����л�
	void CreateEnemy();
	void EnemyMove( int speed);
	void DrawEnemy();
	void EnemyAuto();
	//��ҿ���
	void RoleControl(int speed);		//����ƶ����ӵ�����
	void CreateBullet();				//�����ӵ�
	void BulletMove(int speed);			//�ƶ��ӵ�
	//��ײ���
	void PlayEnemy();
public:
	bool collision(AirPlance* dest, Bullet* src);
	bool collision(AirPlance* dest, AirPlance* src);
private:
	Role* m_role;			//���

	std::list<EnemyPlance> m_enemy;

};

