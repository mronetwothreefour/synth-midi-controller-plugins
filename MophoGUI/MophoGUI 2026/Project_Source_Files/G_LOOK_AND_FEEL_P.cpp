#include "G_LOOK_AND_FEEL_P.h"

#include "G_DRAW_Paths_Osc_Shape_P.h"
#include "G_DRAW_Paths_Widgets_P.h"

using Draw_Shape = Draw_Paths_Osc_Shape_P;
using Draw_Widget = Draw_Paths_Widgets_P;

Look_And_Feel_P::Look_And_Feel_P(float& scale_factor) :
	Look_And_Feel_B{ scale_factor }
{}

void Look_And_Feel_P::draw_label_p(Graphics& g, Label& lbl, String& id) {
	auto txt = lbl.getText();
	g.setColour(COLOR::text.withAlpha(lbl.isBeingEdited() ? 0.0f : 1.0f));
	if (id == ID::label_osc_shape.toString()) {
		if (txt == "SAW") {
			Draw_Shape::sawtooth(g, scale_factor);
			return;
		}
		if (txt == "TRI") {
			Draw_Shape::triangle(g, scale_factor);
			return;
		}
		if (txt == "S/T") {
			Draw_Shape::saw_tri(g, scale_factor);
			return;
		}
		if (txt == "SQR" || txt.startsWith("PW ")) {
			auto w = 50;
			if (txt.startsWith("PW "))
				w = txt.fromFirstOccurrenceOf("PW ", false, false).getIntValue();
			Draw_Shape::pulse(g, w, scale_factor);
			g.setFont(FONT::pulse_w_txt(scale_factor));
			auto txt_area = Rectangle<int>{ 10, 23, 18, 11 }.transformedBy(AffineTransform::scale(scale_factor));
			g.drawText((String)(w), txt_area, Justification::centred);
			return;
		}
		g.setFont(FONT::knob(scale_factor));
		g.drawFittedText(txt == "OFF" ? txt : "ERR", lbl.getLocalBounds().translated(0, 1), Justification::centred, 1, 1.0f);
	}
	if (id == ID::label_seq_step.toString()) {
		auto sf = scale_factor;
		if (txt == "<") {
			Line<float> l{ 20.0f, 13.0f, 5.0f, 13.0f };
			l.applyTransform(AffineTransform::scale(sf));
			g.drawArrow(l, 5.0f * sf, 10.0f * sf, 8.0f * sf);
			return;
		}
		if (txt == ".") {
			g.fillEllipse(10.0f * sf, 10.0f * sf, 6.0f * sf, 6.0f * sf);
			return;
		}
		g.setFont(FONT::seq_step(scale_factor));
		g.drawFittedText(txt, lbl.getLocalBounds().translated(0, 1), Justification::centred, 1, 1.0f);
	}
}

void Look_And_Feel_P::drawRotarySlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/, float pos,
									   const float min_angle, const float max_angle, Slider& s)
{
	if (s.getComponentID() == ID::knob_seq_step.toString() ||
		s.getComponentID() == ID::knob_seq_step_track_1.toString())
		return;
	auto rotation = min_angle + pos * (max_angle - min_angle);
	Draw_Widget::knob(g, rotation, scale_factor);
}
