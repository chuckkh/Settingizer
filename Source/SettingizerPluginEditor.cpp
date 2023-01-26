/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "SettingizerPluginProcessor.h"
#include "SettingizerPluginEditor.h"

//==============================================================================
SettingizerPluginEditor::SettingizerPluginEditor (SettingizerPluginProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p), valueTreeState (vts)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setLookAndFeel(&lnf);
    /*
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
    */
    setUpCCBox(&ccSelectorMain, vts, "mainCC", ccSelectorAttachMain);
    setUpCCBox(&ccSelector1, vts, "pCC1", ccSelectorAttach1);
    setUpCCBox(&ccSelector2, vts, "pCC2", ccSelectorAttach2);
    setUpCCBox(&ccSelector3, vts, "pCC3", ccSelectorAttach3);
    setUpCCBox(&ccSelector4, vts, "pCC4", ccSelectorAttach4);
    setUpCCBox(&ccSelector5, vts, "pCC5", ccSelectorAttach5);
    setUpVSlider(&leftSlider1, vts, "pLower1", leftSliderAttach1);
    setUpVSlider(&leftSlider2, vts, "pLower2", leftSliderAttach2);
    setUpVSlider(&leftSlider3, vts, "pLower3", leftSliderAttach3);
    setUpVSlider(&leftSlider4, vts, "pLower4", leftSliderAttach4);
    setUpVSlider(&leftSlider5, vts, "pLower5", leftSliderAttach5);
    setUpVSlider(&currentSlider1, vts, "pCurrent1", currentSliderAttach1);
    setUpVSlider(&currentSlider2, vts, "pCurrent2", currentSliderAttach2);
    setUpVSlider(&currentSlider3, vts, "pCurrent3", currentSliderAttach3);
    setUpVSlider(&currentSlider4, vts, "pCurrent4", currentSliderAttach4);
    setUpVSlider(&currentSlider5, vts, "pCurrent5", currentSliderAttach5);

    setUpHSlider(&mainSlider, vts, "mainController", mainSliderAttach);
    setUpVSlider(&rightSlider1, vts, "pUpper1", rightSliderAttach1);
    setUpVSlider(&rightSlider2, vts, "pUpper2", rightSliderAttach2);
    setUpVSlider(&rightSlider3, vts, "pUpper3", rightSliderAttach3);
    setUpVSlider(&rightSlider4, vts, "pUpper4", rightSliderAttach4);
    setUpVSlider(&rightSlider5, vts, "pUpper5", rightSliderAttach5);
    addAndMakeVisible(ccLabelMain);
