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
	player1.setPosition({ 1920/2 -300, 1080/2 });

	player2.setTexture(texResMgr.Get("graphics/player3.png"));
	player2.setPosition({ 1920 / 2 + 300, 1080 / 2 });
	
	num1.setFont(fontResMgr.Get("fonts/KOMIKAP_.ttf"));
	num1.setString("NUM1");
	num1.setCharacterSize(24);
	num1.setFillColor(sf::Color::White);
	num1.setPosition({ 1920 / 2 - 300, 740 });
	

	num2.setFont(fontResMgr.Get("fonts/KOMIKAP_.ttf"));
	num2.setString("NUM2");
	num2.setCharacterSize(24);
	num2.setFillColor(sf::Color::White);
	num2.setPosition({ 1920 / 2 + 300, 740 });

}

void SceneCharacter::Release()
{
}

void SceneCharacter::Enter()
{
}

void SceneCharacter::Exit()
{
}

void SceneCharacter::Update(float dt)
{
	if (InputMgr::GetKeyDown(sf::Keyboard::Num1))
	{
		
	}

}

void SceneCharacter::Draw(sf::RenderWindow& window)
{
	//window.clear(sf::Color::White);
	window.draw(player1);
	window.draw(player2);
	window.draw(num1);
	window.draw(num2);
	//window.display();
}
