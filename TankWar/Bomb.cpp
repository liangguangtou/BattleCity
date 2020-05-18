#include "Bomb.h"
#include <ctime>
Bomb::Bomb()
{
    this->m_Disappear = false;
    this->m_dir = UP;
}

Bomb::Bomb(Point pos, BombType type) : Bomb()
{
    this->m_pos = pos;
    this->m_type = type;
    //bombͼ�����ڱ�ը���Ӿ�Ч��
    switch (m_type)
    {
    case L:
        loadimage(&bomb, L"..\\img\\Bomb\\bomb_S.gif",20,20);
        break;
    case M:
        loadimage(&bomb, L"..\\img\\Bomb\\bomb_M.gif",25,25);
        break;
    case S:
        loadimage(&bomb, L"..\\img\\Bomb\\bomb_L.gif",30,30);
    default:
        break;
    }
}

void Bomb::Display()
{

    putimage(m_pos.GetX(), m_pos.GetY(), &bomb);
    //fillcircle(m_pos.GetX(), m_pos.GetY(), 8 - m_timer);
}

void Bomb::Move()
{
    //��ը����ʧ  
    /*int s = 5;
    while (s != 0) {
        time_t t = time(NULL);//ȡ�õ�ǰʱ��
        while (time(NULL) == t);
        s--;
    }*/
    m_Disappear = true;
}

bool Bomb::IsDisappear()
{
    return m_Disappear;
}

void Bomb::Boom(list<Bomb*>& Bombs)
{
    // Do nothing
}

void Bomb::CalculateSphere()
{
    // Do nothing
}