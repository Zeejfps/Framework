#include "Engine.h"

OgreRenderer* Engine::m_renderer = NULL;
InputHandler* Engine::m_inputHandler = NULL;

class OgreFrameListener : public Ogre::FrameListener {
     bool frameRenderingQueued(const Ogre::FrameEvent& e) {
          Engine::Input()->update();
          return true;
     }
};

void Engine::init() {
     std::cout << "Initializing...\n";
     m_renderer = new OgreRenderer();
     m_inputHandler = new OISInputHandler(m_renderer->getWindow());
     std::cout << "Initialized!\n";
}

void Engine::launch() {
     m_renderer->getRoot()->addFrameListener(new OgreFrameListener());
     m_renderer->startRendering();
}

void Engine::loadScene(OgreScene* scene) {
     std::cout << "Loading scene...\n";
     if (m_renderer->loadScene(scene)) {
          std::cout << "Scene loaded!\n";
     }
     else {
          std::cout << "Failed to load scene!\n";
     }
}

OgreRenderer* Engine::Renderer() {
     return m_renderer;
}

InputHandler* Engine::Input() {
     return m_inputHandler;
}

void Engine::exit() {
     delete m_renderer;
}
