#pragma once

#include "D_X_G_Data_User_P.h"

class Envelope_G :
	public Component,
	public Data_User_P,
	public Value::Listener
{
protected: RangedAudioParameter* param_delay;
protected: RangedAudioParameter* param_attack;
protected: RangedAudioParameter* param_decay;
protected: RangedAudioParameter* param_sustain;
protected: RangedAudioParameter* param_release;
protected: Value val_delay;
protected: Value val_attack;
protected: Value val_decay;
protected: Value val_sustain;
protected: Value val_release;
protected: Rectangle<int> init_bounds;
protected: float delay_w;
protected: float attack_w;
protected: float decay_w;
protected: float sustain_h;
protected: float release_w;

//==============================================================================
public: explicit Envelope_G(Data_Hub_P* hub);

public: void paint(Graphics& g) override;
public: void valueChanged(Value& value) override;
public: ~Envelope_G();

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Envelope_G)
};