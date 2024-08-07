#include "ElementBuffer.hpp"

template<typename T>
inline void Bebr::GL::ElementBuffer::BufferData(T* data, Size_t size, DataUsage usage)
{}

template<>
void Bebr::GL::ElementBuffer::BufferData<std::uint8_t>(std::uint8_t* data, Size_t size, DataUsage usage);
template<>
void Bebr::GL::ElementBuffer::BufferData<std::uint16_t>(std::uint16_t* data, Size_t size, DataUsage usage);
template<>
void Bebr::GL::ElementBuffer::BufferData<std::uint32_t>(std::uint32_t* data, Size_t size, DataUsage usage);

template<typename T>
inline void Bebr::GL::ElementBuffer::BufferSubData(T* data, Size_t size, Size_t offset)
{}

template<>
void Bebr::GL::ElementBuffer::BufferSubData<std::uint8_t>(std::uint8_t* data, Size_t size, Size_t start);
template<>
void Bebr::GL::ElementBuffer::BufferSubData<std::uint16_t>(std::uint16_t* data, Size_t size, Size_t start);
template<>
void Bebr::GL::ElementBuffer::BufferSubData<std::uint32_t>(std::uint32_t* data, Size_t size, Size_t start);
