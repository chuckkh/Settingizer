/*
  ==============================================================================

    SettingizerLookAndFeel.cpp
    Created: 23 Jan 2023 3:07:34pm
    Author:  Charles Hubbard, Jr.

  ==============================================================================
*/

#include "SettingizerThreeValueSlider.h"

SettingizerThreeValueSlider::SettingizerThreeValueSlider() :
    juce::Slider()
{
}

void SettingizerThreeValueSlider::setValue(double newValue, juce::NotificationType notification)
{
    // for a two-value style slider, you should use the setMinValue() and setMaxValue()
    // methods to set the two values.
    //juce::jassert(style != TwoValueHorizontal && style != TwoValueVertical);

    //newValue = constrainedValue(newValue);

    if (style == juce::ThreeValueHorizontal || style == juce::ThreeValueVertical)
    {
        juce::jassert(static_cast<double> (valueMin.getValue()) <= static_cast<double> (valueMax.getValue()));

        newValue = juce::jlimit(static_cast<double> (juce::valueMin.getValue()),
            static_cast<double> (juce::valueMax.getValue()),
            newValue);
    }

    if (newValue != lastCurrentValue)
    {
        if (valueBox != nullptr)
            valueBox->hideEditor(true);

        lastCurrentValue = newValue;

        // Need to do this comparison because the Value will use equalsWithSameType to compare
        // the new and old values, so will generate unwanted change events if the type changes.
        // Cast to double before comparing, to prevent comparing as another type (e.g. String).
        if (static_cast<double> (currentValue.getValue()) != newValue)
            currentValue = newValue;

        updateText();
        owner.repaint();

        triggerChangeMessage(notification);
    }
}

void SettingizerThreeValueSlider::setMinValue(double newValue, juce::NotificationType notification, bool allowNudgingOfOtherValues)
{
    // The minimum value only applies to sliders that are in two- or three-value mode.
    jassert(style == TwoValueHorizontal || style == TwoValueVertical
        || style == ThreeValueHorizontal || style == ThreeValueVertical);

    newValue = constrainedValue(newValue);

    if (style == TwoValueHorizontal || style == TwoValueVertical)
    {
        if (allowNudgingOfOtherValues && newValue > static_cast<double> (valueMax.getValue()))
            setMaxValue(newValue, notification, false);

        newValue = jmin(static_cast<double> (valueMax.getValue()), newValue);
    }
    else
    {
        if (allowNudgingOfOtherValues && newValue > lastCurrentValue)
            setValue(newValue, notification);

        newValue = jmin(lastCurrentValue, newValue);
    }

    if (lastValueMin != newValue)
    {
        lastValueMin = newValue;
        valueMin = newValue;
        owner.repaint();
        updatePopupDisplay();

        triggerChangeMessage(notification);
    }
}

void SettingizerThreeValueSlider::setMaxValue(double newValue, juce::NotificationType notification, bool allowNudgingOfOtherValues)
{
    // The maximum value only applies to sliders that are in two- or three-value mode.
    jassert(style == TwoValueHorizontal || style == TwoValueVertical
        || style == ThreeValueHorizontal || style == ThreeValueVertical);

    newValue = constrainedValue(newValue);

    if (style == TwoValueHorizontal || style == TwoValueVertical)
    {
        if (allowNudgingOfOtherValues && newValue < static_cast<double> (valueMin.getValue()))
            setMinValue(newValue, notification, false);

        newValue = jmax(static_cast<double> (valueMin.getValue()), newValue);
    }
    else
    {
        if (allowNudgingOfOtherValues && newValue < lastCurrentValue)
            setValue(newValue, notification);

        newValue = jmax(lastCurrentValue, newValue);
    }

    if (lastValueMax != newValue)
    {
        lastValueMax = newValue;
        valueMax = newValue;
        owner.repaint();
        updatePopupDisplay();

        triggerChangeMessage(notification);
    }
}

void SettingizerThreeValueSlider::setMinAndMaxValues(double newMinValue, double newMaxValue, juce::NotificationType notification)
{
    // The maximum value only applies to sliders that are in two- or three-value mode.
    jassert(style == TwoValueHorizontal || style == TwoValueVertical
        || style == ThreeValueHorizontal || style == ThreeValueVertical);

    if (newMaxValue < newMinValue)
        std::swap(newMaxValue, newMinValue);

    newMinValue = constrainedValue(newMinValue);
    newMaxValue = constrainedValue(newMaxValue);

    if (lastValueMax != newMaxValue || lastValueMin != newMinValue)
    {
        lastValueMax = newMaxValue;
        lastValueMin = newMinValue;
        valueMin = newMinValue;
        valueMax = newMaxValue;
        owner.repaint();

        triggerChangeMessage(notification);
    }
}
