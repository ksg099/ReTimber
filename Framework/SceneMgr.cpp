#include "pch.h"
#include "SceneMgr.h"

#include "SceneGame.h"
#include "SceneCharacter.h"
#include "SceneGameMulti.h"

SceneMgr::~SceneMgr()
{
	Release();
}

void SceneMgr::Init()
{
	Release();

	//scenes.insert(std::make_pair(SceneIds::SCENE_TITLE, new SceneTitle(SceneIds::SCENE_TITLE)));
	//scenes.insert(std::make_pair(SceneIds::SCENE_MOD, new SceneMod(SceneIds::SCENE_MOD)));
	scenes.insert(std::make_pair(SceneIds::SCENE_CHARACTER, new SceneCharacter(SceneIds::SCENE_CHARACTER)));
	//scenes.insert(std::make_pair(SceneIds::SCENE_GAME, new SCENE_GAME(SceneIds::SCENE_GAME, SCENE_GAME::GameMode::Single)));
	//scenes.insert(std::make_pair(SceneIds::SCENE_GAME_2, new SceneGameMulti(SceneIds::SCENE_GAME_2)));

	for (auto& scene : scenes)
	{
		scene.second->Init();
	}

	currentScene = startScene;
	scenes[currentScene]->Enter();
}

void SceneMgr::Release()
{
	for (auto& scene : scenes)
	{
		scene.second->Release();
		delete scene.second;
	}
	scenes.clear();
}

void SceneMgr::ChangeScene(SceneIds id)
{
	// TO-DO: 모든 게임 오브젝트 업데이트 끝난 후에 씬 전환 되도록

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
