#ifndef OGRE_SCENE_H
#define OGRE_SCENE_H

#include <OgreRoot.h>
#include <OgreSceneManager.h>

class OgreScene {
public:
     OgreScene(const char* fileName, const char* sceneName);
     virtual ~OgreScene();
     bool load(Ogre::Root*);
     void unload();

     // Functions needed to be overriden
     virtual bool update(float) = 0;
     virtual bool onLoad() = 0;

     // Getters
     Ogre::SceneManager* getSceneManager();

protected:
     Ogre::SceneManager* m_sceneManager;
     const char* m_sceneName;

private:
     // Member variables
     const char* m_fileName;
};

#endif /* OGRE_SCENE_H */
