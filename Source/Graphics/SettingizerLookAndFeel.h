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
    juce::Image hSliderKnob = juce::ImageCache::getFromMemory(BinaryData::knobHb001_png, BinaryData::knobHb001_pngSize);
    juce::Image vSliderKnob = juce::ImageCache::getFromMemory(BinaryData::knobVw001_png, BinaryData::knobVw001_pngSize);
    juce::Image backgroundImg = juce::ImageCache::getFromMemory(BinaryData::background002_png, BinaryData::background002_pngSize);
//    void drawLinearSliderThumb (juce::Graphics &, int, int, int, int, float, float, float, const juce::Slider::SliderStyle, juce::Slider &) override;
    void drawLinearSlider(juce::Graphics&, int, int, int, int, float, float, float, const juce::Slider::SliderStyle, juce::Slider&) override;
    int getSliderThumbRadius(juce::Slider&) override;

};
