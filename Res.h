#ifndef _RES_H_
#define _RES_H_
#include"Geometry.h"
#include<time.h>
#include<graphics.h>
#include<string>
#include<deque>
#include<iostream>
using std::string;
/*------ȡ��UNICODE�ַ���-------*/
#ifdef UNICODE
#undef UNICODE
#endif
/*------ȡ��UNICODE�ַ���-------*/

/*��Դ��*/
class Res
{
	Res(string BkImg,string(*rolePath)[2], int roleNum, string(*bullpaht)[2], int bullNum, string(*m_enemyPath)[2] = NULL, int enemyNum = 0);
public:
	~Res();
	static Res* CreateRes();
	//��ȡ���ڿ��
	int getWindWidth()
	{
		return m_bkImg->getwidth();
	}
	//��ȡ���ڸ߶�
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
	//�ӵ���Դ
	int		m_bullNum;
	IMAGE	(*m_bullImg)[2];
	//��ͼ��Դ
	IMAGE *m_bkImg;	//����ͼƬ
	//�����Դ
	int		m_roleNum;
	IMAGE	(*m_roleImg)[2];
	//�л���Դ
	int		m_enemyNum;
	IMAGE	(*m_enemyImg)[2];

	static Res * instance;
};


#endif // !_RES_H_



