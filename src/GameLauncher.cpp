#include "Engine.h"
#include "SimpleScene.h"

int main() {
     try {
          Engine::init();
          Engine::loadScene(new SimpleScene());
          Engine::launch();
     }
     catch(...) {
          return 1;
     }
     return 0;
}
