#include "outputs/auto_margins.h"

uint16_t OutputAutoComponent_Margin::getCoordinateX(size_t x, size_t x_max)
{
    return UINT16_MAX * (1 / ((float) x_max - 1)) * ((float) x);
}

uint16_t OutputAutoComponent_Margin::getCoordinateY(size_t y, size_t y_max)
{
    return UINT16_MAX * (1 / ((float) y_max - 1)) * ((float) y);
}
