#pragma once
#ifndef __ENEMY_TANK__
#define __ENEMY_TANK__

#define MAX_STEP 10
#include "Tank.h"
#include "Bullet.h"
class EnemyTank : public Tank
{
public:
    EnemyTank()
    {
        RandomTank();
    }

    ~EnemyTank() {}

    void Display();
    void Move();
    Rect GetSphere()
    {
        return m_rectSphere;
    }
    void Shoot(list<Bullet*>& eBullets);
    bool NeedShoot();
    void SetPos(Point pos);
    void RandomDir(int type);
    EnemyTank& operator=(const EnemyTank& obj)
    {
        m_dir = obj.m_dir;
        m_pos = obj.m_pos;
        m_step = obj.m_step;
        m_rectSphere = obj.m_rectSphere;
    }
protected:
    void CalculateSphere();
    void RandomTank();
    // �������̹�˷��� type�� 1, �·��������֮ǰ����ͬ else ����һ���·���
    int m_stepCnt;//����¼̹�˵�ǰ��ʻ�Ĳ���
    bool m_NeedShoot = false;
    int MAX_STEP_SHOOT = 20;
};

#endif