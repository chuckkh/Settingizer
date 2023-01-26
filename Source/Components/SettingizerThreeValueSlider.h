/*
  ==============================================================================

    SettingizerLookAndFeel.h
    Created: 23 Jan 2023 3:07:34pm
    Author:  Charles Hubbard, Jr.

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"

class SettingizerThreeValueSlider : public juce::Slider
{
public:
    SettingizerThreeValueSlider();
    void setValue(double, juce::NotificationType);
    void setMinValue(double, juce::NotificationType, bool);
    void setMaxValue(double, juce::NotificationType, bool);
    void setMinAndMaxValues(double, double, juce::NotificationType);

};
