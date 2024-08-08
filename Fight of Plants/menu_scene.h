#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

#include "scene_manager.h"
#include "scene.h"

#include <iostream>

extern SceneManager scene_manager;
extern IMAGE img_menu_background;

class MenuScene : public Scene
{
public:
	MenuScene() = default;
	~MenuScene() = default;

	void on_enter()
	{
		mciSendString(_T("play bgm_menu repeat from 0"), NULL, 0, NULL);
	}
	
	void on_draw(const Camera& camera)
	{
		putimage(0, 0, &img_menu_background);
	}

	void on_input(const ExMessage& msg)
	{
		if (msg.message == WM_KEYUP)
		{
			mciSendString(_T("play ui_confirm from 0"), NULL, 0, NULL);
			scene_manager.switch_to(SceneManager::SceneType::Selector);
		}
	}

	
private:
	 
};
#endif // !_MENU_SCENE_H_

