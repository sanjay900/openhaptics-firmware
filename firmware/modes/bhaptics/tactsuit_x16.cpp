#include <Arduino.h>
#include <Wire.h>

#include "connections/bhaptics.h"
#include "firmware.h"
#include "main.h"
#include "output_writers/direct.h"
#include "outputs/auto_margins.h"
const uint16_t _bh_max_x = 4;
const uint16_t _bh_max_y = 5;

inline Point2D* make_point(uint16_t x, uint16_t y) {
    return new Point2D(UINT16_MAX * (1 / ((float)_bh_max_x - 1)) * ((float)x), UINT16_MAX * (1 / ((float)_bh_max_y - 1)) * ((float)y));
}
Point2D* indexesToPoints[40] = {

    make_point(0, 0),
    make_point(1, 0),
    make_point(0, 1),
    make_point(1, 1),
    make_point(0, 2),
    make_point(1, 2),
    make_point(0, 3),
    make_point(1, 4),
    make_point(0, 4),
    make_point(1, 4),

    make_point(0, 0),
    make_point(1, 0),
    make_point(0, 1),
    make_point(1, 1),
    make_point(0, 2),
    make_point(1, 2),
    make_point(0, 3),
    make_point(1, 3),
    make_point(0, 4),
    make_point(1, 4),

    make_point(2, 0),
    make_point(3, 0),
    make_point(2, 1),
    make_point(3, 1),
    make_point(2, 2),
    make_point(3, 2),
    make_point(2, 3),
    make_point(3, 4),
    make_point(2, 4),
    make_point(3, 4),

    make_point(2, 0),
    make_point(3, 0),
    make_point(2, 1),
    make_point(3, 1),
    make_point(2, 2),
    make_point(3, 2),
    make_point(2, 3),
    make_point(3, 3),
    make_point(2, 4),
    make_point(3, 4)};

void vestMotorTransformer(std::string& value) {
    for (size_t i = 0; i < 20; i++) {
        uint8_t byte = value[i];
        uint actIndex = i * 2;

        outputData_t output_0;
        output_0.point = *indexesToPoints[actIndex];
        output_0.intensity = map(((byte >> 4) & 0xf), 0, 15, 0, UINT16_MAX);

        App.getOutput()->writeOutput(
            (actIndex < 10 || actIndex >= 30) ? OUTPUT_PATH_CHEST_FRONT : OUTPUT_PATH_CHEST_BACK,
            output_0);

        outputData_t output_1;
        output_1.point = *indexesToPoints[actIndex + 1];
        output_1.intensity = map((byte & 0xf), 0, 15, 0, UINT16_MAX);

        App.getOutput()->writeOutput(
            (actIndex < 10 || actIndex >= 30) ? OUTPUT_PATH_CHEST_FRONT : OUTPUT_PATH_CHEST_BACK,
            output_1);
    }
}

void setupMode() {
    ledcSetup(0, 60, 12);
    ledcAttachPin(32, 0);

    ledcSetup(1, 60, 12);
    ledcAttachPin(33, 1);

    ledcSetup(2, 60, 12);
    ledcAttachPin(25, 2);

    ledcSetup(3, 60, 12);
    ledcAttachPin(26, 3);

    ledcSetup(4, 60, 12);
    ledcAttachPin(27, 4);

    ledcSetup(5, 60, 12);
    ledcAttachPin(14, 5);

    ledcSetup(6, 60, 12);
    ledcAttachPin(12, 6);

    ledcSetup(7, 60, 12);
    ledcAttachPin(13, 7);

    ledcSetup(8, 60, 12);
    ledcAttachPin(19, 8);

    ledcSetup(9, 60, 12);
    ledcAttachPin(18, 9);

    ledcSetup(10, 60, 12);
    ledcAttachPin(5, 10);

    ledcSetup(11, 60, 12);
    ledcAttachPin(17, 11);

    ledcSetup(12, 60, 12);
    ledcAttachPin(16, 12);

    ledcSetup(13, 60, 12);
    ledcAttachPin(4, 13);

    ledcSetup(14, 60, 12);
    ledcAttachPin(2, 14);

    ledcSetup(15, 60, 12);
    ledcAttachPin(15, 15);

    autoOutputVector_t frontOutputs{
        {
            new DirectOutputWriter(0),
            new DirectOutputWriter(1),
        },
        {
            new DirectOutputWriter(2),
            new DirectOutputWriter(3),
        },
        {
            new DirectOutputWriter(4),
            new DirectOutputWriter(5),
        },
        {
            new DirectOutputWriter(6),
            new DirectOutputWriter(7),
        },
    };
    autoOutputVector_t backOutputs{
        {
            new DirectOutputWriter(8),
            new DirectOutputWriter(9),
        },
        {
            new DirectOutputWriter(10),
            new DirectOutputWriter(11),
        },
        {
            new DirectOutputWriter(12),
            new DirectOutputWriter(13),
        },
        {
            new DirectOutputWriter(14),
            new DirectOutputWriter(15),
        },
    };

    OutputAutoComponent_Margin* chestFront = new OutputAutoComponent_Margin(frontOutputs);
    OutputAutoComponent_Margin* chestBack = new OutputAutoComponent_Margin(backOutputs);

    App.getOutput()->addComponent(OUTPUT_PATH_CHEST_FRONT, chestFront);
    App.getOutput()->addComponent(OUTPUT_PATH_CHEST_BACK, chestBack);

    BHapticsBLEConnection* bhBleConnection = new BHapticsBLEConnection(BLUETOOTH_NAME, vestMotorTransformer);
    App.registerComponent(bhBleConnection);
}