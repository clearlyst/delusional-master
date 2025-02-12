#include <numeric>
#include "structures.hpp"
#include "../../sdk/math/vec3.hpp"

using namespace drawing;

void Line::draw(ImDrawList* draw) const {
	draw->AddLine(m_start, m_end, m_color, m_thickness);
}

void Rectangle::draw(ImDrawList* draw) const {
	draw->AddRect(m_min, m_max, m_color, m_rounding, m_flags, m_thickness);
}

void RectangleFilled::draw(ImDrawList* draw) const {
	draw->AddRectFilled(m_min, m_max, m_color, m_rounding, m_flags);
}

void RectangleGradient::draw(ImDrawList* draw) const {
	if (!m_horizontal)
		draw->AddRectFilledMultiColor(m_min, m_max, m_color1, m_color2, m_color2, m_color1);
	else
		draw->AddRectFilledMultiColor(m_min, m_max, m_color1, m_color1, m_color2, m_color2);
}

void RectangleMultiColor::draw(ImDrawList* draw) const {
	draw->AddRectFilledMultiColor(m_min, m_max, m_color1, m_color2, m_color3, m_color4);
}

void Circle::draw(ImDrawList* draw) const {
	draw->AddCircle(m_centre, m_radius, m_color, m_segments, m_thickness);
}

void CircleFilled::draw(ImDrawList* draw) const {
	draw->AddCircleFilled(m_centre, m_radius, m_color, m_segments);
}

void Triangle::draw(ImDrawList* draw) const {
	draw->AddTriangle(m_p1, m_p2, m_p3, m_color, m_thickness);
}

void TriangleFilled::draw(ImDrawList* draw) const {
	draw->AddTriangleFilled(m_p1, m_p2, m_p3, m_color);
}

void Quad::draw(ImDrawList* draw) const {
	draw->AddQuad(m_p1, m_p2, m_p3, m_p4, m_color, m_thickness);
}

void QuadFilled::draw(ImDrawList* draw) const {
	draw->AddQuadFilled(m_p1, m_p2, m_p3, m_p4, m_color);
}

void QuadMultiColor::draw(ImDrawList* draw) const {
	//draw->AddQuadFilledMultiColor(m_p1, m_p2, m_p3, m_p4, m_color1, m_color2, m_color3, m_color4);
}

void Polyline::draw(ImDrawList* draw) const {
	draw->AddPolyline(m_verts.data(), m_verts.size(), m_color, m_flags, m_thickness);
}

void Polygon::draw(ImDrawList* draw) const {
	draw->AddConvexPolyFilled(m_verts.data(), m_verts.size(), m_color);
}

void PolygonMultiColor::draw(ImDrawList* draw) const {
	//draw->AddConvexPolyFilledMultiColor(m_verts.data(), m_colors.data(), m_verts.size());
}

void Text::draw(ImDrawList* draw) const {
	ImGui::PushFont(m_font);
	ImVec2 pos = m_pos;

	if (auto tsize = ImGui::CalcTextSize(m_text.c_str()); m_centred)
		pos.x -= tsize.x / 2.0f;

	if (m_dropShadow) {
		const auto alpha = ImGui::ColorConvertU32ToFloat4(m_color).w;
		draw->AddText({ pos.x + 1.0f, pos.y + 1.0f }, color_t::U32(clrs::Black.get_color_edit_alpha(alpha)), m_text.c_str());
	}

	if (m_outline) {
		const auto alpha = ImGui::ColorConvertU32ToFloat4(m_color).w;
		draw->AddText({ pos.x + 1.0f, pos.y + 1.0f }, color_t::U32(clrs::Black.get_color_edit_alpha(alpha)), m_text.c_str());
		draw->AddText({ pos.x - 1.0f, pos.y - 1.0f }, color_t::U32(clrs::Black.get_color_edit_alpha(alpha)), m_text.c_str());
		draw->AddText({ pos.x + 1.0f, pos.y - 1.0f }, color_t::U32(clrs::Black.get_color_edit_alpha(alpha)), m_text.c_str());
		draw->AddText({ pos.x - 1.0f, pos.y + 1.0f }, color_t::U32(clrs::Black.get_color_edit_alpha(alpha)), m_text.c_str());
	}

	draw->AddText(pos, m_color, m_text.c_str());

	ImGui::PopFont();
}

void TextSize::draw(ImDrawList* draw) const {
	ImGui::PushFont(m_font);
	ImVec2 pos = m_pos;

	if (auto tsize = m_font->CalcTextSizeA(m_size, FLT_MAX, 0.0f, m_text.c_str()); m_centred)
		pos.x -= tsize.x / 2.0f;


	if (m_dropShadow) {
		const auto alpha = ImGui::ColorConvertU32ToFloat4(m_color).w;
		draw->AddText(m_font, m_size, { pos.x + 1.0f, pos.y + 1.0f }, color_t::U32(clrs::Black.get_color_edit_alpha(alpha)), m_text.c_str());
	}

	if (m_outline) {
		const auto alpha = ImGui::ColorConvertU32ToFloat4(m_color).w;
		draw->AddText({ pos.x + 1.0f, pos.y + 1.0f }, color_t::U32(clrs::Black.get_color_edit_alpha(alpha)), m_text.c_str());
		draw->AddText({ pos.x - 1.0f, pos.y - 1.0f }, color_t::U32(clrs::Black.get_color_edit_alpha(alpha)), m_text.c_str());
		draw->AddText({ pos.x + 1.0f, pos.y - 1.0f }, color_t::U32(clrs::Black.get_color_edit_alpha(alpha)), m_text.c_str());
		draw->AddText({ pos.x - 1.0f, pos.y + 1.0f }, color_t::U32(clrs::Black.get_color_edit_alpha(alpha)), m_text.c_str());
	}

	draw->AddText(m_font, m_size, pos, m_color, m_text.c_str());

	ImGui::PopFont();
}

void Arc::draw(ImDrawList* draw) const {
	draw->PathArcTo(m_centre, m_radius, m_aMin, m_aMax, m_segments);
	draw->PathStroke(m_color, m_flags, m_thickness);
}