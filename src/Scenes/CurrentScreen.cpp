#include "currentScreen.h"

void ScreenScene(bool& IsRunning, bool& multiplayer) {
	switch (gamescene)
	{
	case GameScene::Menu:
		SetExitKey(KEY_ESCAPE);
		MenuScene(multiplayer);
		break;
	case GameScene::GameLoop:
		SetExitKey(NULL);
		Gameplay(multiplayer);
		break;
	case GameScene::Rules:
		SetExitKey(NULL);
		DrawRules();
		break;
	case GameScene::Credits:
		SetExitKey(NULL);
		RulesScene();
		break;
	case GameScene::Exit:
		IsRunning = false;
		break;
	default:
		break;
	}
}