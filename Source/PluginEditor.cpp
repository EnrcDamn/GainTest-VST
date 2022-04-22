/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainTestAudioProcessorEditor::GainTestAudioProcessorEditor (GainTestAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 400);

    sliderAttach = new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.treeState, GAIN_ID, gainSlider);

    gainSlider.setSliderStyle(juce::Slider::LinearVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
    gainSlider.setTextValueSuffix(" dB");
    gainSlider.setRange(-48.0, 0.0);
    gainSlider.setValue(-5.0);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
}

GainTestAudioProcessorEditor::~GainTestAudioProcessorEditor()
{
}

//==============================================================================
void GainTestAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

}

void GainTestAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getLocalBounds());
}

void GainTestAudioProcessorEditor::sliderValueChanged (juce::Slider *slider)
{
    if (slider == &gainSlider)
    {
        audioProcessor.gainValue = gainSlider.getValue();
    }
}