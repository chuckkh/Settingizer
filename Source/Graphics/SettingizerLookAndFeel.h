/*
  ==============================================================================

    SettingizerLookAndFeel.h
    Created: 23 Jan 2023 3:07:34pm
    Author:  Home

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../BinaryAssets/BinaryData.h"

class SettingizerLookAndFeel : public juce::LookAndFeel_V4
{
    juce::Image hSliderKnob = juce::ImageCache::getFromMemory(BinaryData::knob001_png, BinaryData::knob001_pngSize);
    void 	drawLinearSliderThumb (Graphics &, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle, Slider &) override;

};
