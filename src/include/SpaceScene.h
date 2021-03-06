#ifndef SPACE_SCENE_H
#define SPACE_SCENE_H

#include "OgreScene.h"

class SpaceScene : public OgreScene {
public:
     SpaceScene();
     ~SpaceScene();
     bool onLoad();
     bool update(float);
private:
     Ogre::SceneNode* m_player;
};

#endif /* SPACE_SCENE_H */
