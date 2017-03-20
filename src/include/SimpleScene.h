#ifndef SIMPLE_SCENE_H
#define SIMPLE_SCENE_H

#include "OgreScene.h"
#include <OgreSceneNode.h>
#include <OgreAnimationState.h>

class SimpleScene : public OgreScene {

public:
     SimpleScene();
     ~SimpleScene();
     bool update(float);
     bool onLoad();

private:
     Ogre::SceneNode *mPlatformNode;
     Ogre::SceneNode *mCameraNode;
     Ogre::AnimationState **mAnimations;
};

#endif //SIMPLE_SCENE_H
