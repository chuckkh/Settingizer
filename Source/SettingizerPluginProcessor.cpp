/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "SettingizerPluginProcessor.h"
#include "SettingizerPluginEditor.h"

//==============================================================================
SettingizerPluginProcessor::SettingizerPluginProcessor()
    : AudioProcessor(getBusesLayout()),
    parameters(*this, nullptr, juce::Identifier("Settingizer"),
        {
            std::make_unique<juce::AudioParameterInt>(
            "mainController",
            "MainControllerValue",
            0,
            127,
            0),
            std::make_unique<juce::AudioParameterInt>(
            "pLower1",
            "LowerLimit1",
            0,
            127,
            0),
            std::make_unique<juce::AudioParameterInt>(
            "pUpper1",
            "UpperLimit1",
            0,
            127,
            0),

            std::make_unique<juce::AudioParameterInt>(
            "pLower2",
            "LowerLimit2",
            0,
            127,
            0),
            std::make_unique<juce::AudioParameterInt>(
            "pUpper2",
            "UpperLimit2",
            0,
            127,
            0),

            std::make_unique<juce::AudioParameterInt>(
            "pLower3",
            "LowerLimit3",
            0,
            127,
            0),
            std::make_unique<juce::AudioParameterInt>(
            "pUpper3",
            "UpperLimit3",
            0,
            127,
            0),

            std::make_unique<juce::AudioParameterInt>(
            "pLower4",
            "LowerLimit4",
            0,
            127,
            0),
            std::make_unique<juce::AudioParameterInt>(
            "pUpper4",
            "UpperLimit4",
            0,
            127,
            0),

            std::make_unique<juce::AudioParameterInt>(
            "pLower5",
            "LowerLimit5",
            0,
            127,
            0),
            std::make_unique<juce::AudioParameterInt>(
            "pUpper5",
            "UpperLimit5",
            0,
            127,
            0),

            std::make_unique<juce::AudioParameterInt>(
            "pCurrent1",
            "CurrentValue1",
            0,
            127,
            0),
            std::make_unique<juce::AudioParameterInt>(
            "pCurrent2",
            "CurrentValue2",
            0,
            127,
            0),
            std::make_unique<juce::AudioParameterInt>(
            "pCurrent3",
            "CurrentValue3",
            0,
            127,
            0),
            std::make_unique<juce::AudioParameterInt>(
            "pCurrent4",
            "CurrentValue4",
            0,
            127,
            0),
            std::make_unique<juce::AudioParameterInt>(
            "pCurrent5",
            "CurrentValue5",
            0,
            127,
            0),
            std::make_unique<juce::AudioParameterInt>(
            "mainCurrent",
            "Main Current",
            0,
            127,
            0),

            std::make_unique<juce::AudioParameterInt>(
            "mainCC",
            "MainCC",
            0,
            119,
            3),
            std::make_unique<juce::AudioParameterInt>(
            "pCC1",
            "CC1",
            0,
            119,
            1),
            std::make_unique<juce::AudioParameterInt>(
            "pCC2",
            "CC2",
            0,
            119,
            7),
            std::make_unique<juce::AudioParameterInt>(
            "pCC3",
            "CC3",
            0,
            119,
            10),
            std::make_unique<juce::AudioParameterInt>(
            "pCC4",
            "CC4",
            0,
            119,
            11),
            std::make_unique<juce::AudioParameterInt>(
            "pCC5",
            "CC5",
            0,
            119,
            74)
        }
        )
{
    parameterLowerLimit1 = parameters.getRawParameterValue("pLower1");
    parameterLowerLimit2 = parameters.getRawParameterValue("pLower2");
    parameterLowerLimit3 = parameters.getRawParameterValue("pLower3");
    parameterLowerLimit4 = parameters.getRawParameterValue("pLower4");
    parameterLowerLimit5 = parameters.getRawParameterValue("pLower5");
    parameterUpperLimit1 = parameters.getRawParameterValue("pUpper1");
    parameterUpperLimit2 = parameters.getRawParameterValue("pUpper2");
    parameterUpperLimit3 = parameters.getRawParameterValue("pUpper3");
    parameterUpperLimit4 = parameters.getRawParameterValue("pUpper4");
    parameterUpperLimit5 = parameters.getRawParameterValue("pUpper5");
    parameterCurrentValue1 = parameters.getRawParameterValue("pCurrent1");
    parameterCurrentValue2 = parameters.getRawParameterValue("pCurrent2");
    parameterCurrentValue3 = parameters.getRawParameterValue("pCurrent3");
    parameterCurrentValue4 = parameters.getRawParameterValue("pCurrent4");
    parameterCurrentValue5 = parameters.getRawParameterValue("pCurrent5");
    mainCurrentValue = parameters.getRawParameterValue("mainCurrent");
    mainCC = parameters.getRawParameterValue("mainCC");
    parameterCC1 = parameters.getRawParameterValue("pCC1");
    parameterCC2 = parameters.getRawParameterValue("pCC2");
    parameterCC3 = parameters.getRawParameterValue("pCC3");
    parameterCC4 = parameters.getRawParameterValue("pCC4");
    parameterCC5 = parameters.getRawParameterValue("pCC5");
    mainControllerValue = parameters.getRawParameterValue("mainController");
}



           


