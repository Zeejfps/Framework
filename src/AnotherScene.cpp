#include "Engine.h"
#include "AnotherScene.h"
#include "SimpleScene.h"
#include <OgreEntity.h>

AnotherScene::~AnotherScene() {

}

bool AnotherScene::onLoad() {
     return true;
}

bool AnotherScene::update(float dt) {
     if (Engine::Input()->wasButtonPressed(VK_ESC)) {
          return false;
     }

     if (Engine::Input()->wasButtonPressed(VK_A)) {
          Engine::loadScene(new SimpleScene("./assets/scenes/Simple.scene"));
     }

     return true;
}
