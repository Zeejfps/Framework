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
     if (m_currentScene) {
          return m_currentScene->update(evt.timeSinceLastFrame);
     }
     return true;
}

bool OgreRenderer::loadScene(OgreScene* scene) {
     if (m_currentScene != NULL) {
          delete m_currentScene;
     }
     m_currentScene = scene;
     if (!m_currentScene->load(m_root)) {
          return false;
     }
     Ogre::SceneManager* sm = m_currentScene->getSceneManager();
     Ogre::Camera* camera = sm->getCamera("MainCamera");
     if (camera == NULL) {
          std::cout << "No Main Camera found\n";
          return false;
     }
     float actual_width = Ogre::Real(m_viewport->getActualWidth());
     float actual_height = Ogre::Real(m_viewport->getActualHeight());
     float aspect_ratio = actual_width/actual_height;
     camera->setAspectRatio(aspect_ratio);
     m_viewport->setCamera(camera);
     return true;
}