template <typename any>
void SettingizerPluginProcessor::processMidi(juce::AudioBuffer<any>& buffer, juce::MidiBuffer& midiMessages)
{
    buffer.clear();
    juce::MidiBuffer midiOutput;

    // Here I calculate all the output CC values!!!

    uint8_t current = *mainControllerValue;
    uint8_t lower1 = *parameterLowerLimit1;
    uint8_t lower2 = *parameterLowerLimit2;
    uint8_t lower3 = *parameterLowerLimit3;
    uint8_t lower4 = *parameterLowerLimit4;
    uint8_t lower5 = *parameterLowerLimit5;
    int newVal1 = current * (*parameterUpperLimit1 - lower1) / 127 + lower1;
    int newVal2 = current * (*parameterUpperLimit2 - lower2) / 127 + lower2;
    int newVal3 = current * (*parameterUpperLimit3 - lower3) / 127 + lower3;
    int newVal4 = current * (*parameterUpperLimit4 - lower4) / 127 + lower4;
    int newVal5 = current * (*parameterUpperLimit5 - lower5) / 127 + lower5;
    if (current != *mainCurrentValue) {
        *mainCurrentValue = (float)current;
        midiOutput.addEvent(juce::MidiMessage::controllerEvent(1, (int)(*mainCC), current), 0);
    }
    if (newVal1 != *parameterCurrentValue1) {
        *parameterCurrentValue1 = (float)newVal1;
        midiOutput.addEvent(juce::MidiMessage::controllerEvent(1, (int)(*parameterCC1), newVal1), 0);
    }
    if (newVal2 != *parameterCurrentValue2) {
        *parameterCurrentValue2 = (float)newVal2;
        midiOutput.addEvent(juce::MidiMessage::controllerEvent(1, (int)(*parameterCC2), newVal2), 0);
    }
    if (newVal3 != *parameterCurrentValue3) {
        *parameterCurrentValue3 = (float)newVal3;
        midiOutput.addEvent(juce::MidiMessage::controllerEvent(1, (int)(*parameterCC3), newVal3), 0);
    }
    if (newVal4 != *parameterCurrentValue4) {
        *parameterCurrentValue4 = (float)newVal4;
        midiOutput.addEvent(juce::MidiMessage::controllerEvent(1, (int)(*parameterCC4), newVal4), 0);
    }
    if (newVal5 != *parameterCurrentValue5) {
        *parameterCurrentValue5 = (float)newVal5;
        midiOutput.addEvent(juce::MidiMessage::controllerEvent(1, (int)(*parameterCC5), newVal5), 0);
    }


    //    juce::MidiMessage msg = { 176, 10, dummyValue };
    //    juce::MidiMessage msg = juce::MidiMessage::controllerEvent(1, 10, dummyValue);
    //    dummyValue++;
    //    dummyValue %= 120;
    //    midiOutput.addEvent(msg, 0);
    midiMessages.swapWith(midiOutput);
}


SettingizerPluginProcessor::~SettingizerPluginProcessor()
{
}

//==============================================================================
const juce::String SettingizerPluginProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SettingizerPluginProcessor::acceptsMidi() const
{
    return true;
}

bool SettingizerPluginProcessor::producesMidi() const
{
    return true;
}

bool SettingizerPluginProcessor::isMidiEffect() const
{
    return true;
}

double SettingizerPluginProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SettingizerPluginProcessor::getNumPrograms()
{
    return 1;
}

int SettingizerPluginProcessor::getCurrentProgram()
{
    return 0;
}

void SettingizerPluginProcessor::setCurrentProgram (int index)
{
}

const juce::String SettingizerPluginProcessor::getProgramName (int index)
{
    return {};
}

void SettingizerPluginProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void SettingizerPluginProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    
}

void SettingizerPluginProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void SettingizerPluginProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    processMidi(buffer, midiMessages);
}

void SettingizerPluginProcessor::processBlock(juce::AudioBuffer<double>& buffer, juce::MidiBuffer& midiMessages)
{
    processMidi(buffer, midiMessages);
}

//==============================================================================
bool SettingizerPluginProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessorEditor* SettingizerPluginProcessor::createEditor()
{
    return new SettingizerPluginEditor(*this, parameters);
}

//==============================================================================
void SettingizerPluginProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto pState = parameters.copyState();
    std::unique_ptr<juce::XmlElement> xmlRecord(pState.createXml());
    copyXmlToBinary(*xmlRecord, destData);
}

void SettingizerPluginProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

    if (xmlState.get() != nullptr)
    {
        if (xmlState->hasTagName(parameters.state.getType()))
        {
            parameters.replaceState(juce::ValueTree::fromXml(*xmlState));
        }
    }
}

juce::AudioProcessor::BusesProperties SettingizerPluginProcessor::getBusesLayout()
{
    // Live doesn't like to load midi-only plugins, so we add an audio output there.
    // From Juce example MidiLoggerPluginDemo.h
    // (Copyright (c) 2022 - Raw Material Software Limited)
    return juce::PluginHostType::PluginHostType().isAbletonLive() ? BusesProperties().withOutput("out", juce::AudioChannelSet::stereo())
        : BusesProperties();

}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SettingizerPluginProcessor();
}
