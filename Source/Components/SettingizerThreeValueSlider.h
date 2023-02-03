/*
  ==============================================================================

    SettingizerLookAndFeel.h
    Created: 23 Jan 2023 3:07:34pm
    Author:  Charles Hubbard, Jr.

  ==============================================================================
*/

#pragma once

#include "../../JuceLibraryCode/JuceHeader.h"
#include "../Graphics/SettingizerLeftSliderLookAndFeel.h"
#include "../Graphics/SettingizerRightSliderLookAndFeel.h"
#include "../SettingizerPluginProcessor.h"


// This class will hold a left slider, a right slider and a "current" slider,
// So I don't have to set each one up separately.
// There is one thin slider on the left with just a pointer, stolen
// from ThreeValueSlider, but no track or background; a mirror of it
// on the right; and a normal slider in the middle.
// The user only manipulates the right and left directly. The current value
// is determined by Settingizer.
// I cannot simply use a ThreeValueSlider because they enforce that the left value must be <= the right value, but I want to be able to invert them.
class SettingizerThreeValueSlider : public juce::Component,
    public juce::Slider::Listener
{
public:
    SettingizerThreeValueSlider(SettingizerPluginProcessor&, juce::AudioProcessorValueTreeState&, const juce::String, const juce::String, const juce::String, const juce::Colour);
    ~SettingizerThreeValueSlider();
    typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    typedef juce::AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;
    typedef juce::AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;

    void paint(juce::Graphics&) override;
    void resized() override;
    void juce::Slider::Listener::sliderValueChanged(juce::Slider*);
// This encapsulates the basic setup for each of the 3 vertical sliders.
    void setUpVSlider(juce::Slider*, juce::AudioProcessorValueTreeState&, juce::String, std::unique_ptr<SliderAttachment>&);

    void sliderUpdate(double newValue);

private:
    juce::Slider leftSlider, currentSlider, rightSlider;
    juce::Rectangle<float> border;
    SettingizerLeftSliderLookAndFeel leftLNF;
    SettingizerRightSliderLookAndFeel rightLNF;
    SettingizerPluginProcessor& audioProcessor;
    juce::AudioProcessorValueTreeState& valueTreeState;

    juce::String paramIdLeft, paramIdRight, paramIdCurrent;
    juce::Colour colour;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> leftSliderAttach1, leftSliderAttach2, leftSliderAttach3, leftSliderAttach4, leftSliderAttach5;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> rightSliderAttach1, rightSliderAttach2, rightSliderAttach3, rightSliderAttach4, rightSliderAttach5;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> currentSliderAttach1, currentSliderAttach2, currentSliderAttach3, currentSliderAttach4, currentSliderAttach5;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingizerThreeValueSlider)
};
