#include "pch.h"
#include "uiStartTimer.h"

void uiStartTimer::Init()
{
	TextGo::Init();
	Set(RES_MGR_FONT.Get(""), "", 100, sf::Color::Black);
	text.setOutlineThickness(10.f);
	text.setOutlineColor(sf::Color::White);


	Reset();
}

void uiStartTimer::Update(float dt)
{
	TextGo::Update(dt);
	timer -= dt;
	ceilSecond = ceil(timer);
	SetString(std::to_string(ceilSecond));

	if (timer <= 0.f)
		SetActive(false);

}

void uiStartTimer::Draw(sf::RenderWindow& window)
{
	TextGo::Draw(window);

}

void uiStartTimer::Reset()
{
	timer = duration;
	ceilSecond = ceil(timer);
	SetString(std::to_string(ceilSecond));
}
