#ifndef OGRE_RENDERER_H
#define OGRE_RENDERER_H

#include "OgreScene.h"
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreRenderWindow.h>
#include <OgreFrameListener.h>

class OgreRenderer : public Ogre::FrameListener {

public:
     OgreRenderer();
     ~OgreRenderer();
     bool loadScene(OgreScene*);
     void startRendering();
     bool frameRenderingQueued(const Ogre::FrameEvent&);

     // Getters
     inline Ogre::Root* getRoot() {return m_root;}
     inline Ogre::RenderWindow* getWindow() {return m_window;}
     inline Ogre::Viewport* getViewport() {return m_viewport;}
     inline OgreScene* getCurrentScene() {return m_currentScene;}

private:
     // Member variables
     Ogre::Root* m_root;
     Ogre::RenderWindow* m_window;
     Ogre::Viewport* m_viewport;
     OgreScene* m_currentScene;
};

#endif /* OGRE_RENDERER_H */
