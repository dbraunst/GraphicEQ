/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

//#ifndef SLIDER_SPACING
#define SLIDER_SPACING 30

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <iostream>


//==============================================================================
Ps10_equalizerAudioProcessorEditor::Ps10_equalizerAudioProcessorEditor (Ps10_equalizerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    char s[MAX_BAND];
    
    //slider bandGain[MAX_BAND]
    for(int i = 0; i < MAX_BAND; i++)
    {
        //set slider params
        bandGain[i].setSliderStyle(Slider::LinearVertical);
        bandGain[i].setRange(MIN_GAIN_DB, 0, 3);
        bandGain[i].setTextBoxStyle(juce::Slider::TextBoxBelow, true,
                SLIDER_SPACING, 20);
        bandGain[i].setValue(INIT_GAIN_DB);
        
        //add sliders to GUI
        addAndMakeVisible(&bandGain[i]);
        
        //set band center freq string and assign to bandlabel
        p.equalizer.get_band_cf_str(i, s);
        bandLabel[i].setText(s, dontSendNotification);
        
        //attach label to sliders + add to GUI
        bandLabel[i].attachToComponent(&bandGain[i], false);
        addAndMakeVisible(bandLabel[i]);
        
        bandGain[i].addListener(this);
    }
}

Ps10_equalizerAudioProcessorEditor::~Ps10_equalizerAudioProcessorEditor()
{
    
}

//==============================================================================
void Ps10_equalizerAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    
    //Titles, upper + lower
    g.drawText("Band Center Frequencies", 15, 15, 200, 25, Justification::centredLeft, 1);
    g.drawFittedText("Band Gain, dB", getLocalBounds(), Justification::centredBottom, 1);
    
    
}

void Ps10_equalizerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    for (int i = 0; i < MAX_BAND; i++)
    {
        bandGain[i].setBounds((i + 1) * 35, 70, SLIDER_SPACING, 200);
        bandGain[i].setValue(0.0);
    }
}

void Ps10_equalizerAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    //get slider from addr of array, set gain DB based on dragged value
    int i = (int)(slider - &bandGain[0]);
    //std::cout << "sliderChanged: " << i << ": "<< slider->getValue() << std::endl;
    processor.equalizer.set_gain_dB(i, slider->getValue());
}
