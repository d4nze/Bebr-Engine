#pragma once
#include "Resource.hpp"
#include <string>
#include <System/Vector2.hpp>
#include <System/Vector3.hpp>
#include <System/Matrix.hpp>

namespace Bebr
{
namespace GL
{
class Program : public Resource
{
public:
    Program(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    Program(const Program&) = default;
    ~Program() = default;

public:
    void Activate();
    void Deactivate();

    void SetUniform(const std::string& name, float value);
    void SetUniform(const std::string& name, std::int32_t value);
    void SetUniform(const std::string& name, std::uint32_t value);

    void SetUniform(const std::string& name, float x, float y);
    void SetUniform(const std::string& name, std::int32_t x, std::int32_t y);
    void SetUniform(const std::string& name, std::uint32_t x, std::uint32_t y);
    void SetUniform(const std::string& name, const System::Vector2F_t& value);
    void SetUniform(const std::string& name, const System::Vector2I_t& value);
    void SetUniform(const std::string& name, const System::Vector2U_t& value);

    void SetUniform(const std::string& name, float x, float y, float z);
    void SetUniform(const std::string& name, std::int32_t x, std::int32_t y, std::int32_t z);
    void SetUniform(const std::string& name, std::uint32_t x, std::uint32_t y, std::uint32_t z);
    void SetUniform(const std::string& name, const System::Vector3F_t& value);
    void SetUniform(const std::string& name, const System::Vector3I_t& value);
    void SetUniform(const std::string& name, const System::Vector3U_t& value);

    void SetUniform(const std::string& name, float x, float y, float z, float w);
    void SetUniform(const std::string& name, std::int32_t x, std::int32_t y, std::int32_t z, std::int32_t w);
    void SetUniform(const std::string& name, std::uint32_t x, std::uint32_t y, std::uint32_t z, std::uint32_t w);

    void SetUniform(const std::string& name, const System::Matrix2_t<float>& matrix);
    void SetUniform(const std::string& name, const System::Matrix2x3_t<float>& matrix);
    void SetUniform(const std::string& name, const System::Matrix2x4_t<float>& matrix);
    void SetUniform(const std::string& name, const System::Matrix2_t<double>& matrix);
    void SetUniform(const std::string& name, const System::Matrix2x3_t<double>& matrix);
    void SetUniform(const std::string& name, const System::Matrix2x4_t<double>& matrix);

    void SetUniform(const std::string& name, const System::Matrix3_t<float>& matrix);
    void SetUniform(const std::string& name, const System::Matrix3x2_t<float>& matrix);
    void SetUniform(const std::string& name, const System::Matrix3x4_t<float>& matrix);
    void SetUniform(const std::string& name, const System::Matrix3_t<double>& matrix);
    void SetUniform(const std::string& name, const System::Matrix3x2_t<double>& matrix);
    void SetUniform(const std::string& name, const System::Matrix3x4_t<double>& matrix);

    void SetUniform(const std::string& name, const System::Matrix4_t<float>& matrix);
    void SetUniform(const std::string& name, const System::Matrix4x2_t<float>& matrix);
    void SetUniform(const std::string& name, const System::Matrix4x3_t<float>& matrix);
    void SetUniform(const std::string& name, const System::Matrix4_t<double>& matrix);
    void SetUniform(const std::string& name, const System::Matrix4x2_t<double>& matrix);
    void SetUniform(const std::string& name, const System::Matrix4x3_t<double>& matrix);

private:
    void LinkProgram(unsigned int vertexShader, unsigned int fragmentShader);
    std::int32_t GetUniformLocation(const std::string& name) const;
};
}
}