//    ccLabelMain.setColour
    ccLabelMain.setText("Main CC", juce::NotificationType::dontSendNotification);

    ccLabel1.setText("CC 1", juce::NotificationType::dontSendNotification);
    ccLabel2.setText("CC 2", juce::NotificationType::dontSendNotification);
    ccLabel3.setText("CC 3", juce::NotificationType::dontSendNotification);
    ccLabel4.setText("CC 4", juce::NotificationType::dontSendNotification);
    ccLabel5.setText("CC 5", juce::NotificationType::dontSendNotification);
    addAndMakeVisible(ccLabel1);
    addAndMakeVisible(ccLabel2);
    addAndMakeVisible(ccLabel3);
    addAndMakeVisible(ccLabel4);
    addAndMakeVisible(ccLabel5);
    addAndMakeVisible(leftLabel1);
    addAndMakeVisible(leftLabel2);
    addAndMakeVisible(leftLabel3);
    addAndMakeVisible(leftLabel4);
    addAndMakeVisible(leftLabel5);
    leftLabel1.setText("L1", juce::NotificationType::dontSendNotification);
    leftLabel2.setText("L2", juce::NotificationType::dontSendNotification);
    leftLabel3.setText("L3", juce::NotificationType::dontSendNotification);
    leftLabel4.setText("L4", juce::NotificationType::dontSendNotification);
    leftLabel5.setText("L5", juce::NotificationType::dontSendNotification);


    addAndMakeVisible(currentLabel1);
    addAndMakeVisible(currentLabel2);
    addAndMakeVisible(currentLabel3);
    addAndMakeVisible(currentLabel4);
    addAndMakeVisible(currentLabel5);
    currentLabel1.setText("1", juce::NotificationType::dontSendNotification);
    currentLabel2.setText("2", juce::NotificationType::dontSendNotification);
    currentLabel3.setText("3", juce::NotificationType::dontSendNotification);
    currentLabel4.setText("4", juce::NotificationType::dontSendNotification);
    currentLabel5.setText("5", juce::NotificationType::dontSendNotification);

    addAndMakeVisible(rightLabel1);
    addAndMakeVisible(rightLabel2);
    addAndMakeVisible(rightLabel3);
    addAndMakeVisible(rightLabel4);
    addAndMakeVisible(rightLabel5);
    rightLabel1.setText("R1", juce::NotificationType::dontSendNotification);
    rightLabel2.setText("R2", juce::NotificationType::dontSendNotification);
    rightLabel3.setText("R3", juce::NotificationType::dontSendNotification);
    rightLabel4.setText("R4", juce::NotificationType::dontSendNotification);
    rightLabel5.setText("R5", juce::NotificationType::dontSendNotification);



    /*
    currentSlider1.getValueObject().referTo(valueTreeState.getParameterAsValue("pCurrent1"));
    currentSlider2.getValueObject().referTo(valueTreeState.getParameterAsValue("pCurrent2"));
    currentSlider3.getValueObject().referTo(valueTreeState.getParameterAsValue("pCurrent3"));
    currentSlider4.getValueObject().referTo(valueTreeState.getParameterAsValue("pCurrent4"));
    currentSlider5.getValueObject().referTo(valueTreeState.getParameterAsValue("pCurrent5"));
    /**/
    startTimerHz(30);


    setSize (800, 350);
}

void SettingizerPluginEditor::timerCallback()
{
    currentSlider1.setValue(*valueTreeState.getRawParameterValue("pCurrent1"));
    currentSlider2.setValue(*valueTreeState.getRawParameterValue("pCurrent2"));
    currentSlider3.setValue(*valueTreeState.getRawParameterValue("pCurrent3"));
    currentSlider4.setValue(*valueTreeState.getRawParameterValue("pCurrent4"));
    currentSlider5.setValue(*valueTreeState.getRawParameterValue("pCurrent5"));
}



SettingizerPluginEditor::~SettingizerPluginEditor()
{
    setLookAndFeel(nullptr);
    stopTimer();
}

//==============================================================================
void SettingizerPluginEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.drawImageAt(lnf.backgroundImg, 0, 0, false);
    g.setColour (juce::Colours::mintcream);
    g.setFont (30.0f);
    g.drawFittedText("Settingizer", 0, 0, 800, 40, juce::Justification::centredTop, 1);
}

