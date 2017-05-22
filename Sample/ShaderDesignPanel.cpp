#include "ShaderDesignPanel.h"
#include <algorithm>

using namespace Crystal::UI;

static inline ImVec2 operator+(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x + rhs.x, lhs.y + rhs.y); }
static inline ImVec2 operator-(const ImVec2& lhs, const ImVec2& rhs) { return ImVec2(lhs.x - rhs.x, lhs.y - rhs.y); }

void ShaderDesignPanel::show()
{
	bool opened =false;
	ImGui::SetNextWindowSize(ImVec2(700, 600), ImGuiSetCond_FirstUseEver);
	if (!ImGui::Begin("Example: Custom Node Graph", &opened, ImGuiWindowFlags_MenuBar)) {
		ImGui::End();
		return;
	}
	if (!inited) {
		auto smoothingNode = new ShaderNode(0, "Smoothing", ImVec2(40, 50));
		auto depthNode = new ShaderNode(1, "Depth", ImVec2(40, 150));
		auto thicknessNode = new ShaderNode(2, "Thickness", ImVec2(270, 80));
		smoothingNode->build();
		nodes.push_back(smoothingNode);
		nodes.push_back(depthNode);
		nodes.push_back(thicknessNode);
		auto slot1 = smoothingNode->createOutputSlot();
		auto slot2 = depthNode->createInputSlot("");
		auto slot3 = thicknessNode->createInputSlot("");
		links.push_back(ShaderLink(slot1, slot2));
		links.push_back(ShaderLink(slot1, slot3));
		inited = true;
	}

	ImGui::BeginMenuBar();
	if (ImGui::BeginMenu("File")) {
		//if (ImGui::MenuItem("Close")) *p_open = false;
		if (ImGui::MenuItem("Open")) {
			;
		}
		if (ImGui::MenuItem("Save")) {
			std::stringstream ss;
			{
				cereal::JSONOutputArchive o_archive(ss);
				for (auto n : nodes) {
					o_archive(*n);
				}
			}
			std::cout << ss.str() << std::endl;
		}
		ImGui::EndMenu();
		if (ImGui::MenuItem("SaveAs")) {
			;
		}
	}
	ImGui::EndMenuBar();

	// Draw a list of nodes on the left side
	bool open_context_menu = false;
	ShaderNode* hoveredNodeInList = nullptr;
	ShaderNode* hoveredNodeInScene = nullptr;
	ImGui::BeginChild("node_list", ImVec2(100, 0));
	ImGui::Text("Nodes");
	ImGui::Separator();
	for (auto node : nodes) {
		ImGui::PushID(node->id);
		if (ImGui::Selectable(node->name.c_str(), node == selectedNode)) {
			selectedNode = node;
		}
		if (ImGui::IsItemHovered()) {
			hoveredNodeInList = node;
			open_context_menu |= ImGui::IsMouseClicked(1);
		}
		ImGui::PopID();
	}
	ImGui::EndChild();

	ImGui::SameLine();
	ImGui::BeginGroup();

	const float NODE_SLOT_RADIUS = 4.0f;
	const ImVec2 NODE_WINDOW_PADDING(8.0f, 8.0f);

	// Create our child canvas
	ImGui::Text("Hold middle mouse button to scroll (%.2f,%.2f)", scrolling.x, scrolling.y);
	ImGui::SameLine(ImGui::GetWindowWidth() - 100);
	ImGui::Checkbox("Show grid", &show_grid);
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(1, 1));
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
	ImGui::PushStyleColor(ImGuiCol_ChildWindowBg, ImColor(60, 60, 70, 200));
	ImGui::BeginChild("scrolling_region", ImVec2(0, 0), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoMove);
	ImGui::PushItemWidth(120.0f);

	ImVec2 offset = ImGui::GetCursorScreenPos() - scrolling;
	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	draw_list->ChannelsSplit(2);

	// Display grid
	if (show_grid) {
		ImU32 GRID_COLOR = ImColor(200, 200, 200, 40);
		float GRID_SZ = 64.0f;
		ImVec2 win_pos = ImGui::GetCursorScreenPos();
		ImVec2 canvas_sz = ImGui::GetWindowSize();
		for (float x = fmodf(offset.x, GRID_SZ); x < canvas_sz.x; x += GRID_SZ) {
			draw_list->AddLine(ImVec2(x, 0.0f) + win_pos, ImVec2(x, canvas_sz.y) + win_pos, GRID_COLOR);
		}
		for (float y = fmodf(offset.y, GRID_SZ); y < canvas_sz.y; y += GRID_SZ) {
			draw_list->AddLine(ImVec2(0.0f, y) + win_pos, ImVec2(canvas_sz.x, y) + win_pos, GRID_COLOR);
		}
	}

	// Display links
	draw_list->ChannelsSetCurrent(0); // Background
	for (auto link : links) {
		auto p1 = offset + link.in->getPosition();
		auto p2 = offset + link.out->getPosition();
		draw_list->AddBezierCurve(p1, p1 + ImVec2(+50, 0), p2 + ImVec2(-50, 0), p2, ImColor(200, 200, 100), 3.0f);
	}

	// Display nodes
	for (auto node : nodes) {
		ImGui::PushID(node->id);
		ImVec2 node_rect_min = offset + node->pos;

		// Display node contents first
		draw_list->ChannelsSetCurrent(1); // Foreground
		bool old_any_active = ImGui::IsAnyItemActive();
		ImGui::SetCursorScreenPos(node_rect_min + NODE_WINDOW_PADDING);
		ImGui::BeginGroup(); // Lock horizontal position
		ImGui::Text("%s", node->name.c_str());
		static bool showShaderSource = false;
		if (ImGui::Button("ShaderSource")) {
			showShaderSource = true;
		}
		if(showShaderSource) {
			ImGui::SetNextWindowSize(ImVec2(500, 500), ImGuiSetCond_FirstUseEver);

			ImGui::Begin("ShaderSource", &showShaderSource);
			char str[256];
			ImGui::InputTextMultiline("VertexShader", str, 256);
			ImGui::InputTextMultiline("FragmentShader", str, 256);

			ImGui::End();
		}
		ImGui::EndGroup();

		// Save the size of what we have emitted and whether any of the widgets are being used
		bool node_widgets_active = (!old_any_active && ImGui::IsAnyItemActive());
		node->size = ImGui::GetItemRectSize() + NODE_WINDOW_PADDING + NODE_WINDOW_PADDING;
		ImVec2 node_rect_max = node_rect_min + node->size;

		// Display node box
		draw_list->ChannelsSetCurrent(0); // Background
		ImGui::SetCursorScreenPos(node_rect_min);
		ImGui::InvisibleButton("node", node->size);
		if (ImGui::IsItemHovered()) {
			hoveredNodeInScene = node;
			open_context_menu |= ImGui::IsMouseClicked(1);
		}
		bool node_moving_active = ImGui::IsItemActive();
		if (node_widgets_active || node_moving_active) {
			selectedNode = node;
		}
		if (node_moving_active && ImGui::IsMouseDragging(0)) {
			node->pos = node->pos + ImGui::GetIO().MouseDelta;
		}

		ImU32 node_bg_color = (hoveredNodeInList == node || hoveredNodeInScene == node || (hoveredNodeInList == nullptr && selectedNode == node)) ? ImColor(75, 75, 75) : ImColor(60, 60, 60);
		draw_list->AddRectFilled(node_rect_min, node_rect_max, node_bg_color, 4.0f);
		draw_list->AddRect(node_rect_min, node_rect_max, ImColor(100, 100, 100), 4.0f);
		for (auto slot : node->inputSlots) {
			draw_list->AddCircleFilled(offset + slot->getPosition(), NODE_SLOT_RADIUS, ImColor(150, 150, 150, 150));
		}
		for (auto slot : node->outputSlots) {
			draw_list->AddCircleFilled(offset + slot->getPosition() , NODE_SLOT_RADIUS, ImColor(150, 150, 150, 150));
		}

		ImGui::PopID();
	}
	draw_list->ChannelsMerge();

	// Open context menu
	if (!ImGui::IsAnyItemHovered() && ImGui::IsMouseHoveringWindow() && ImGui::IsMouseClicked(1)) {
		selectedNode = nullptr;
		hoveredNodeInList = nullptr;
		hoveredNodeInScene = nullptr;
		open_context_menu = true;
	}
	if (open_context_menu) {
		ImGui::OpenPopup("context_menu");
		if (hoveredNodeInList) {
			selectedNode = hoveredNodeInList;
		}
		if (hoveredNodeInScene) {
			selectedNode = hoveredNodeInScene;
		}
	}

	// Draw context menu
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8, 8));
	if (ImGui::BeginPopup("context_menu")) {
		auto node = selectedNode;
		ImVec2 scene_pos = ImGui::GetMousePosOnOpeningCurrentPopup() - offset;
		if (node) {
			ImGui::Text("Node '%s'", node->name.c_str());
			ImGui::Separator();
			if (ImGui::MenuItem("Rename..", NULL, false)) {
				/*

				static char str[256];
				ImGui::BeginPopup("NewName");
				if (ImGui::InputText("Name", str, 256)) {
					selectedNode->setName(str);
				}
				ImGui::EndPopup();
				*/
			}
			if (ImGui::MenuItem("Delete", NULL, false)) {
				nodes.erase(std::remove(nodes.begin(), nodes.end(), node), nodes.end());
				delete node;
			}
			if (ImGui::MenuItem("Copy", NULL, false, false)) {}
		}
		else {
			if (ImGui::MenuItem("Add")) {
				nodes.push_back(new ShaderNode(nodes.size(), "New node", scene_pos));
			}
			if (ImGui::MenuItem("Paste", NULL, false, false)) {
				;
			}
		}
		ImGui::EndPopup();
	}
	ImGui::PopStyleVar();

	// Scrolling
	if (ImGui::IsWindowHovered() && !ImGui::IsAnyItemActive() && ImGui::IsMouseDragging(2, 0.0f)) {
		scrolling = scrolling - ImGui::GetIO().MouseDelta;
	}

	ImGui::PopItemWidth();
	ImGui::EndChild();
	ImGui::PopStyleColor();
	ImGui::PopStyleVar(2);
	ImGui::EndGroup();

	ImGui::End();
}