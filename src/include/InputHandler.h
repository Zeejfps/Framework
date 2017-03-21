#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

enum Axis {
     MOUSE_X,
     MOUSE_Y,
     JS_AXIS_0,
     JS_AXIS_1,
     JS_AXIS_3,
     JS_AXIS_4,
};

enum Button {
     VK_ESC,
     VK_A,
     VK_S,
     VK_D,
     VK_W,
     VK_SPACE,
     JS_BUTTON_0,
     VK_UNASSIGNED,
};

class InputHandler {
public:
     virtual ~InputHandler(){};
     virtual void update() = 0;
     virtual float getAxis(Axis) = 0;
     virtual bool isButtonDown(Button) = 0;
     virtual bool wasButtonPressed(Button) = 0;
     virtual bool wasButtonReleased(Button) = 0;
};

#endif /* INPUT_HANDLER_H */
