/*
  ==============================================================================

    SettingizerLookAndFeel.cpp
    Created: 23 Jan 2023 3:07:34pm
    Author:  Charles Hubbard, Jr.

  ==============================================================================
*/

#include "SettingizerThreeValueSlider.h"


SettingizerThreeValueSlider::SettingizerThreeValueSlider(SettingizerPluginProcessor& p, juce::AudioProcessorValueTreeState& vts, const juce::String pIdLeft, const juce::String pIdRight, const juce::String pIdCurrent) : audioProcessor(p), valueTreeState(vts), paramIdLeft(pIdLeft), paramIdRight(pIdRight), paramIdCurrent(pIdCurrent)
    
{

    leftSlider.setLookAndFeel(&leftLNF);
    rightSlider.setLookAndFeel(&rightLNF);
    setUpVSlider(&leftSlider, valueTreeState, paramIdLeft, leftSliderAttach1);
    setUpVSlider(&rightSlider, valueTreeState, paramIdRight, rightSliderAttach1);
    setUpVSlider(&currentSlider, valueTreeState, paramIdCurrent, currentSliderAttach1);

}

SettingizerThreeValueSlider::~SettingizerThreeValueSlider()
{
    leftSlider.setLookAndFeel(nullptr);
    rightSlider.setLookAndFeel(nullptr);
}

void SettingizerThreeValueSlider::setUpVSlider(juce::Slider* slider, juce::AudioProcessorValueTreeState& vts, juce::String paramId,
    std::unique_ptr<SliderAttachment>& attachment)
{
    addAndMakeVisible(slider);
    //    slider->setBounds(slider->getBounds().expanded(20, 0));
    slider->setTextBoxStyle(juce::Slider::TextBoxBelow, true, 0, 0);
    slider->setPopupDisplayEnabled(true, true, this);
    //slider->setSliderStyle(juce::Slider::LinearVertical);
    slider->setSliderStyle(juce::Slider::LinearVertical);
    attachment.reset(new SliderAttachment(vts, paramId, *slider));
    slider->addListener(this);
}

void SettingizerThreeValueSlider::paint(juce::Graphics& g)
{

}

void SettingizerThreeValueSlider::resized()
{
    auto w = getWidth();
    auto w3 = w / 3;
    auto h = getHeight();
    leftSlider.setBounds(0, 0, w3, h);
    currentSlider.setBounds(w3, 0, w3, h);
    rightSlider.setBounds(w - w3, 0, w3, h);
}

void SettingizerThreeValueSlider::sliderValueChanged(juce::Slider* slider)
{

}

void SettingizerThreeValueSlider::sliderUpdate(double newValue)
{
    currentSlider.setValue(newValue);
}