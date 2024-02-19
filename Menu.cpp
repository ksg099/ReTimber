#include "pch.h"
#include "Menu.h"
#include "TextGo.h"
#include "SpriteGo.h"

Menu::Menu(SceneIds id) : Scene(id)
{
}

void Menu::Init()
{

	RES_MGR_TEXTURE.Load("graphics/background.png");
	RES_MGR_FONT.Load("graphics/background.png");


	//��� ����ϱ�
	SpriteGo* background = new SpriteGo("BG");
	background->SetPosition({0.f, 0.f});
	background->SetTexture("graphics/background.png");


	//1�� �������� ���� ���
	Single = new TextGo("text");
	Single->Set(RES_MGR_FONT.Get("fonts/KOMIKAP_.ttf"), "Single Play to PRESS 1", 75, sf::Color::Red);
	Single->SetPosition({ 1920.f / 2, 400.f });
	Single->SetOrigin(Origins::MC);

	//2�� �������� ���� ���
	Multi = new TextGo("text");
	Multi->Set(RES_MGR_FONT.Get("fonts/KOMIKAP_.ttf"), "Multi Play to PRESS 2", 75, sf::Color::Blue);
	Multi->SetPosition({ 1920.f / 2, 600.f });
	Multi->SetOrigin(Origins::MC);

	AddGo(background);
	AddGo(Single);
	AddGo(Multi);

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

void Menu::Update(float dt) //�ʱ���½�
{
    // ���� ȭ��ǥ Ű�� ������ ��
    if (InputMgr::GetKeyDown(sf::Keyboard::Up))
    {
        // �÷��̾� ��带 Single�� ����
        SCENE_MGR.playMode = GameMode::Single;
    }

    // �Ʒ��� ȭ��ǥ Ű�� ������ ��
    if (InputMgr::GetKeyDown(sf::Keyboard::Down))
    {
        // �÷��̾� ��带 Multi�� ����
        SCENE_MGR.playMode = GameMode::Multi;
    }

    // Enter Ű�� ������ �� ���� ������ �Ѿ
    if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
    {
        SCENE_MGR.ChangeScene(SceneIds::SCENE_CHARACTER);
    }

    // Escape Ű�� ������ �� Ÿ��Ʋ ������ ���ư�
    if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
    {
        SCENE_MGR.ChangeScene(SceneIds::SCENE_TITLE);
    }

    // �÷��̾� ��忡 ���� �ؽ�Ʈ ���� ����
    if (SCENE_MGR.playMode == GameMode::Single)
    {
        Single->Set(RES_MGR_FONT.Get("fonts/KOMIKAP_.ttf"), "Multi Play to PRESS 1", 80, sf::Color::White);
        Multi->Set(RES_MGR_FONT.Get("fonts/KOMIKAP_.ttf"), "Multi Play to PRESS 2", 75, sf::Color::Red);

    }
    else if (SCENE_MGR.playMode == GameMode::Multi)
    {
        Single->Set(RES_MGR_FONT.Get("fonts/KOMIKAP_.ttf"), "Multi Play to PRESS 1", 75, sf::Color::Red);;
        Multi->Set(RES_MGR_FONT.Get("fonts/KOMIKAP_.ttf"), "Multi Play to PRESS 2", 80, sf::Color::White);
    }

	//Esc������ Ÿ��Ʋ ȭ������ �̵�
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		SCENE_MGR.ChangeScene(SceneIds::SCENE_TITLE);
	}

	if (InputMgr::GetKeyDown(sf::Keyboard::F5))
	{
		SCENE_MGR.ChangeScene(SceneIds::SCENE_TITLE);
	}
}

