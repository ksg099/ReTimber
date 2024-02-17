#pragma once
#include "Scene.h"
class SceneCharacter : public Scene
{
protected:




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

