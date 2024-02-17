#include "pch.h"
#include "SceneCharacter.h"

SceneCharacter::SceneCharacter(SceneIds id)
	:Scene(id)
{
}

void SceneCharacter::Init()
{
	
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
	window.clear(sf::Color::White);

	window.display();
}
