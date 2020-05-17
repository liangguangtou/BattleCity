#pragma warning(disable:4996)

#include <iostream>
#include <conio.h>
#include <time.h>

#include <list>

#include "Graphic.h"
#include "MainTank.h"
#include "EnemyTank.h"
#include "EnemyTank.cpp"
#include "Bullet.h"

#define MAX_ENEMYTANKS 5

using namespace std;
IMAGE img;


int main()
{
	Graphic::Create();
	//MAGE img;
	loadimage(&img, L"..\\img\\author.png", 200, 100);
	putimage(200, 300, &img);
	_getch();
	IMAGE img2;
	loadimage(&img2, L"..\\img\\startimg.png",1024,768);
	putimage(0,0, &img2);
	char m;
	m = getchar();
	while (m != 'f' && m != 'F')
		m = getchar();

	//Tank* eTank[MAX_ENEMYTANKS];
	//��list ����EenmyTankʵ��
	list<EnemyTank*> lstTanks;
	lstTanks.clear();

	for (int i = 0; i < MAX_ENEMYTANKS; i++)
	{
		lstTanks.push_back(new EnemyTank()); //���һ����̹��
	}
	//�ӵ���ʵ�֣�
	list<Object*> Bullets;
	Bullets.clear();
    
	MainTank mainTank;
	bool loop = true;
	bool skip = false;
	while (loop)
	{
		if (kbhit())
		{
			int key = getch();
			switch (key)
			{
				// Up
			case 72:
				mainTank.SetDir(Dir::UP);
				break;
				// Down
			case 80:
				mainTank.SetDir(Dir::DOWN);
				break;
				// Left
			case 75:
				mainTank.SetDir(Dir::LEFT);
				break;
				// Right
			case 77:
				mainTank.SetDir(Dir::RIGHT);
				break;
			case 224: // �������8λ
				break;
				// Esc �˳�
			case 27:
				loop = false;
				break;
				// 32�ǿո�Space �ƻ������ӵ�
			case 32:
				mainTank.Shoot(Bullets);
				break;
				// 13��Enter Enter��ͣ
			case 13:
				if (skip)
					skip = false;
				else
					skip = true;
				break;
			default:
				break;
			}
		}

		if (!skip)
		{
			cleardevice();
			Graphic::DrawBattleGround();
			mainTank.Move();
			mainTank.Display();

			//��ʼ��һ��Tank������������ʵ��ÿһ��̹�˵�Move��Display
			for (list<EnemyTank*>::iterator it = lstTanks.begin(); it != lstTanks.end(); it++)
			{
				(*it)->Move();
				(*it)->Display();
			}
			//��ʼ��һ��Bullets������������ʵ���ӵ��ķ���
			for (list<Object*>::iterator it = Bullets.begin(); it != Bullets.end();)
			{
				(*it)->Move();

				if ((*it)->IsDisapear())
				{

					delete* it;
					it = Bullets.erase(it);
					continue;
				}

				(*it)->Display();
				it++;
			}
		}
		Sleep(200);
	}
	//�˳�֮ǰ����ɾ���ĺ�ϰ��
	//for (int i = 0; i < MAX_ENEMYTANKS; i++)
	//{
	//	delete eTank[i];
	//}
	for (list<EnemyTank*>::iterator it = lstTanks.begin(); it != lstTanks.end(); it++)
	{
		delete* it;
	}
	lstTanks.clear();

	for (list<Object*>::iterator it = Bullets.begin(); it != Bullets.end(); it++)
	{
		delete* it;
	}
	Bullets.clear();
	Graphic::Destroy();
} 
