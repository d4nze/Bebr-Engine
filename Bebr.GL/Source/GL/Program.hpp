#pragma once
#include <string>
#include "Resource.hpp"

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

private:
    void LinkProgram(unsigned int vertexShader, unsigned int fragmentShader);
};
}
}
