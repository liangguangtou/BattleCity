#ifndef __MAIN_TANK__
#define __MAIN_TANK__

#include "Tank.h"

class MainTank : public Tank
{
public:
    MainTank():Tank()
    {
        m_pos.Set(300, 300);
        this->CalculateSphere();
        m_dir = Dir::UP;
        m_step = 4;

    }

    ~MainTank() {}

    // ������ʻ����
    void SetDir(Dir dir);
    void Display();
    void Move();
    void Shoot(list<Object*>& Bullets);
protected:
    //̹����ռ�������
    void CalculateSphere();
    // ����̹������
    void DrawTankBody();
};

#endif