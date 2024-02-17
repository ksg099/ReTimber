#pragma once
#include "Scene.h"
#include "TextGo.h"

class Title : public Scene
{
protected:
	TextGo text;
	Title* title;
public:

	Title(SceneIds id);
	virtual ~Title() = default;

	void Init() override;
	void Release() override;

	void Enter() override;
	void Exit() override;

	void Update(float dt) override;

};

