#pragma once
#include <stdint.h>

namespace supersixteen{

class Calibration {
    public:
        void initializeCalibrationMode();

        void updateCalibration();

        int getCalibratedOutput(double pitch);

        int incrementCalibration(int amt, uint8_t step);

        void readCalibrationValues();

        void writeCalibrationValues();

        int getCalibrationValue(uint8_t step);

        int readDisplayModeValue();

        void writeDisplayModeValue(int displayMode);
};

}
