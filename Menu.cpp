#include "pch.h"
#include "Menu.h"

Menu::Menu(SceneIds id) : Scene(id)
{
}

void Menu::Init()
{
	texResMgr.Load("graphics/background.png");
	text.SetPosition({ 1000.f, 1000.f });
	text.Set(RES_MGR_FONT.Get("fonts/KOMIKAP_.ttf"), "Single Play", 100, sf::Color::Red);
	text.SetPosition({ 1000.f, 1000.f });
	text.Set(RES_MGR_FONT.Get("fonts/KOMIKAP_.ttf"), "Multi Play", 100, sf::Color::Red);

	AddGo(&text);
}

void Menu::Release()
{
}

void Menu::Enter()
{
}

void Menu::Exit()
{
}

void Menu::Update(float dt)
{
	//if (InputMgr::GetKeyDown(sf::Keyboard::Num1))
	//{
	//	SceneMgr::ChangeScene(SceneIds::1��~~);
	//	text.SetString("You Choice Single Play"); 
	//}
	//if (InputMgr::GetKeyDown(sf::Keyboard::Num2))
	//{
	//	SceneMgr::ChangeScene(SceneIds::2��~~);
	//	text.SetString("You Choice Multi Play"); 
	//}
}

