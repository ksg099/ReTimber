#pragma once
#include "Singleton.h"

class Scene;

class SceneMgr : public Singleton<SceneMgr>
{
	friend class Singleton<SceneMgr>;

protected:
	std::map<SceneIds, Scene*> scenes;

	SceneIds startScene = SceneIds::SCENE_TITLE;
	SceneIds currentScene = startScene;

	bool doSceneChange = false; //�� ��ȯ ����
	SceneIds nextScene = startScene; //����� ��

	SceneMgr() = default;
	virtual ~SceneMgr();

public:

	GameMode playMode = GameMode::Single; //Single, Multi
	std::string player1; //�÷��̾�1 �ؽ��� ��� "graphic/�ؽ���.png"
	std::string	player2;

	void Init();
	void Release();

	void ChangeScene(SceneIds id);

	Scene* GetCurrentScene() { return scenes[currentScene]; };

	void Update(float dt);
	void Draw(sf::RenderWindow& window);


	SceneMgr(const SceneMgr&) = delete;
	SceneMgr(SceneMgr&&) = delete;
	SceneMgr& operator=(const SceneMgr&) = delete;
	SceneMgr& operator=(SceneMgr&&) = delete;
};

#define SCENE_MGR (SceneMgr::Instance())