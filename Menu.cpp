#include "pch.h"
#include "Menu.h"

Menu::Menu(SceneIds id) : Scene(id)
{
}

void Menu::Init()
{
	texResMgr.Load("graphics/background.png");
	text.SetString("Single Play");
	text.SetString("Multi Play");

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
	//	SceneMgr::ChangeScene(SceneIds::1¿Œ~~);
	//	text.SetString("You Choice Single Play"); 
	//}
	//if (InputMgr::GetKeyDown(sf::Keyboard::Num2))
	//{
	//	SceneMgr::ChangeScene(SceneIds::2¿Œ~~);
	//	text.SetString("You Choice Multi Play"); 
	//}
}
