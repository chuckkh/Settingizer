/*
  ==============================================================================

    SettingizerLookAndFeel.h
    Created: 23 Jan 2023 3:07:34pm
    Author:  Charles Hubbard, Jr.

  ==============================================================================
*/

#pragma once

//#include "../../JuceLibraryCode/JuceHeader.h"
//#include "../BinaryAssets/BinaryData.h"
#include "SettingizerLookAndFeel.h"

class SettingizerRightSliderLookAndFeel : public SettingizerLookAndFeel
{
public:
    void drawLinearSlider(juce::Graphics&, int, int, int, int, float, float, float, const juce::Slider::SliderStyle, juce::Slider&) override;
};
