#include "EnemyTank.h"
#include "Tank.h"

void EnemyTank::RandomTank()
{
    //��������Ļ�Ϸ�:
    m_pos.SetX(rand() % Graphic::GetBattleGround().GetHeight());
    m_pos.SetY(28);
    m_dir = (Dir)(Dir::UP + (rand() % 4)); //���ȷ��̹�˷���
    m_step = 2;

    m_stepCnt = rand() % MAX_STEP;
}

void EnemyTank::Display()
{
    IMAGE EnemyTank;
    switch (m_dir)
    {
    case UP:
        loadimage(&EnemyTank, L"..\\img\\enemytank\\enemyUP.gif",36,36);
        putimage(m_pos.GetX()-18, m_pos.GetY()-18, &EnemyTank);
        break;
    case DOWN:
        loadimage(&EnemyTank, L"..\\img\\enemytank\\enemyDOWN.gif", 36, 36);
        putimage(m_pos.GetX() - 18, m_pos.GetY() - 18, &EnemyTank);
        break;
    case RIGHT:
        loadimage(&EnemyTank, L"..\\img\\enemytank\\enemyRIGHT.gif", 36, 36);
        putimage(m_pos.GetX() - 18, m_pos.GetY() - 18, &EnemyTank);
        break;
    case LEFT:
        loadimage(&EnemyTank, L"..\\img\\enemytank\\enemyLEFT.gif", 36, 36);
        putimage(m_pos.GetX() - 18, m_pos.GetY() - 18, &EnemyTank);
        break;
    }
}

void EnemyTank::RandomDir(int type)
// ����typeΪ1ʱ����һ���͵�ǰ����ͬ���·��򣬲���typeΪ0ʱ����������һ���·���
{
    if (type == 1)
    {
        Dir dir;
        while ((dir = (Dir)(Dir::UP + (rand() % 4))) == m_dir) {} 
        m_dir = dir;
    }
    else
    {
        m_dir = (Dir)(Dir::UP + (rand() % 4));
    }
}
void EnemyTank::Move()
{
    switch (m_dir)
    {
    case UP:
        m_pos.SetY(m_pos.GetY() - m_step); // -2 ȷ��������ײ
        if (m_rectSphere.GetStartPoint().GetY()-2 < Graphic::GetBattleGround().GetStartPoint().GetY())
        {
            m_pos.SetY(m_pos.GetY() + m_step);
            this->RandomDir(1);
        }
        break;
    case DOWN:
        m_pos.SetY(m_pos.GetY() + m_step);
        if (m_rectSphere.GetEndPoint().GetY() +2 > Graphic::GetBattleGround().GetEndPoint().GetY())
        {
            m_pos.SetY(m_pos.GetY() - m_step);
            this->RandomDir(1);
        }
        break;
    case LEFT:
        m_pos.SetX(m_pos.GetX() - m_step);
        if (m_rectSphere.GetStartPoint().GetX() -2 < Graphic::GetBattleGround().GetStartPoint().GetX())
        {
            m_pos.SetX(m_pos.GetX() + m_step);  this->RandomDir(1);
        }
        break;
    case RIGHT:
        m_pos.SetX(m_pos.GetX() + m_step);
        if (m_rectSphere.GetEndPoint().GetX() +2 > Graphic::GetBattleGround().GetEndPoint().GetX())
        {
            m_pos.SetX(m_pos.GetX() - m_step); this->RandomDir(1);
        }
        break;
    default:
        break;
    }

    m_stepCnt++;
    if (m_stepCnt >= MAX_STEP)  //Ҫд>=��Ϊ����һ�����ͻ� m_stepCnt = MAX_STEP
    {
        m_stepCnt = 0;
        this->RandomDir(0);
    }
    CalculateSphere();
}

void EnemyTank::CalculateSphere()
{
    switch (m_dir)
    {
    case UP:
    case DOWN:
        m_rectSphere.Set(m_pos.GetX() - 18, m_pos.GetY() - 18, m_pos.GetX() + 18, m_pos.GetY() + 18);
        break;
    case LEFT:
    case RIGHT:
        m_rectSphere.Set(m_pos.GetX() - 18, m_pos.GetY() - 18, m_pos.GetX() + 18, m_pos.GetY() + 18);
        break;
    default:
        break;
    }
}