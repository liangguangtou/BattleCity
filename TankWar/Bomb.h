#ifndef __BOMB_H__
#define __BOMB_H__
#include "Graphic.h"
#include <list>

using namespace std;

enum BombType
{
    L, //��ű�ը�����ڴݻ�̹��
    M, //�кű�ը�����ڴݻ�ǽ��
    S  //С�ű�ը�����ڴ������
}; 

class Bomb
{
public:
    Bomb();
    Bomb(Point pos, BombType type);
    ~Bomb() {}

    void Display();

    void Move();

    void Boom (list <Bomb*> & Bombs);

    bool IsDisappear();

protected:
    void CalculateSphere();
    IMAGE bomb;
    BombType m_type;
    bool m_Disappear;
    Dir m_dir;
    Point m_pos;

};

#endif
