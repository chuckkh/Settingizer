/*
  ==============================================================================

    SettingizerLookAndFeel.cpp
    Created: 23 Jan 2023 3:07:34pm
    Author:  Home

  ==============================================================================
*/

#include "SettingizerLookAndFeel.h"

void SettingizerLookAndFeel::drawLinearSliderThumb (juce::Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const juce::Slider::SliderStyle style, juce::Slider& slider)
{
    if (style == juce::Slider::LinearHorizontal)
    {
        g.drawImage(hSliderKnob, slider.getLocalBounds().toFloat());
        g.setColour(juce::Colours::white);
        g.setFont(15.0f);
        g.drawFittedText("KNOB", slider.getLocalBounds(), juce::Justification::centred, 1);
    }
}
