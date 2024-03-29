/*
  ==============================================================================

    SettingizerLookAndFeel.cpp
    Created: 23 Jan 2023 3:07:34pm
    Author:  Charles Hubbard, Jr.

  ==============================================================================
*/

#include "SettingizerLookAndFeel.h"
/*
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
/* */
SettingizerLookAndFeel::SettingizerLookAndFeel()
{

}

int SettingizerLookAndFeel::getSliderThumbRadius(juce::Slider& slider)
{
    return slider.isHorizontal() ? 21 : juce::jmin(12, static_cast<int> ((float)slider.getWidth()));
//    return juce::jmin(12, slider.isHorizontal() ? static_cast<int> ((float)slider.getHeight() * 0.5f)
//        : static_cast<int> ((float)slider.getWidth() * 0.5f));
}


void SettingizerLookAndFeel::drawLinearSlider(juce::Graphics& g, int x, int y, int width, int height,
    float sliderPos,
    float minSliderPos,
    float maxSliderPos,
    const juce::Slider::SliderStyle style, juce::Slider& slider)
{
    if (slider.isBar())
    {
        g.setColour(slider.findColour(juce::Slider::trackColourId));
        g.fillRect(slider.isHorizontal() ? juce::Rectangle<float>(static_cast<float> (x), (float)y + 0.5f, sliderPos - (float)x, (float)height - 1.0f)
            : juce::Rectangle<float>((float)x + 0.5f, sliderPos, (float)width - 1.0f, (float)y + ((float)height - sliderPos)));
    }
    else
    {
        auto isTwoVal = (style == juce::Slider::SliderStyle::TwoValueVertical || style == juce::Slider::SliderStyle::TwoValueHorizontal);
        auto isThreeVal = (style == juce::Slider::SliderStyle::ThreeValueVertical || style == juce::Slider::SliderStyle::ThreeValueHorizontal);

        auto trackWidth = juce::jmin(6.0f, slider.isHorizontal() ? (float)height * 0.5f : (float)width * 0.5f);

        juce::Point<float> startPoint(slider.isHorizontal() ? (float)x : (float)x + (float)width * 0.5f,
            slider.isHorizontal() ? (float)y + (float)height * 0.5f : (float)y);

        juce::Point<float> endPoint(slider.isHorizontal() ? (float)(width + x) : startPoint.x,
            slider.isHorizontal() ? startPoint.y : (float)(height + y));

        juce::Path backgroundTrack;
        backgroundTrack.startNewSubPath(startPoint);
        backgroundTrack.lineTo(endPoint);
        g.setColour(slider.findColour(juce::Slider::backgroundColourId));
        g.strokePath(backgroundTrack, { trackWidth, juce::PathStrokeType::curved, juce::PathStrokeType::rounded });

        juce::Path valueTrack;
        juce::Point<float> minPoint, maxPoint, thumbPoint;

        if (isTwoVal || isThreeVal)
        {
            minPoint = { slider.isHorizontal() ? minSliderPos : (float)width * 0.5f,
                         slider.isHorizontal() ? (float)height * 0.5f : minSliderPos };

            if (isThreeVal)
                thumbPoint = { slider.isHorizontal() ? sliderPos : (float)width * 0.5f,
                               slider.isHorizontal() ? (float)height * 0.5f : sliderPos };

            maxPoint = { slider.isHorizontal() ? maxSliderPos : (float)width * 0.5f,
                         slider.isHorizontal() ? (float)height * 0.5f : maxSliderPos };
        }
        else
        {
            auto kx = slider.isHorizontal() ? sliderPos : ((float)x + (float)width * 0.5f);
            auto ky = slider.isHorizontal() ? ((float)y + (float)height * 0.5f) : sliderPos;

            minPoint = startPoint;
            maxPoint = { kx, ky };
        }

        auto thumbWidth = getSliderThumbRadius(slider);

        valueTrack.startNewSubPath(minPoint);
        valueTrack.lineTo(isThreeVal ? thumbPoint : maxPoint);
        g.setColour(slider.findColour(juce::Slider::trackColourId));
        g.strokePath(valueTrack, { trackWidth, juce::PathStrokeType::curved, juce::PathStrokeType::rounded });

        if (!isTwoVal)
        {
            g.setColour(slider.findColour(juce::Slider::backgroundColourId));
            if (slider.isHorizontal())
            {
                //slider.setBounds(slider.getBounds().expanded(20, 0));
                g.drawImageAt(hSliderKnob, sliderPos - 19, y + height / 2 - 12, false);
            }
            else
            {
                //slider.setBounds(slider.getBounds().expanded(0, 20));
                //g.drawImageAt(vSliderKnob, x + width / 2 - 12, sliderPos - 19, false);
                //g.setColour(slider.findColour(juce::Slider::trackColourId));
                g.setColour(slider.findColour(juce::Slider::thumbColourId));
                g.fillEllipse(juce::Rectangle<float>(static_cast<float> (thumbWidth), static_cast<float> (thumbWidth)).withCentre(isThreeVal ? thumbPoint : maxPoint));
            }
        }

        if (isTwoVal || isThreeVal)
        {
            auto sr = juce::jmin(trackWidth, (slider.isHorizontal() ? (float)height : (float)width) * 0.4f);
            auto pointerColour = slider.findColour(juce::Slider::thumbColourId);

            if (slider.isHorizontal())
            {
                drawPointer(g, minSliderPos - sr,
                    juce::jmax(0.0f, (float)y + (float)height * 0.5f - trackWidth * 2.0f),
                    trackWidth * 2.0f, pointerColour, 2);

                drawPointer(g, maxSliderPos - trackWidth,
                    juce::jmin((float)(y + height) - trackWidth * 2.0f, (float)y + (float)height * 0.5f),
                    trackWidth * 2.0f, pointerColour, 4);
            }
            else
            {
                drawPointer(g, juce::jmax(0.0f, (float)x + (float)width * 0.5f - trackWidth * 2.0f),
                    minSliderPos - trackWidth,
                    trackWidth * 2.0f, pointerColour, 1);

                drawPointer(g, juce::jmin((float)(x + width) - trackWidth * 2.0f, (float)x + (float)width * 0.5f), maxSliderPos - sr,
                    trackWidth * 2.0f, pointerColour, 3);
            }
        }
    }
}
