#include "pch.h"
#include "Title.h"
#include "SpriteGo.h"

Title::Title(SceneIds id) : Scene(id)
{
}

void Title::Init()
{
	
	RES_MGR_TEXTURE.Load("graphics/background.png");
	RES_MGR_FONT.Load("fonts/KOMIKAP_.ttf");

	//��� ����ϱ�
	SpriteGo* background = new SpriteGo("BG");
	background->SetTexture(RES_MGR_TEXTURE.Get("graphics/background.png"));
	background->SetPosition({ 0.f, 0.f });

	//���� Ÿ��Ʋ ����ϱ�
	Titletext = new TextGo("Titletext");
	Titletext->Set(RES_MGR_FONT.Get("fonts/KOMIKAP_.ttf"), "TIMBERAND", 300, sf::Color::Green);
	Titletext->SetOrigin(Origins::TC);
	Titletext->SetPosition({ 1920.f / 2, 100.f });

	//���� ���� ���� ����ϱ�
	textcomt = new TextGo("textcomt");
	textcomt->Set(RES_MGR_FONT.Get("fonts/KOMIKAP_.ttf"), "PRESS TO START", 75, sf::Color::White);
	textcomt->SetOrigin(Origins::MC);
	textcomt->SetPosition({ 1920.f / 2, 700.f });

	//texResMgr.Load("graphics/background.png");
	//fontResMgr.Load("fonts/KOMIKAP_.ttf");

	//SpriteGo* background = new SpriteGo("BG");
	//background->SetTexture("graphics/background.png");
	//background->SetPosition({ 0.f, 0.f });

	//Titletext = new TextGo("Titletext");
	//Titletext->Set(fontResMgr.Get("fonts/KOMIKAP_.ttf"), "TIMBERAND", 300, sf::Color::Green);
	//Titletext->SetOrigin(Origins::TC);
	//Titletext->SetPosition({ 1920.f / 2, 100.f });

	//textcomt = new TextGo("textcomt");
	//textcomt->Set(fontResMgr.Get("fonts/KOMIKAP_.ttf"), "PRESS TO START", 75, sf::Color::White);
	//textcomt->SetOrigin(Origins::MC);
	//textcomt->SetPosition({ 1920.f / 2, 700.f });


	
	AddGo(background);
	AddGo(Titletext);
	AddGo(textcomt);

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
	//�ƹ�Ű�� ������ ��� ���� �޴� ���þ����� �Ѿ��.
	if (InputMgr::AnyKeyDown())
	{
		SCENE_MGR.ChangeScene(SceneIds::SCENE_MENU);
	}

	//if (InputMgr::GetKeyDown(sf::Keyboard::Escape)
	//{
	// 
	//}
}
