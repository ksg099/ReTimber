#include "pch.h"
#include "Title.h"

Title::Title(SceneIds id) : Scene(id)
{
}

void Title::Init()
{
	texResMgr.Load("graphics/background.png");
	fontResMgr.Load("fonts/KOMIKAP_.ttf");

	text = new TextGo("text");
	//text->SetTexture(texResMgr.Get("graphics/background.png"));
	text->SetOrigin(Origins::MC);
	text->SetPosition({ 1920.f / 2, 500.f });
	text->Set(RES_MGR_FONT.Get("fonts/KOMIKAP_.ttf"),"PRESS TO START", 75, sf::Color::White);
	text->Set(RES_MGR_TEXTURE.Get("graphics/background.png"), "PRESS TO START", 75, sf::Color::White);

	AddGo(text);
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
