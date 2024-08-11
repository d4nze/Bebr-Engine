#pragma once
#include <System/Vector2.hpp>
#include <string>

struct GLFWwindow;

namespace Bebr
{
namespace Window
{
class BasicWindow
{
public:
	BasicWindow(const std::string& title);
	BasicWindow(int width, int height, const std::string& title);
	BasicWindow(const System::Vector2I_t& size, const std::string& title);
	~BasicWindow();
	BasicWindow(const BasicWindow&) = delete;

public:
	void MakeCurrentContext();
	void SwapBuffers();
	bool IsOpen() const;
	void Close();

	void SetTitle(const std::string& title);
	void SetPosition(int x, int y);
	void SetPosition(const System::Vector2I_t& position);
	void SetSize(int width, int height);
	void SetSize(const System::Vector2I_t& size);

	const std::string& GetTitle() const;
	const System::Vector2I_t& GetPosition() const;
	const System::Vector2I_t& GetSize() const;

private:
	void InitializeCallbacks();

private:
	GLFWwindow* m_handler;
	std::string m_title;
	System::Vector2I_t m_position;
	System::Vector2I_t m_size;

	friend class Keyboard;
	friend class Mouse;
};
}
}
