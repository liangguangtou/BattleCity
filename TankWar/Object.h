#pragma once
#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Graphic.h"

enum Dir { UP, DOWN, LEFT, RIGHT };

class Object
{
public:
    // ��ͼ
    virtual void Display() =0;

    // �ƶ�
    virtual void Move() =0;

    // �ж��Ƿ���
    virtual bool IsDisapear() =0;

protected:
    // ����������Χ
    //virtual void CalculateSphere() =0;

    // λ��
    Point m_pos;
    // ������Χ
    Rect m_rectSphere;
    // ����
    Dir m_dir;
    // �Ƿ���
    bool m_Disapear;
    // ����ǰ������
    int m_step;
};

#endif