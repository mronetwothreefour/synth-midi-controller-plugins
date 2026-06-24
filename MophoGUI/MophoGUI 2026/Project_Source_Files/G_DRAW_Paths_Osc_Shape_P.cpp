#include "G_DRAW_Paths_Osc_Shape_P.h"

PathStrokeType Draw_Paths_Osc_Shape_P::stroke() {
	return { 1.0f, PathStrokeType::mitered, PathStrokeType::rounded };
}

void Draw_Paths_Osc_Shape_P::pulse(Graphics& g, const int w, float& scale_factor) {
	Path p;
	auto crossover_x{ x() + 1.0f + (18.0f * (w * .01f))};
	p.addLineSegment({ x() + 1.0f, y() + 9.0f, x() + 1.0f, y() }, 0.5f);
	p.addLineSegment({ x() + 1.0f, y(), crossover_x, y() }, 0.5f);
	p.addLineSegment({ crossover_x, y(), crossover_x, y() + 9.0f }, 0.5f);
	p.addLineSegment({ crossover_x, y() + 9.0f, x() + 19.0f, y() + 9.0f}, 0.5f);
	p.applyTransform(AffineTransform::scale(scale_factor));
	g.strokePath(p, stroke());
}

void Draw_Paths_Osc_Shape_P::sawtooth(Graphics& g, float& scale_factor) {
	Path p;
	p.addLineSegment({ x() + 1.0f, y() + 12.0f, x() + 16.0f, y() }, 0.5f);
	p.addLineSegment({ x() + 16.0f, y(), x() + 16.0f, y() + 12.0f }, 0.5f);
	p.applyTransform(AffineTransform::scale(scale_factor));
	g.strokePath(p, stroke());
}

void Draw_Paths_Osc_Shape_P::triangle(Graphics& g, float& scale_factor) {
	Path p;
	p.addLineSegment({ x() + 2.0f, y() + 12.0f, x() + 10.0f, y() + 1.0f }, 0.5f);
	p.addLineSegment({ x() + 10.0f, y() + 1.0f, x() + 18.0f, y() + 12.0f }, 0.5f);
	p.applyTransform(AffineTransform::scale(scale_factor));
	g.strokePath(p, stroke());
}

void Draw_Paths_Osc_Shape_P::saw_tri(Graphics& g, float& scale_factor) {
	Path p;
	p.addLineSegment({ x(), y() + 7.0f, x() + 5.0f, y() }, 0.5f);
	p.addLineSegment({ x() + 5.0f, y(), x() + 10.0f, y() + 7.0f }, 0.5f);
	p.addLineSegment({ x() + 10.0f, y() + 7.0f, x() + 10.0f, y() + 15.0f }, 0.5f);
	p.addLineSegment({ x() + 10.0f, y() + 15.0f, x() + 20.0f, y() + 7.0f }, 0.5f);
	p.applyTransform(AffineTransform::scale(scale_factor));
	g.strokePath(p, stroke());
}
