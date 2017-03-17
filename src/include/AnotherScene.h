#ifndef ANOTHER_SCENE_H
#define ANOTHER_SCENE_H

#include "OgreScene.h"
#include <OgreSceneNode.h>
#include <OgreAnimationState.h>

class AnotherScene : public OgreScene {

public:
     AnotherScene(const char* fileName) : OgreScene(fileName){};
     ~AnotherScene();
     bool update(float);
     bool onLoad();

private:
     Ogre::SceneNode *mPlatformNode;
     Ogre::SceneNode *mCameraNode;
     Ogre::AnimationState **mAnimations;
};

#endif /* ANOTHER_SCENE_H */
