#pragma once
#include "Scene.h"
#include "TextGo.h"
//��� �ؽ�ó�� ����� �ٸ� ����� ����?  ��������Ʈ�� ����

class Title : public Scene
{
protected:
	TextGo* Titletext;
	TextGo* textcomt;

public:

	Title(SceneIds id);
	virtual ~Title() = default;

	void Init() override;
	void Release() override;

	void Enter() override;
	void Exit() override;

	void Update(float dt) override;

};

