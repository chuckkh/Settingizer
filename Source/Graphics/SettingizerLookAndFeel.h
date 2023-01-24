/*
  ==============================================================================

    SettingizerLookAndFeel.h
    Created: 23 Jan 2023 3:07:34pm
    Author:  Charles Hubbard, Jr.

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../BinaryAssets/BinaryData.h"

class SettingizerLookAndFeel : public juce::LookAndFeel_V4
{
public:
    juce::Image hSliderKnob = juce::ImageCache::getFromMemory(BinaryData::knob001_png, BinaryData::knob001_pngSize);
//    void drawLinearSliderThumb (juce::Graphics &, int, int, int, int, float, float, float, const juce::Slider::SliderStyle, juce::Slider &) override;
    void drawLinearSlider(juce::Graphics&, int, int, int, int, float, float, float, const juce::Slider::SliderStyle, juce::Slider&) override;

};
