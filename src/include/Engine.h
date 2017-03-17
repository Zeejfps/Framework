#ifndef ENGINE_H
#define ENGINE_H

#include "OgreScene.h"
#include "OgreRenderer.h"
#include "OISInputHandler.h"
#include <OgreRoot.h>

class Engine  {

public:
     // Start and stop methods
     static void init();
     static void launch();
     static void exit();
     static void loadScene(OgreScene*);

     // Getter methods
     static OgreRenderer* Renderer();
     static InputHandler* Input();
private:
     // Engine components
     static OgreRenderer* m_renderer;
     static InputHandler* m_inputHandler;
};

#endif /* ENINE_H */
