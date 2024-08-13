#pragma once
#include <string>

namespace Bebr
{
namespace GUI
{
class DragDrop
{
public:
	DragDrop() = delete;

public:
	enum class Flag
	{
		None						= 0,
		SourceNoPreviewTooltip		= 1 << 0,
		SourceNoDisableHover		= 1 << 1,
		SourceNoHoldToOpenOthers	= 1 << 2,
		SourceAllowNullID			= 1 << 3,
		SourceExtern				= 1 << 4,
		PayloadAutoExpire			= 1 << 5,
		PayloadNoCrossContext		= 1 << 6,
		PayloadNoCrossProcess		= 1 << 7,
		AcceptBeforeDelivery		= 1 << 10,
		AcceptNoDrawDefaultRect		= 1 << 11,
		AcceptNoPreviewTooltip		= 1 << 12,
	};

	class Source
	{
	public:
		Source();
		Source(const Source&)	= default;
		~Source()				= default;

	public:
		bool Begin();
		void End();
		template<typename T>
		void SetPayload(const char* tag, const T& data);
		void SetPayload(const char* tag, const void* data, std::size_t size);

		void AddFlag(Flag flag);
		void RemoveFlag(Flag flag);

	private:
		std::int32_t m_flags;
	};

	class Target
	{
	public:
		Target();
		Target(const Target&) = default;
		~Target() = default;

	public:
		bool Begin();
		void End();

		template<typename T>
		T		AcceptPayload(const char* tag);
		void*	AcceptPayload(const char* tag);

		void AddFlag(Flag flag);
		void RemoveFlag(Flag flag);

	private:
		std::int32_t m_flags;
	};
};
}
}

template<typename T>
inline void Bebr::GUI::DragDrop::Source::SetPayload(const char* tag, const T& data)
{
	SetPayload(tag, &data, sizeof(T));
}

template<typename T>
inline T Bebr::GUI::DragDrop::Target::AcceptPayload(const char* tag)
{
	if (void* data = AcceptPayload(tag))
	{
		return *reinterpret_cast<T*>(data);
	}
	return nullptr;
}
