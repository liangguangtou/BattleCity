#pragma once

#ifndef __SHAPE_H__
#define __SHAPE_H__

#include "../Model/Rect.h"

class Shape
{
public:
    //���ж�һ�����Ƿ���һ�����εķ�Χ�ڡ�
    //CheckInterSect���������ж����������Ƿ��غϡ�
    static bool CheckPointInRect(Point point, Rect rect);
    static bool CheckIntersect(Rect rectA,Rect rectB);
};

#endif