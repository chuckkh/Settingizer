/*
  ==============================================================================

    SettingizerLookAndFeel.h
    Created: 23 Jan 2023 3:07:34pm
    Author:  Home

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../BinaryAssets/BinaryData.h"

class SettingizerLookAndFeel : public juce::LookAndFeel_V4
{
public:
    juce::Image hSliderKnob = juce::ImageCache::getFromMemory(BinaryData::knob001_png, BinaryData::knob001_pngSize);
    void 	drawLinearSliderThumb (juce::Graphics &, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const juce::Slider::SliderStyle, juce::Slider &) override;

};
