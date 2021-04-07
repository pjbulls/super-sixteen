#pragma once

#include "Display.h"
#include "AnalogIo.h"
#include <MCP23S17.h>

namespace supersixteen{

class Buttons {
  public:
    Buttons() { }
    ~Buttons() { }
  
    
    void init();
    void poll();

    int getQueuedEvent(uint16_t &value);

    void setGlideLed(bool glide);

    

  private:
    void selectStep(unsigned int stepnum);

    void saveButton(bool state);
    void loadButton(bool state);
    void playButton(bool state);
    void shiftButton(bool state);

    void recordButton(bool state);
    void repeatButton(bool state);
    void glideButton(bool state);

    void onButtonPush(uint16_t &event);
        
    int button_map[16] = { 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 }; //rows are wired sequentially
    bool button_matrix[16] = { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
    int saveCount = 0;

    bool function_button_matrix[16]; //store status of buttons in/out  -- no idea why but first bit never toggles? works when offset by one - bad memory address?

    int row = 0;
    uint16_t buttons_state;
    uint16_t buttons_mask;
};

}