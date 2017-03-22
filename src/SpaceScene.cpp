#include "Engine.h"
#include "SpaceScene.h"
#include "SimpleScene.h"

SpaceScene::SpaceScene() :
OgreScene("./assets/scenes/Space.scene", "SpaceScene")
{

}

SpaceScene::~SpaceScene() {

}

bool SpaceScene::onLoad() {
     m_sceneManager->setSkyBox(true, "Skybox-Material");
     m_player = m_sceneManager->getSceneNode("Player");
     return true;
}

bool SpaceScene::update(float dt) {
     if (Engine::Input()->wasButtonPressed(KC_ESC)) {
          return false;
     }

     float mouseX = Engine::Input()->getAxis(MOUSE_X);
     float mouseY = Engine::Input()->getAxis(MOUSE_Y);

     m_player->yaw(Ogre::Degree(-0.07 * mouseX), Ogre::Node::TS_WORLD);
     m_player->pitch(Ogre::Degree(-0.07 * mouseY));

     if (Engine::Input()->wasButtonPressed(KC_ENTER)) {
          std::cout << "Test?\n";
          Engine::loadScene(new SimpleScene());
     }

     return true;
}
