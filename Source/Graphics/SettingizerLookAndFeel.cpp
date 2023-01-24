/*
  ==============================================================================

    SettingizerLookAndFeel.cpp
    Created: 23 Jan 2023 3:07:34pm
    Author:  Home

  ==============================================================================
*/

#include "SettingizerLookAndFeel.h"

void SettingizerLookAndFeel::drawLinearSliderThumb (Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle, Slider& slider)
{
    g.drawImage(hSliderKnob, slider.getLocalBounds().toFloat());
}
