/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "main.h"
#include "equalizer.h"
#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Ps10_equalizerAudioProcessorEditor  : public AudioProcessorEditor, public Slider::Listener
{
public:
    Ps10_equalizerAudioProcessorEditor (Ps10_equalizerAudioProcessor&);
    ~Ps10_equalizerAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Ps10_equalizerAudioProcessor& processor;
    void sliderValueChanged (Slider* slider) override;
    
    //array of sliders and labels
    Slider bandGain[MAX_BAND];
    Label bandLabel[MAX_BAND];

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Ps10_equalizerAudioProcessorEditor)
};
