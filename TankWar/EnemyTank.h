#pragma once
#ifndef __ENEMY_TANK__
#define __ENEMY_TANK__

#define MAX_STEP 10
#include "Tank.h"

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
protected:
    void CalculateSphere();
    void RandomTank();
    // �������̹�˷��� type�� 1, �·��������֮ǰ����ͬ 2, ����һ���·���
    void RandomDir(int type);
    int m_stepCnt;//����¼̹�˵�ǰ��ʻ�Ĳ���
};

#endif