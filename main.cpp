#include<iostream>
using namespace std;
#include"Control.h"
int main()
{
	Res::CreateRes();				//����������Դ
	initgraph(Res::getWidth(), Res::getHeight(),1);
	
	Role*role= new Role(100);
	Map map;
	Control *pcmd = new Control(role);

	BeginBatchDraw();
	while (true)
	{
		cleardevice();
		map.mapDraw();
		role->drawImg();
		pcmd->RoleControl(5);
		pcmd->EnemyAuto();


		FlushBatchDraw();		
	}
	EndBatchDraw();
	
	getchar();
	return 0;
}