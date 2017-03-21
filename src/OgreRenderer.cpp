#include "OgreRenderer.h"

#include <iostream>
#include <OgreLogManager.h>

OgreRenderer::OgreRenderer() {
     Ogre::LogManager *lm = new Ogre::LogManager();
	lm->createLog("", true, false, false);

     m_root = new Ogre::Root("", "");
     m_root->loadPlugin("RenderSystem_GL");

     Ogre::RenderSystem* rs = m_root->getRenderSystemByName("OpenGL Rendering Subsystem");
     m_root->setRenderSystem(rs);
     rs->setConfigOption("Full Screen", "No");
     rs->setConfigOption("Video Mode", "800 x 600 @ 32-bit colour");

     m_window = m_root->initialise(true, "Engine");
     m_viewport = m_window->addViewport(NULL);

     m_root->addFrameListener(this);
}

OgreRenderer::~OgreRenderer() {
	m_window->removeAllViewports();
	m_window->destroy();
	m_window = NULL;

	delete m_currentScene;
	m_currentScene = NULL;

	delete m_root;
	m_root = NULL;
}

void OgreRenderer::startRendering() {
     m_root->startRendering();
}

bool OgreRenderer::frameRenderingQueued(const Ogre::FrameEvent &evt) {
     if (m_window->isClosed()) {
          return false;
     }
     if (m_loadNextScene) {
          loadNextScene();
     }
     if (m_currentScene != NULL) {
          return m_currentScene->update(evt.timeSinceLastFrame);
     }
     return true;
}

void OgreRenderer::loadScene(OgreScene* scene) {
     m_nextScene = scene;
     m_loadNextScene = true;
}

void OgreRenderer::loadNextScene() {
     m_nextScene->load(m_root);
     Ogre::SceneManager* sm = m_nextScene->getSceneManager();
     Ogre::Camera* camera;
     try {
          camera = sm->getCamera("MainCamera");
     } catch (Ogre::Exception e) {
          std::cout << "Failed to load scene: No Main Camera found\n";
          return;
     }
     float actual_width = Ogre::Real(m_viewport->getActualWidth());
     float actual_height = Ogre::Real(m_viewport->getActualHeight());
     float aspect_ratio = actual_width/actual_height;
     camera->setAspectRatio(aspect_ratio);
     m_viewport->setCamera(camera);

     if (m_currentScene != NULL) {
          m_currentScene->unload();
          //m_root->destroySceneManager(sm);
     }
     m_currentScene = m_nextScene;
     m_loadNextScene = false;
     m_nextScene = NULL;
}
