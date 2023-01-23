/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SettingizerPluginProcessor.h"
#include "Graphics/SettingizerLookAndFeel.h"
 
//==============================================================================
/**
*/
class SettingizerPluginEditor  
    : public juce::AudioProcessorEditor,
    public juce::Button::Listener,
    public juce::ComboBox::Listener,
    public juce::Slider::Listener
{
public:
    SettingizerPluginEditor (SettingizerPluginProcessor&, juce::AudioProcessorValueTreeState&);
    ~SettingizerPluginEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SettingizerPluginProcessor& audioProcessor;
    SettingizerLookAndFeel lnf;
    juce::AudioProcessorValueTreeState& valueTreeState;

    void buttonClicked(juce::Button*) override;
    void sliderValueChanged(juce::Slider*) override;
    void comboBoxChanged(juce::ComboBox*) override;

    typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    typedef juce::AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;
    typedef juce::AudioProcessorValueTreeState::ComboBoxAttachment ComboAttachment;

    juce::ComboBox channelSelector1, channelSelector2, channelSelector3, channelSelector4, channelSelector5, channelSelectorMain;
    juce::ComboBox ccSelector1, ccSelector2, ccSelector3, ccSelector4, ccSelector5, ccSelectorMain;
    juce::Slider leftSlider1, leftSlider2, leftSlider3, leftSlider4, leftSlider5;
    juce::Slider rightSlider1, rightSlider2, rightSlider3, rightSlider4, rightSlider5;
    juce::Slider mainSlider;

    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> channelSelectorAttach1, channelSelectorAttach2, channelSelectorAttach3, channelSelectorAttach4, channelSelectorAttach5, channelSelectorAttachMain;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> ccSelectorAttach1, ccSelectorAttach2, ccSelectorAttach3, ccSelectorAttach4, ccSelectorAttach5, ccSelectorAttachMain;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> leftSliderAttach1, leftSliderAttach2, leftSliderAttach3, leftSliderAttach4, leftSliderAttach5;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> rightSliderAttach1, rightSliderAttach2, rightSliderAttach3, rightSliderAttach4, rightSliderAttach5;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mainSliderAttach;




    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingizerPluginEditor)
};
