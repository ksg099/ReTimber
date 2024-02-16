#include "pch.h"
#include "SceneMgr.h"

#include "SceneGame.h"

SceneMgr::~SceneMgr()
{
	Release();
}

void SceneMgr::Init()
{
	Release();

	//scenes.insert(std::make_pair(SceneIds::SCENE_TITLE, new SCENE_TITLE(SceneIds::SCENE_TITLE)));
	//scenes.insert(std::make_pair(SceneIds::SCENE_MOD, new SCENE_MOD(SceneIds::SCENE_MOD)));
	//scenes.insert(std::make_pair(SceneIds::SCENE_CHARACTER, new SCENE_CHARACTER(SceneIds::SCENE_CHARACTER)));
	scenes.insert(std::make_pair(SceneIds::SCENE_GAME, new SCENE_GAME(SceneIds::SCENE_GAME)));
	//scenes.insert(std::make_pair(SceneIds::SCENE_GAME_2, new SCENE_GAME_2(SceneIds::SCENE_GAME_2)));

	for (auto scene : scenes)
	{
		scene.second->Init();
	}

	currentScene = startScene;
	scenes[currentScene]->Enter();
}

void SceneMgr::Release()
{
	for (auto scene : scenes)
	{
		scene.second->Release();
		delete scene.second;
	}
	scenes.clear();
}

void SceneMgr::ChangeScene(SceneIds id)
{
	// TO-DO: ��� ���� ������Ʈ ������Ʈ ���� �Ŀ� �� ��ȯ �ǵ���

	scenes[currentScene]->Exit();
	currentScene = id;
	scenes[currentScene]->Enter();
}

void SceneMgr::Update(float dt)
{
	scenes[currentScene]->Update(dt);
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	scenes[currentScene]->Draw(window);
}
