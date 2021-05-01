#include "Control.h"

Control::Control(Role* role) :m_role(role)
{
}

//�����л�
void Control::CreateEnemy()
{
	if (Timer(1000, 0))
	{
		Point pos(rand() % (Res::instance->getWindWidth() - 100), 0);
		m_enemy.push_back(EnemyPlance(pos, 3));
		std::cout << "enemy_size:" << m_enemy.size() << std::endl;
	}
}
//�л��ƶ�
void Control::EnemyMove(int speed)
{
	if (Timer(20, 1))
	{
#if 0
		for (int i = 0; i < m_enemyNum; i++)
		{
			if (m_penemy[i].getLive())
			{
				m_penemy[i].getY() += speed;
				if (m_penemy[i].getY() >= Res::instance->getWindHeight())
				{
					m_penemy[i].getLive() = false;
				}
				if ((rand() % 1000) == 1)
				{
					//enemyCreateBullet(enemy[i]);
				}
			}
		}
#else 
		for (auto it = m_enemy.begin(); it!=m_enemy.end();)
		{
			it->pos.move(DIR::DOWN, speed);						//�л��ƶ�
			if (it->pos.m_y >= Res::instance->getWindHeight())
			{
				it = m_enemy.erase(it);
			}
			else
			{
				it++;
			}
		}
#endif
	}
}
void Control::DrawEnemy()
{
	for (auto& val : m_enemy)
	{
		val.drawImg();
	}
}
void Control::EnemyAuto()
{
	this->EnemyMove(2);
	this->CreateEnemy();
	this->DrawEnemy();
	this->PlayEnemy();
}
//��ҿ���
void Control::RoleControl(int speed)
{
	if (Timer(10, 2))
	{
		if (GetAsyncKeyState(VK_UP) && m_role->pos.m_y >= 0)
		{
			m_role->pos.move(DIR::UP, speed);
		}
		if (GetAsyncKeyState(VK_DOWN) && m_role->pos.m_y + 120 <= Res::instance->getWindHeight())
		{
			m_role->pos.move(DIR::DOWN, speed);
		}
		if (GetAsyncKeyState(VK_LEFT) && m_role->pos.m_x + 50 >= 0)
		{
			m_role->pos.move(DIR::LEFT, speed);
		}
		if (GetAsyncKeyState(VK_RIGHT) && m_role->pos.m_x + 55 <= Res::instance->getWindWidth())
		{
			m_role->pos.move(DIR::RIGHT, speed);
		}
	}
	
	//��������ӵ�����ʱ��
	//�����ӵ�
	if (GetAsyncKeyState(VK_SPACE) && Timer(200, 3))
	{
		CreateBullet();
	}
	BulletMove(1);
}
//�ӵ��ƶ�
void Control::BulletMove(int speed)
{
	auto it = m_role->getBull().begin();
	for (it; it != m_role->getBull().end(); )
	{
		it->draw();
		it->pos.move(DIR::UP, speed);
		if (it->pos.m_y < 0)
		{
			it = m_role->getBull().erase(it);
		}
		else
		{
			it++;
		}
	}
}
void Control::CreateBullet()
{
	m_role->getBull().push_back(Bullet(Point(m_role->pos.m_x + 45, m_role->pos.m_y)));
	std::cout <<"bull num:"<< m_role->getBull().size() << std::endl;
}
void Control::PlayEnemy()
{
#if 0
	//1�������л�����  �ж��Ƿ���
	for (int i = 0; i < m_enemyNum; i++)
	{
		if (!m_penemy[i].getLive())
		{
			continue;
		}
		for (auto it = m_role->getBull().begin(); it !=m_role->getBull().end(); )
		{
			if (it->m_x > m_penemy[i].getX() && it->m_x<m_penemy[i].getX() + Res::instance->m_enemyImg[0][0].getwidth()
				&& it->m_y>m_penemy[i].getY() && it->m_y < m_penemy[i].getY() + Res::instance->m_enemyImg[0][0].getheight())
			{
				m_penemy[i].getHp()--;
				it = m_role->getBull().erase(it);//ɾ��Ԫ�ػ�ʹ������ʧЧ������Ҫ������һ��λ�õĵ�����
			}
			else
			{
				it++;
			}
			//�л�����
			if (m_penemy[i].getHp() <= 0)
			{
				m_penemy[i].getLive() = false;
			}
		}
	}
#else
	//1�������л�����  �ж��Ƿ���
	for (auto eit = m_enemy.begin(); eit !=m_enemy.end(); )
	{
		for (auto it = m_role->getBull().begin(); it != m_role->getBull().end(); )
		{
			//��ײ
			if(collision(&*eit,&*it))
			{
				eit->getHp()--;
				it = m_role->getBull().erase(it);//ɾ��Ԫ�ػ�ʹ������ʧЧ������Ҫ������һ��λ�õĵ�����
			}
			else
			{
				it++;
			}
		}
		//�л�����
		if (eit->getHp() <= 0)
		{
			eit = m_enemy.erase(eit);
		}
		else
		{
			eit++;
		}
	}
#endif
}
/// <summary>
/// ��ײ���
/// </summary>
/// <param name="dest">����ײ��(�磺�л�)</param>
/// <param name="src">������ײ(�磺�ӵ�)</param>
/// <returns>������ײ����true</returns>
bool Control::collision(AirPlance* dest, Bullet* src)
{
	if (src->pos.m_x > dest->pos.m_x && src->pos.m_x<dest->pos.m_x + dest->getW() &&
		src->pos.m_y>dest->pos.m_y && src->pos.m_y < dest->pos.m_y + dest->getH())
	{
		return true;
	}
	return false;
}
bool Control::collision(AirPlance* dest, AirPlance* src)
{
	if (src->pos.m_x > dest->pos.m_x && src->pos.m_x<dest->pos.m_x + dest->getW() &&
		src->pos.m_y>dest->pos.m_y && src->pos.m_y < dest->pos.m_y + dest->getH())
	{
		return true;
	}
	return false;
}
Control::~Control()
{
}

bool Control::Timer(clock_t ms, int id)
{
	static clock_t _start[10] = { 0 };
	clock_t end = clock();
	if (end - _start[id] > ms)
	{
		_start[id] = end;
		return true;
	}
	return false;
}
