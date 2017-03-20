#include "SpaceScene.h"

SpaceScene::SpaceScene() :
OgreScene("./assets/scenes/Space.scene")
{

}

SpaceScene::~SpaceScene() {

}

bool SpaceScene::onLoad() {
     return true;
}

bool SpaceScene::update(float dt) {
     return true;
}
