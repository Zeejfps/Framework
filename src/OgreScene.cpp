#include "OgreScene.h"
#include "OgreSceneParser.h"

OgreScene::OgreScene(const char* fileName) {
     m_fileName = fileName;
}

OgreScene::~OgreScene() {
     if (m_sceneManager) {
          m_sceneManager->clearScene();
     	m_sceneManager->destroyAllCameras();
          delete m_sceneManager;
          m_sceneManager = NULL;
     }
}

bool OgreScene::load(Ogre::Root* root) {
     m_sceneManager = root->createSceneManager(Ogre::ST_GENERIC);
     if (!parseScene(m_fileName, m_sceneManager)) {
          std::cout << "Failed to parse scene!\n";
          return false;
     }
     return onLoad();
}

Ogre::SceneManager* OgreScene::getSceneManager() {
     return m_sceneManager;
}
