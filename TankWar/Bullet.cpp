#include "Bullet.h"

Bullet::Bullet() {}

Bullet::Bullet(Point pos, Dir dir)
{
	m_pos = pos;
	m_dir = dir;
	m_step = 20;
    m_Disapear = false;
    
	CalculateSphere();
}

Bullet::~Bullet(){}


void Bullet::Display()
{
	IMAGE bullets;
	loadimage(&bullets, L"..\\img\\bullet.gif",6,6);
	putimage(m_pos.GetX() - 1, m_pos.GetY() - 1,&bullets);
    
}


void Bullet::Move()
{
    switch (m_dir)
    {
    case UP:
        m_pos.SetY(m_pos.GetY() - m_step);
        CalculateSphere();
        if (m_rectSphere.GetStartPoint().GetY() < Graphic::GetBattleGround().GetStartPoint().GetY())
        {
            m_Disapear = true;
        }
        break;
    case DOWN:
        m_pos.SetY(m_pos.GetY() + m_step);
        CalculateSphere();
        if (m_rectSphere.GetEndPoint().GetY() > Graphic::GetBattleGround().GetEndPoint().GetY())
        {
            m_Disapear = true;
        }
        break;
    case LEFT:
        m_pos.SetX(m_pos.GetX() - m_step);
        CalculateSphere();
        if (m_rectSphere.GetStartPoint().GetX() < Graphic::GetBattleGround().GetStartPoint().GetX())
        {
            m_Disapear = true;
        }
        break;
    case RIGHT:
        m_pos.SetX(m_pos.GetX() + m_step);
        CalculateSphere();
        if (m_rectSphere.GetEndPoint().GetX() > Graphic::GetBattleGround().GetEndPoint().GetX())
        {
            m_Disapear = true;
        }
        break;
    default:
        break;
    }
}

void Bullet::CalculateSphere()
{
    m_rectSphere.Set(m_pos.GetX() - 2, m_pos.GetY() - 2, m_pos.GetX() + 2, m_pos.GetY() + 2);
}