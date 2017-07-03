#include "ShaderDesignPanel.h"
#include "CameraNode.h"
#include "ImGuiExt.h"
#include <algorithm>
#include <fstream>

#include "../ThirdParty/nativefiledialog/src/include/nfd.h"

using namespace Crystal::UI;


namespace {
	std::string getStrFromFile(const std::string& file)
	{
		std::ifstream stream(file);
		if (stream.fail()) {
			assert(false);
			return "";
		}
		std::istreambuf_iterator<char> it(stream);
		std::istreambuf_iterator<char> last;
		return std::string(it, last);
	}
}


void ShaderDesignPanel::show()
{
	bool opened =false;
	ImGui::SetNextWindowSize(ImVec2(700, 600), ImGuiSetCond_FirstUseEver);
	if (!ImGui::Begin("Example: Custom Node Graph", &opened, ImGuiWindowFlags_MenuBar)) {
		ImGui::End();
		return;
	}
	if (!inited) {
		model.build();
		inited = true;
	}

	ImGui::BeginMenuBar();
	if (ImGui::BeginMenu("File")) {
		//if (ImGui::MenuItem("Close")) *p_open = false;
		if (ImGui::MenuItem("Open")) {
			nfdchar_t *outPath = NULL;
			std::string filter = "cgs";
			nfdresult_t result = NFD_OpenDialog(filter.data(), NULL, &outPath);

			if (result == NFD_OKAY) {
				puts("Success!");
				puts(outPath);
				//model.save(outPath);
				free(outPath);
			}
			else if (result == NFD_CANCEL) {
				puts("User pressed cancel.");
			}
			else {
				printf("Error: %s\n", NFD_GetError());
			}
		}
		if (ImGui::MenuItem("Save")) {
			//model.save();
		}
		if (ImGui::MenuItem("SaveAs")) {
			nfdchar_t *outPath = NULL;
			std::string filter = "cgs";
			nfdresult_t result = NFD_SaveDialog(filter.data(), NULL, &outPath);

			if (result == NFD_OKAY) {
				puts(outPath);
				model.save(outPath);
				free(outPath);
			}
		}
		ImGui::EndMenu();
	}
	ImGui::EndMenuBar();


	// Draw a list of nodes on the left side
	bool open_context_menu = false;
	ShaderNode* hoveredNodeInScene = nullptr;

	ImGui::SameLine();
	ImGui::BeginGroup();


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
	/*
	for (auto link : links) {
		auto p1 = offset + link.in->getPosition();
		auto p2 = offset + link.out->getPosition();
		draw_list->AddBezierCurve(p1, p1 + ImVec2(+50, 0), p2 + ImVec2(-50, 0), p2, ImColor(200, 200, 100), 3.0f);
	}
	*/
	model.draw(draw_list, offset);

	// Open context menu
	if (!ImGui::IsAnyItemHovered() && ImGui::IsMouseHoveringWindow() && ImGui::IsMouseClicked(1)) {
		selectedNode = nullptr;
		hoveredNodeInScene = nullptr;
		open_context_menu = true;
	}
	if (open_context_menu) {
		ImGui::OpenPopup("context_menu");
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
			ImGui::Text("Node '%s'", node->getName().c_str());
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
				/*
				model.remove();
				nodes.erase(std::remove(nodes.begin(), nodes.end(), node), nodes.end());
				delete node;
				*/
			}
			if (ImGui::MenuItem("Copy", NULL, false, false)) {}
		}
		else {
			if (ImGui::MenuItem("Add")) {
				//nodes.push_back(new ShaderNode(nodes.size(), "New node", scene_pos));
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