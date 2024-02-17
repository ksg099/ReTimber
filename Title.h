#pragma once
#include "Scene.h"
#include "TextGo.h"

class Title : public Scene
{
protected:
	TextGo* text;

public:

	Title(SceneIds id);
	virtual ~Title() = default;

	void Init() override;
	void Release() override;

	void Enter() override;
	void Exit() override;

	void Update(float dt) override;

};

