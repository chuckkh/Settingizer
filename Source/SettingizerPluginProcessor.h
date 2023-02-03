/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/**
*/
class SettingizerPluginProcessor  : public juce::AudioProcessor
                            
{
public:
    //==============================================================================
    SettingizerPluginProcessor();
    ~SettingizerPluginProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    static BusesProperties getBusesLayout();

    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    void processBlock(juce::AudioBuffer<double>&, juce::MidiBuffer&) override;

    template <typename any>
    void processMidi(juce::AudioBuffer<any>&, juce::MidiBuffer&);

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    /*juce::AudioParameterInt* parameterLowerLimit1, * parameterLowerLimit2, * parameterLowerLimit3, * parameterLowerLimit4, * parameterLowerLimit5;
    juce::AudioParameterInt* parameterUpperLimit1, * parameterUpperLimit2, * parameterUpperLimit3, * parameterUpperLimit4, * parameterUpperLimit5;
    juce::AudioParameterInt* parameterCurrentValue1, * parameterCurrentValue2, * parameterCurrentValue3, * parameterCurrentValue4, * parameterCurrentValue5;
    juce::AudioParameterInt* parameterCC1, * parameterCC2, * parameterCC3, * parameterCC4, * parameterCC5;*/
    std::atomic<float> *parameterLowerLimit1=nullptr, * parameterLowerLimit2 = nullptr, * parameterLowerLimit3 = nullptr, * parameterLowerLimit4 = nullptr, * parameterLowerLimit5 = nullptr;
    std::atomic<float>* parameterUpperLimit1 = nullptr, * parameterUpperLimit2 = nullptr, * parameterUpperLimit3 = nullptr, * parameterUpperLimit4 = nullptr, * parameterUpperLimit5 = nullptr;
    std::atomic<float>* parameterCurrentValue1 = nullptr, * parameterCurrentValue2 = nullptr, * parameterCurrentValue3 = nullptr, * parameterCurrentValue4 = nullptr, * parameterCurrentValue5 = nullptr;
    std::atomic<float>* parameterCC1 = nullptr, * parameterCC2 = nullptr, * parameterCC3 = nullptr, * parameterCC4 = nullptr, * parameterCC5 = nullptr;
    std::atomic<float>*mainControllerValue = nullptr;
    std::atomic<float>* mainCC = nullptr;
    std::atomic<float>* mainCurrentValue = nullptr;
//    std::vector<juce::AudioParameterInt*> allParameters;
    juce::AudioProcessorValueTreeState parameters;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingizerPluginProcessor)
};
