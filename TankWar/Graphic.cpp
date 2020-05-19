
#include "Graphic.h"
#include "Model/Rect.cpp"
#include "Setting.cpp"
#include "Setting.h"
Rect Graphic::m_rectScreen;
Rect Graphic::m_rectBattleGround;
char Graphic::m_pArray[100];

void Graphic::Create()
{
	m_rectScreen.Set(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	setbkcolor(BLACK);

	m_rectBattleGround.Set(BATTLE_GROUND_X1, BATTLE_GROUND_Y1, BATTLE_GROUND_X2, BATTLE_GROUND_Y2);
}

void Graphic::Destroy()
{
	closegraph();
}

void Graphic::DrawBattleGround()
{
	rectangle(BATTLE_GROUND_X1, BATTLE_GROUND_Y1, BATTLE_GROUND_X2, BATTLE_GROUND_Y2);
}

int Graphic::GetScreenWidth()
{
	return SCREEN_WIDTH;
}

int Graphic::GetScreenHeight()
{
	return SCREEN_HEIGHT;
}

Rect Graphic::GetBattleGround()
{
	return m_rectBattleGround;
}



const int SCORE_LEFT = 810;
const int SCORE_TOP = 5;


// DT_CENTER : 居中
// DT_VCENTER:垂直居中
// DT_SINGLELINE:单行显示
void Graphic::ShowScore()
{
    COLORREF fill_color_save = getfillcolor();
    COLORREF color_save = getcolor();


    rectangle(SCORE_LEFT, SCORE_TOP, SCORE_LEFT + 200, SCORE_TOP + 40);


    RECT r = { SCORE_LEFT, SCORE_TOP, SCORE_LEFT + 200, SCORE_TOP + 40 };
    wsprintf((LPWSTR)m_pArray, _T("第 %d 关"), Setting::GetGameLevel());
    drawtext((LPWSTR)m_pArray, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

    r.top += 50;
    r.bottom += 50;
    wsprintf((LPWSTR)m_pArray, _T("分  数  :  %d"), Setting::GetSumScore());
    drawtext((LPWSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

    r.top += 50;
    r.bottom += 50;
    wsprintf((LPWSTR)m_pArray, _T("级  别  :  %d"), Setting::GetTankLevel());
    drawtext((LPWSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);   

    r.top += 50;
    r.bottom += 50;
    wsprintf((LPWSTR)m_pArray, _T("生  命  :  %d"), Setting::GetLife());
    drawtext((LPWSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

    r.top += 50;
    r.bottom += 50;
    wsprintf((LPWSTR)m_pArray, _T("敌人数  :  %d"), Setting::GetTankNum());
    drawtext((LPWSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);

    r.top += 50;
    r.bottom += 50;

    line(SCORE_LEFT, r.bottom, SCREEN_WIDTH - 5, r.bottom);

    r.top += 50;
    r.bottom += 50;
    wsprintf((LPWSTR)m_pArray, _T("Author: Rave1sking"));
    drawtext((LPWSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);
    r.top += 50;
    r.bottom += 50;
    wsprintf((LPWSTR)m_pArray, _T("共击毁敌人数  :  %d"), Setting::GetTankSum());
    drawtext((LPWSTR)m_pArray, &r, DT_VCENTER | DT_SINGLELINE);


    setcolor(color_save);
    setfillcolor(fill_color_save);
    //从上到下依次显示
}