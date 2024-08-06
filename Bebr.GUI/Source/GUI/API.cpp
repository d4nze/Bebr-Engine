#include "API.hpp"
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <GL/glew.h>
#include <glfw3.h>

bool Bebr::GUI::API::InitializeMain()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	return true;
}

bool Bebr::GUI::API::InitializeBackend()
{
	if (!ImGui_ImplGlfw_InitForOpenGL(glfwGetCurrentContext(), true))
	{
		return false;
	}
	if (!ImGui_ImplOpenGL3_Init("#version 330 core"))
	{
		return false;
	}
	return true;
}

void Bebr::GUI::API::CreateFrame()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Bebr::GUI::API::Render()
{
	ImGui::Render();

	GLFWwindow* backup_current_context = glfwGetCurrentContext();
	ImGui::UpdatePlatformWindows();
	ImGui::RenderPlatformWindowsDefault();
	if (backup_current_context != glfwGetCurrentContext())
	{
		glfwMakeContextCurrent(backup_current_context);
	}

	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Bebr::GUI::API::DockspaceOverViewport()
{
	ImGui::DockSpaceOverViewport(0, ImGui::GetMainViewport());
}

void Bebr::GUI::API::DemoWindow()
{
	ImGui::ShowDemoWindow();
}
