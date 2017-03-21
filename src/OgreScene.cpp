#include "OgreScene.h"
#include "OgreSceneParser.h"

OgreScene::OgreScene(const char* fileName, const char* sceneName) {
     m_fileName = fileName;
     m_sceneName = sceneName;
}

OgreScene::~OgreScene() {
     unload();
     m_sceneManager = NULL;
     Ogre::ResourceGroupManager& rgm = Ogre::ResourceGroupManager::getSingleton();
     rgm.destroyResourceGroup(m_sceneName);
}

bool OgreScene::load(Ogre::Root* root) {
     m_sceneManager = root->createSceneManager(Ogre::ST_GENERIC);
     if (!parseScene(m_fileName, m_sceneManager, m_sceneName)) {
          std::cout << "Failed to parse scene!\n";
          return false;
     }
     Ogre::ResourceGroupManager& rgm = Ogre::ResourceGroupManager::getSingleton();
     rgm.loadResourceGroup(m_sceneName);
     return onLoad();
}

void OgreScene::unload() {
     m_sceneManager->clearScene();
     m_sceneManager->destroyAllCameras();
     Ogre::ResourceGroupManager& rgm = Ogre::ResourceGroupManager::getSingleton();
     rgm.unloadResourceGroup(m_sceneName);
}

Ogre::SceneManager* OgreScene::getSceneManager() {
     return m_sceneManager;
}
