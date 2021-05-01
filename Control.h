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
	//定时器
	bool Timer(clock_t ms, int id);
	//产生敌机
	void CreateEnemy();
	void EnemyMove( int speed);
	void DrawEnemy();
	void EnemyAuto();
	//玩家控制
	void RoleControl(int speed);		//玩家移动和子弹发射
	void CreateBullet();				//产生子弹
	void BulletMove(int speed);			//移动子弹
	//碰撞检测
	void PlayEnemy();
public:
	bool collision(AirPlance* dest, Bullet* src);
	bool collision(AirPlance* dest, AirPlance* src);
private:
	Role* m_role;			//玩家

	std::list<EnemyPlance> m_enemy;

};

