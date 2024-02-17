#pragma once
#include "Scene.h"
class SceneCharacter : public Scene
{
protected:
	sf::Sprite player1;
	sf::Sprite player2;

	sf::Text num1;
	sf::Text num2;



public:
	SceneCharacter(SceneIds id);
	virtual ~SceneCharacter() = default;

	void Init() override;
	void Release()override;

	void Enter()override;
	void Exit() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

};

