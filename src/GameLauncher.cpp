#include "Engine.h"
#include "SpaceScene.h"
#include "SimpleScene.h"

int main() {
     try {
          Engine::init();
          Engine::loadScene(new SimpleScene());
          Engine::launch();
     }
     catch(Ogre::Exception e) {
          std::cout << e.getDescription() << "\n";
          return 1;
     }
     return 0;
}
