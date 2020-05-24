#ifndef __MAIN_TANK__
#define __MAIN_TANK__

#include "Tank.h"
#include "Bullet.h"

class MainTank : public Tank
{
public:
    MainTank():Tank()
    {
        m_pos.Set(300, 700);
        this->CalculateSphere();
        m_dir = Dir::UP;
        m_step = 6;

    }

    ~MainTank() {}

    // ������ʻ����
    void SetDir(Dir dir);
    void Display();
    void Move();
    void Shoot(list<Bullet*>& Bullets);
    Rect GetSphere()
    {
        return m_rectSphere;
    }
    IMAGE maintankUP;
    IMAGE maintankDOWN;
    IMAGE maintankLEFT;
    IMAGE maintankRIGHT;
    void InitMainTankImage();
protected:
    //̹����ռ�������
    void CalculateSphere();
    // ����̹������
    void DrawTankBody();
};

#endif