/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SettingizerPluginProcessor.h"
#include "Graphics/SettingizerLookAndFeel.h"
#include "Graphics/SettingizerLeftSliderLookAndFeel.h"
#include "Graphics/SettingizerRightSliderLookAndFeel.h"
#include "Components/SettingizerThreeValueSlider.h"
 
//==============================================================================
/**
*/
class SettingizerPluginEditor  
    : public juce::AudioProcessorEditor,
    public juce::Button::Listener,
    public juce::ComboBox::Listener,
    public juce::Slider::Listener,
    public juce::Timer
{
public:
    typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    typedef juce::AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;
    typedef juce::AudioProcessorValueTreeState::ComboBoxAttachment ComboBoxAttachment;

    SettingizerPluginEditor (SettingizerPluginProcessor&, juce::AudioProcessorValueTreeState&);
    ~SettingizerPluginEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void setUpChannelBox(juce::ComboBox*, juce::AudioProcessorValueTreeState&, juce::String,
        std::unique_ptr<ComboBoxAttachment>&);
    void setUpCCBox(juce::ComboBox*, juce::AudioProcessorValueTreeState&, juce::String,
        std::unique_ptr<ComboBoxAttachment>&);
    void setUpVSlider(juce::Slider*, juce::AudioProcessorValueTreeState&, juce::String,
        std::unique_ptr<SliderAttachment>&);
    void setUpHSlider(juce::Slider*, juce::AudioProcessorValueTreeState&, juce::String,
        std::unique_ptr<SliderAttachment>&);
    void timerCallback() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SettingizerPluginProcessor& audioProcessor;
    SettingizerLookAndFeel lnf;
    SettingizerLeftSliderLookAndFeel llnf;
    SettingizerRightSliderLookAndFeel rlnf;
    juce::AudioProcessorValueTreeState& valueTreeState;

    void buttonClicked(juce::Button*) override;
    void sliderValueChanged(juce::Slider*) override;
    void comboBoxChanged(juce::ComboBox*) override;


    juce::ComboBox ccSelector1, ccSelector2, ccSelector3, ccSelector4, ccSelector5, ccSelectorMain;
    juce::Label ccLabel1, ccLabel2, ccLabel3, ccLabel4, ccLabel5, ccLabelMain;
    //juce::Slider leftSlider1, leftSlider2, leftSlider3, leftSlider4, leftSlider5;
    juce::Slider leftSlider1, leftSlider2, leftSlider3, leftSlider4, leftSlider5;
    juce::Label leftLabel1, leftLabel2, leftLabel3, leftLabel4, leftLabel5;
    juce::Slider rightSlider1, rightSlider2, rightSlider3, rightSlider4, rightSlider5;
    juce::Label rightLabel1, rightLabel2, rightLabel3, rightLabel4, rightLabel5;
    juce::Slider currentSlider1, currentSlider2, currentSlider3, currentSlider4, currentSlider5;
    juce::Label currentLabel1, currentLabel2, currentLabel3, currentLabel4, currentLabel5;
    juce::Slider mainSlider;

    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> channelSelectorAttach1, channelSelectorAttach2, channelSelectorAttach3, channelSelectorAttach4, channelSelectorAttach5, channelSelectorAttachMain;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> ccSelectorAttach1, ccSelectorAttach2, ccSelectorAttach3, ccSelectorAttach4, ccSelectorAttach5, ccSelectorAttachMain;
    /**
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> leftSliderAttach1, leftSliderAttach2, leftSliderAttach3, leftSliderAttach4, leftSliderAttach5;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> rightSliderAttach1, rightSliderAttach2, rightSliderAttach3, rightSliderAttach4, rightSliderAttach5;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> currentSliderAttach1, currentSliderAttach2, currentSliderAttach3, currentSliderAttach4, currentSliderAttach5;
    /**/
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mainSliderAttach;
    SettingizerThreeValueSlider valueSlider1, valueSlider2, valueSlider3, valueSlider4, valueSlider5;



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingizerPluginEditor)
};