void SettingizerPluginEditor::resized()
{
    ccLabelMain.setBounds(5, 8, 60, 10);
    ccLabel1.setBounds(10, 53, 60, 25);
    ccLabel2.setBounds(10, 103, 60, 25);
    ccLabel3.setBounds(10, 153, 60, 25);
    ccLabel4.setBounds(10, 203, 60, 25);
    ccLabel5.setBounds(10, 253, 60, 25);

    ccSelectorMain.setBounds(5, 20, 60, 30);

    ccSelector1.setBounds(10, 75, 60, 25);
    ccSelector2.setBounds(10, 125, 60, 25);
    ccSelector3.setBounds(10, 175, 60, 25);
    ccSelector4.setBounds(10, 225, 60, 25);
    ccSelector5.setBounds(10, 275, 60, 25);
    leftSlider1.setBounds(100, 10, 25, 280);
    leftSlider2.setBounds(130, 10, 25, 280);
    leftSlider3.setBounds(160, 10, 25, 280);
    leftSlider4.setBounds(190, 10, 25, 280);
    leftSlider5.setBounds(220, 10, 25, 280);
    leftLabel1.setBounds(100, 300, 25, 50);
    leftLabel2.setBounds(130, 300, 25, 50);
    leftLabel3.setBounds(160, 300, 25, 50);
    leftLabel4.setBounds(190, 300, 25, 50);
    leftLabel5.setBounds(220, 300, 25, 50);
    currentSlider1.setBounds(325, 50, 18, 200);
    currentSlider2.setBounds(358, 50, 18, 200);
    currentSlider3.setBounds(391, 50, 18, 200);
    currentSlider4.setBounds(424, 50, 18, 200);
    currentSlider5.setBounds(457, 50, 18, 200);
    currentLabel1.setBounds(325, 260, 18, 50);
    currentLabel2.setBounds(358, 260, 18, 50);
    currentLabel3.setBounds(391, 260, 18, 50);
    currentLabel4.setBounds(424, 260, 18, 50);
    currentLabel5.setBounds(457, 260, 18, 50);
    mainSlider.setBounds(250, 300, 300, 50);
    rightSlider1.setBounds(580, 10, 25, 280);
    rightSlider2.setBounds(610, 10, 25, 280);
    rightSlider3.setBounds(640, 10, 25, 280);
    rightSlider4.setBounds(670, 10, 25, 280);
    rightSlider5.setBounds(700, 10, 25, 280);
    rightLabel1.setBounds(580, 300, 25, 50);
    rightLabel2.setBounds(610, 300, 25, 50);
    rightLabel3.setBounds(640, 300, 25, 50);
    rightLabel4.setBounds(670, 300, 25, 50);
    rightLabel5.setBounds(700, 300, 25, 50);




    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void SettingizerPluginEditor::setUpVSlider(juce::Slider* slider, juce::AudioProcessorValueTreeState& vts, juce::String paramId,
    std::unique_ptr<SliderAttachment>& attachment)
{
    addAndMakeVisible(slider);
//    slider->setBounds(slider->getBounds().expanded(20, 0));
    slider->setTextBoxStyle(juce::Slider::TextBoxBelow, true, 0, 0);
    slider->setPopupDisplayEnabled(true, true, this);
    //slider->setSliderStyle(juce::Slider::LinearVertical);
    slider->setSliderStyle(juce::Slider::ThreeValueVertical);
    attachment.reset(new SliderAttachment(vts, paramId, *slider));
    slider->addListener(this);
}

void SettingizerPluginEditor::setUpHSlider(juce::Slider* slider, juce::AudioProcessorValueTreeState& vts, juce::String paramId,
    std::unique_ptr<SliderAttachment>& attachment)
{
    addAndMakeVisible(slider);
//    slider->setBounds(slider->getBounds().expanded(20, 0));
    slider->setTextBoxStyle(juce::Slider::TextBoxBelow, true, 0, 0);
    slider->setSliderStyle(juce::Slider::LinearHorizontal);
    attachment.reset(new SliderAttachment(vts, paramId, *slider));
    slider->addListener(this);
}

void SettingizerPluginEditor::setUpChannelBox(juce::ComboBox* box, juce::AudioProcessorValueTreeState& vts, juce::String paramId,
    std::unique_ptr<ComboBoxAttachment>& attachment)
{
    addAndMakeVisible(box);
    box->addItem("Omni", 128);
    box->addItem("1", 1);
    box->addItem("2", 2);
    box->addItem("3", 3);
    box->addItem("4", 4);
    box->addItem("5", 5);
    box->addItem("6", 6);
    box->addItem("7", 7);
    box->addItem("8", 8);
    box->addItem("9", 9);
    box->addItem("10", 10);
    box->addItem("11", 11);
    box->addItem("12", 12);
    box->addItem("13", 13);
    box->addItem("14", 14);
    box->addItem("15", 15);
    box->addItem("16", 16);
    //    box->setColour(juce::ComboBox::ColourIds::backgroundColourId, juce::Colours::black);
    attachment.reset(new ComboBoxAttachment(vts, paramId, *box));
    box->addListener(this);
}

void SettingizerPluginEditor::setUpCCBox(juce::ComboBox* box, juce::AudioProcessorValueTreeState& vts, juce::String paramId,
    std::unique_ptr<ComboBoxAttachment>& attachment)
{
    addAndMakeVisible(box);
    box->addItem("0", 128);
    box->addItem("1", 1);
    box->addItem("2", 2);
    box->addItem("3", 3);
    box->addItem("4", 4);
    box->addItem("5", 5);
    box->addItem("6", 6);
    box->addItem("7", 7);
    box->addItem("8", 8);
    box->addItem("9", 9);
    box->addItem("10", 10);
    box->addItem("11", 11);
    box->addItem("12", 12);
    box->addItem("13", 13);
    box->addItem("14", 14);
    box->addItem("15", 15);
    box->addItem("16", 16);
    box->addItem("17", 17);
    box->addItem("18", 18);
    box->addItem("19", 19);
    box->addItem("20", 20);
    box->addItem("21", 21);
    box->addItem("22", 22);
    box->addItem("23", 23);
    box->addItem("24", 24);
    box->addItem("25", 25);
    box->addItem("26", 26);
    box->addItem("27", 27);
    box->addItem("28", 28);
    box->addItem("29", 29);
    box->addItem("30", 30);
    box->addItem("31", 31);
    box->addItem("32", 32);
    box->addItem("33", 33);
    box->addItem("34", 34);
    box->addItem("35", 35);
    box->addItem("36", 36);
    box->addItem("37", 37);
    box->addItem("38", 38);
    box->addItem("39", 39);
    box->addItem("40", 40);
    box->addItem("41", 41);
    box->addItem("42", 42);
    box->addItem("43", 43);
    box->addItem("44", 44);
    box->addItem("45", 45);
    box->addItem("46", 46);
    box->addItem("47", 47);
    box->addItem("48", 48);
    box->addItem("49", 49);
    box->addItem("50", 50);
    box->addItem("51", 51);
    box->addItem("52", 52);
    box->addItem("53", 53);
    box->addItem("54", 54);
    box->addItem("55", 55);
    box->addItem("56", 56);
    box->addItem("57", 57);
    box->addItem("58", 58);
    box->addItem("59", 59);
    box->addItem("60", 60);
    box->addItem("61", 61);
    box->addItem("62", 62);
    box->addItem("63", 63);
    box->addItem("64", 64);
    box->addItem("65", 65);
    box->addItem("66", 66);
    box->addItem("67", 67);
    box->addItem("68", 68);
    box->addItem("69", 69);
    box->addItem("70", 70);
    box->addItem("71", 71);
    box->addItem("72", 72);
    box->addItem("73", 73);
    box->addItem("74", 74);
    box->addItem("75", 75);
    box->addItem("76", 76);
    box->addItem("77", 77);
    box->addItem("78", 78);
    box->addItem("79", 79);
    box->addItem("80", 80);
    box->addItem("81", 81);
    box->addItem("82", 82);
    box->addItem("83", 83);
    box->addItem("84", 84);
    box->addItem("85", 85);
    box->addItem("86", 86);
    box->addItem("87", 87);
    box->addItem("88", 88);
    box->addItem("89", 89);
    box->addItem("90", 90);
    box->addItem("91", 91);
    box->addItem("92", 92);
    box->addItem("93", 93);
    box->addItem("94", 94);
    box->addItem("95", 95);
    box->addItem("96", 96);
    box->addItem("97", 97);
    box->addItem("98", 98);
    box->addItem("99", 99);
    box->addItem("100", 100);
    box->addItem("101", 101);
    box->addItem("102", 102);
    box->addItem("103", 103);
    box->addItem("104", 104);
    box->addItem("105", 105);
    box->addItem("106", 106);
    box->addItem("107", 107);
    box->addItem("108", 108);
    box->addItem("109", 109);
    box->addItem("110", 110);
    box->addItem("111", 111);
    box->addItem("112", 112);
    box->addItem("113", 113);
    box->addItem("114", 114);
    box->addItem("115", 115);
    box->addItem("116", 116);
    box->addItem("117", 117);
    box->addItem("118", 118);
    box->addItem("119", 119);
    //    box->setColour(juce::ComboBox::ColourIds::backgroundColourId, juce::Colours::black);
    attachment.reset(new ComboBoxAttachment(vts, paramId, *box));
    box->addListener(this);
}


void SettingizerPluginEditor::buttonClicked(juce::Button*)
{

}

void SettingizerPluginEditor::sliderValueChanged(juce::Slider*)
{

}

void SettingizerPluginEditor::comboBoxChanged(juce::ComboBox*)
{

}