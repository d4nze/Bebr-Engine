#pragma once
#include <string>

namespace Bebr
{
namespace GL
{
class Program
{
public:
    Program(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    Program(const Program&) = default;
    ~Program() = default;

public:
    void Use();
    unsigned int GetID() const;

private:
    void LinkProgram(unsigned int vertexShader, unsigned int fragmentShader);

private:
    unsigned int m_id;
};
}
}
