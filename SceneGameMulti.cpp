#include "pch.h"
#include "SceneGameMulti.h"

SceneGameMulti::SceneGameMulti(SceneIds id)
	:Scene(id),
	scenePlayer1(new SCENE_GAME(SceneIds::SCENE_GAME, GameMode::Player1)),
	scenePlayer2(new SCENE_GAME(SceneIds::SCENE_GAME, GameMode::Player2))
{
	float windowSizeX = Framework::Instance().GetWindowSize().x;
	float windowSizeY =	Framework::Instance().GetWindowSize().y;
	viewPlayer1.setViewport(sf::FloatRect(0.f, 0.f, 0.495f, 1.f));
	viewPlayer2.setViewport(sf::FloatRect(0.505f, 0.f, 0.495f, 1.f));
	viewAll.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));

	viewPlayer1.setCenter({ windowSizeX * 0.5f }, viewPlayer1.getCenter().y);
	viewPlayer2.setCenter({ windowSizeX * 0.5f }, viewPlayer2.getCenter().y);
}

void SceneGameMulti::Init()
{
	scenePlayer1->Init();
	scenePlayer2->Init();
}

void SceneGameMulti::Release()
{
	scenePlayer1->Release();
	scenePlayer2->Release();
	Scene::Release();
}

void SceneGameMulti::Enter()
{
	Scene::Enter();
	scenePlayer1->Enter();
	scenePlayer2->Enter();
}

void SceneGameMulti::Exit()
{
	scenePlayer1->Exit();
	scenePlayer2->Exit();
}

void SceneGameMulti::Update(float dt)
{
	scenePlayer2->Update(dt);
	scenePlayer1->Update(dt);
	Scene::Update(dt);

	switch (currStatus)
	{
	case SCENE_GAME::Status::Awake:
		break;
	case SCENE_GAME::Status::Game:
		break;
	case SCENE_GAME::Status::GameOver:
		break;
	case SCENE_GAME::Status::Pause:
		break;
	default:
		break;
	}



}

void SceneGameMulti::Draw(sf::RenderWindow& window)
{
	window.setView(viewPlayer1);
	scenePlayer1->Draw(window);

	window.setView(viewPlayer2);
	scenePlayer2->Draw(window);

	window.setView(viewAll);
	Scene::Draw(window);
}
