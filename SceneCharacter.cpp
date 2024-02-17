#include "pch.h"
#include "SceneCharacter.h"

SceneCharacter::SceneCharacter(SceneIds id)
	:Scene(id)
{
}

void SceneCharacter::Init()
{
	texResMgr.Load("graphics/player.png");
	texResMgr.Load("graphics/rip.png");

	player1.setTexture(texResMgr.Get("graphics/player.png"));
	player1.setPosition({ 1920/2 -300, 1080/2 });

	player2.setTexture(texResMgr.Get("graphics/rip.png"));
	player2.setPosition({ 1920 / 2 + 300, 1080 / 2 });
	
	

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
}

void SceneCharacter::Draw(sf::RenderWindow& window)
{
	window.draw(player1);
	window.draw(player2);
}
