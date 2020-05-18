#pragma warning(disable:4996)

#include <iostream>
#include <conio.h>
#include <time.h>
#include <list>
#include <stdlib.h>


#include "Graphic.h"
#include "MainTank.h"
#include "EnemyTank.h"
#include "EnemyTank.cpp"
#include "Bullet.cpp"
#include "Bomb.h"
#include "Bomb.cpp"
//#include "Utils/Shape.h"
#include "Utils/Shape.cpp"

#define MAX_ENEMYTANKS 5

using namespace std;
IMAGE img;

list<EnemyTank*> lstTanks;
list<Bullet*> MainBullets;
void CheckCrash()
{
	for (list<Bullet*>::iterator it = MainBullets.begin(); it != MainBullets.end(); it++)
	{
		for (list<EnemyTank*>::iterator itt = lstTanks.begin(); itt != lstTanks.end(); itt++)
		{
			Rect a = (*it)->GetSphere(); 
			Rect b = (*itt)->GetSphere();
			if (Shape::CheckIntersect(a, b))
			{
				(*itt)->SetDisappear();
				(*it)->SetDisappear();
			}
		}
	}
}
int main()
{
	Graphic::Create();
	/*loadimage(&img, L"..\\img\\author.png", 200, 100);
	putimage(200, 300, &img);
	_getch();
	IMAGE img2;
	loadimage(&img2, L"..\\img\\startimg.png",1024,768);
	putimage(0,0, &img2);
	char m;
	m = getchar();
	while (m != 'f' && m != 'F')
		m = getchar();
	*/
	//Tank* eTank[MAX_ENEMYTANKS];
	//��list ����EenmyTankʵ��
	lstTanks.clear();

	for (int i = 0; i <= MAX_ENEMYTANKS; i++)
	{
		lstTanks.push_back(new EnemyTank()); //���һ����̹��
	}
	//�ӵ���ʵ�֣�
    //��̹���ӵ�
	MainBullets.clear();
    
	//��ը��ʵ��
	list<Bomb*> Bombs;
	Bombs.clear();


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
				mainTank.Shoot(MainBullets);
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
			CheckCrash();
			Graphic::DrawBattleGround();
			mainTank.Move();
			mainTank.Display();
			//��ʼ��һ��Tank������������ʵ��ÿһ���ط�̹�˵�Move��Display
			//list������ end() �������õ�listĩ����һλ��
			//�൱�ڣ�int a[n]�еĵ�n+1��λ��a[n]��ʵ�����ǲ����ڵģ����ܷ��ʡ�
			for (list<EnemyTank*>::iterator it = lstTanks.begin(); it != lstTanks.end(); )
			{
				(*it)->Move();
				if ((*it)->IsDisappear())
				{
					// Add a bomb
					//(*it)->Boom(lstBombs);

					// Delete the tank
					delete* it;
					it = lstTanks.erase(it);
					continue;
				}
				(*it)->Display();
				it++;
			}
			//��ʼ��һ��Bullets������������ʵ���ӵ��ķ���
			for (list<Bullet*>::iterator it = MainBullets.begin(); it != MainBullets.end();)
			{
				(*it)->Move();

				if ((*it)->IsDisappear())
				{
					//�����ʧ�ͱ�ը
					//(*it)->bomb(Bombs);
					delete* it;
					it = MainBullets.erase(it);
					continue;
				}
				(*it)->Display();
				it++; //��Ȼ�����
			}

			// ��ʼ��һ��Bomb������������ʵ�ֱ�ը����ʧ
			/*for (list<Bomb*>::iterator it = Bombs.begin(); it != Bombs.end();)
			{

				(*it)->Move();  //����ӳ٣�

				if ((*it)->IsDisappear())
				{
					delete* it;
					it = Bombs.erase(it);
					continue;
				}

				(*it)->Display();
				it++;
			}*/
		}
		Sleep(200);
	}
	//�˳�֮ǰ����ɾ���ĺ�ϰ��

	//ɾ���з�̹��
	for (list<EnemyTank*>::iterator it = lstTanks.begin(); it != lstTanks.end(); it++)
	{
		delete* it;
	}
	lstTanks.clear();

	//ɾ���ӵ�
	for (list<Bullet*>::iterator it = MainBullets.begin(); it != MainBullets.end(); it++)
	{
		delete* it;
	}
	MainBullets.clear();

	//ɾ����ը
	for (list<Bomb*>::iterator it = Bombs.begin(); it != Bombs.end(); it++)
	{
		delete* it;
	}
	Bombs.clear();


	Graphic::Destroy();
} 
