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
    SettingizerRightSliderLookAndFeel::SettingizerRightSliderLookAndFeel();
    void drawLinearSlider(juce::Graphics&, int, int, int, int, float, float, float, const juce::Slider::SliderStyle, juce::Slider&) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SettingizerRightSliderLookAndFeel)
};

