#include "pch.h"
#include "SceneCharacter.h"

SceneCharacter::SceneCharacter(SceneIds id)
	:Scene(id)
{
}

void SceneCharacter::Init()
{
	texResMgr.Load("graphics/player.png");
	texResMgr.Load("graphics/player3.png");


	fontResMgr.Load("fonts/KOMIKAP_.ttf");

	player1.setTexture(texResMgr.Get("graphics/player.png"));
	player1.setPosition({ 1920 / 2 - 300, 1080 / 2 });

	player2.setTexture(texResMgr.Get("graphics/player3.png"));
	player2.setScale(1.1f, 1.1f);
	player2.setPosition({ 1920 / 2 + 300, 1080 / 2 });

	num1.setFont(fontResMgr.Get("fonts/KOMIKAP_.ttf"));
	num1.setString("Left");
	num1.setCharacterSize(24);
	num1.setFillColor(sf::Color::White);
	num1.setPosition({ 1920 / 2 - 260, 740 });


	num2.setFont(fontResMgr.Get("fonts/KOMIKAP_.ttf"));
	num2.setString("Right");
	num2.setCharacterSize(24);
	num2.setFillColor(sf::Color::White);
	num2.setPosition({ 1920 / 2 + 370, 740 });

}

void SceneCharacter::Release()
{
}

void SceneCharacter::Enter()
{
	player1choice = false;
	player2choice = false;
}

void SceneCharacter::Exit()
{

}

void SceneCharacter::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::F5))
	{
		SCENE_MGR.ChangeScene(SceneIds::SCENE_TITLE);
	}

	if (SCENE_MGR.playMode == GameMode::Single)
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::Left))
		{
			SCENE_MGR.player1 = "graphics/player.png";
			SCENE_MGR.ChangeScene(SceneIds::SCENE_GAME);

		}
		else if (InputMgr::GetKeyDown(sf::Keyboard::Right))
		{
			SCENE_MGR.player1 = "graphics/player3.png";
			SCENE_MGR.ChangeScene(SceneIds::SCENE_GAME);

		}
	}
	if (SCENE_MGR.playMode == GameMode::Multi)
	{
		if (InputMgr::GetKeyDown(sf::Keyboard::A))
		{
			SCENE_MGR.player1 = "graphics/player.png";
			player1choice = true;
		}
		else if (InputMgr::GetKeyDown(sf::Keyboard::D))
		{
			SCENE_MGR.player1 = "graphics/player3.png";
			player1choice = true;

		}
		if (InputMgr::GetKeyDown(sf::Keyboard::Left))
		{
			SCENE_MGR.player2 = "graphics/player.png";
			player2choice = true;
		}
		else if (InputMgr::GetKeyDown(sf::Keyboard::Right))
		{
			SCENE_MGR.player2 = "graphics/player3.png";
			player2choice = true;
		}

		if (player1choice && player2choice)
		{
			SCENE_MGR.ChangeScene(SceneIds::SCENE_GAME_2);
		}
	}

}

void SceneCharacter::Draw(sf::RenderWindow& window)
{
	
	window.draw(player1);
	window.draw(player2);
	window.draw(num1);
	window.draw(num2);
	
}
