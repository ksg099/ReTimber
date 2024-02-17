#include "pch.h"
#include "Title.h"

Title::Title(SceneIds id) : Scene(id)
{
}

void Title::Init()
{
	texResMgr.Load("graphics/background.png");
	text.SetString("PRESS TO START");

	title* = new SpriteGo("BG");

	AddGo(title)

}

void Title::Release()
{
}

void Title::Enter()
{
}

void Title::Exit()
{
}

void Title::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Unknown))
	{
		SCENE_MGR.ChangeScene(SceneIds::SCENE_MOD);
	}
}
