#include "Engine.h"
#include "SimpleScene.h"
#include <OgreEntity.h>

SimpleScene::SimpleScene():
OgreScene("./assets/scenes/Simple.scene", "SimpleScene")
{

}

SimpleScene::~SimpleScene() {
}

bool SimpleScene::onLoad() {
     m_sceneManager->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
     m_sceneManager->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE);

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
     mAnimations[3]->setLoop(false);
     mAnimations[3]->setEnabled(false);

     node = m_sceneManager->getSceneNode("Spring");
     entity = (Ogre::Entity*)node->getAttachedObject("Spring");
     mAnimations[4] = entity->getAnimationState("spring");
     mAnimations[4]->setLoop(false);
     mAnimations[4]->setEnabled(true);
     mAnimations[4]->setTimePosition(7);

     return true;
}

bool SimpleScene::update(float dt) {

     if(mAnimations[3]->getLength()==mAnimations[3]->getTimePosition()) {
          mAnimations[3]->setEnabled(false);
     }

     if(mAnimations[4]->getTimePosition() >= 7) {
          mAnimations[4]->setTimePosition(7);
          //mAnimations[4]->setEnabled(false);
     }

     mPlatformNode->rotate(Ogre::Vector3::UNIT_Y, Ogre::Degree(25 * dt));
     for (int i = 0; i < 5; i++) {
          mAnimations[i]->addTime(dt);
     }

     if (Engine::Input()->wasButtonPressed(VK_ESC)) {
          return false;
     }

     float mouseX = Engine::Input()->getAxis(MOUSE_X);
     float mouseY = Engine::Input()->getAxis(MOUSE_Y);

     mCameraNode->yaw(Ogre::Degree( -mouseX*dt*3 ), Ogre::Node::TS_WORLD);
     mCameraNode->pitch(Ogre::Degree(-mouseY * dt*3));

     float jsAxis3 = Engine::Input()->getAxis(JS_AXIS_3);
     float jsAxis4 = Engine::Input()->getAxis(JS_AXIS_4);

     mCameraNode->yaw(Ogre::Degree( -jsAxis3*dt*50.0), Ogre::Node::TS_WORLD);
     mCameraNode->pitch(Ogre::Degree(-jsAxis4*dt*50.0));

     if (Engine::Input()->isButtonDown(VK_A)) {
          mCameraNode->translate(-10*dt, 0, 0, Ogre::Node::TransformSpace::TS_LOCAL);
     }
     else if (Engine::Input()->isButtonDown(VK_D)) {
          mCameraNode->translate(10*dt, 0, 0, Ogre::Node::TransformSpace::TS_LOCAL);
     }

     if (Engine::Input()->isButtonDown(VK_W)) {
          mCameraNode->translate(0, 0, -10*dt, Ogre::Node::TransformSpace::TS_LOCAL);
     }
     else if (Engine::Input()->isButtonDown(VK_S)) {
          mCameraNode->translate(0, 0, 10*dt, Ogre::Node::TransformSpace::TS_LOCAL);
     }

     if (Engine::Input()->wasButtonPressed(VK_SPACE) || Engine::Input()->wasButtonPressed(JS_BUTTON_0)) {
          mAnimations[3]->setTimePosition(0);
          mAnimations[4]->setTimePosition(0);
          mAnimations[3]->setEnabled(true);
          mAnimations[4]->setEnabled(true);
     }

     float horizontal = Engine::Input()->getAxis(JS_AXIS_0);
     float vertical = Engine::Input()->getAxis(JS_AXIS_1);

     mCameraNode->translate(horizontal*dt*10, 0, vertical*dt*10, Ogre::Node::TransformSpace::TS_LOCAL);

     /*if (Engine::Input()->wasButtonPressed(VK_A)) {
          Engine::loadScene(new SpaceScene());
     }*/
     return true;
}
