#include "Engine.h"
#include "SimpleScene.h"
#include "AnotherScene.h"
#include <OgreEntity.h>

SimpleScene::~SimpleScene() {

}

bool SimpleScene::onLoad() {
     mCameraNode = m_sceneManager->getSceneNode("CameraNode");

     mPlatformNode = m_sceneManager->getSceneNode("PlatformNode");

     mAnimations = new Ogre::AnimationState*[5];

     Ogre::SceneNode* node;
     Ogre::Entity* entity;

     node = m_sceneManager->getSceneNode("Squirrel01");
     entity = (Ogre::Entity*)node->getAttachedObject("Squirrel01");
     mAnimations[0] = entity->getAnimationState("my_animation");
     mAnimations[0]->setLoop(true);
     mAnimations[0]->setEnabled(true);

     node = m_sceneManager->getSceneNode("Squirrel02");
     entity = (Ogre::Entity*)node->getAttachedObject("Squirrel02");
     mAnimations[1] = entity->getAnimationState("my_animation");
     mAnimations[1]->setLoop(true);
     mAnimations[1]->setEnabled(true);

     mAnimations[2] = m_sceneManager->getAnimationState("rotate");
     mAnimations[2]->setLoop(true);
     mAnimations[2]->setEnabled(true);

     mAnimations[3] = m_sceneManager->getAnimationState("hood_open_anim");
     mAnimations[3]->setLoop(true);
     mAnimations[3]->setEnabled(true);

     node = m_sceneManager->getSceneNode("Spring");
     entity = (Ogre::Entity*)node->getAttachedObject("Spring");
     mAnimations[4] = entity->getAnimationState("spring");
     mAnimations[4]->setLoop(true);
     mAnimations[4]->setEnabled(true);

     return true;
}

bool SimpleScene::update(float dt) {
     mPlatformNode->rotate(Ogre::Vector3::UNIT_Y, Ogre::Degree(25 * dt));
     for (int i = 0; i < 5; i++) {
          mAnimations[i]->addTime(dt);
     }

     if (Engine::Input()->wasButtonPressed(VK_ESC)) {
          return false;
     }

     if (Engine::Input()->wasButtonPressed(VK_A)) {
          Engine::loadScene(new AnotherScene("./assets/scenes/Another.scene"));
     }

     return true;
}
