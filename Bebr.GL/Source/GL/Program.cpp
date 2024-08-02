#include "Program.hpp"
#include <System/Log.hpp>
#include <GL/glew.h>
#include <fstream>
#include <sstream>

static class Shader : public Bebr::GL::Resource
{
public:
    Shader(const char* path, unsigned int type);
    ~Shader();

private:
    void ReadFile(const char* path);
    void Compile(unsigned int type);

private:
    std::string m_code;
};

Shader::Shader(const char* path, unsigned int type) : Resource()
{
    ReadFile(path);
    Compile(type);
}

Shader::~Shader()
{
    glDeleteShader(m_id);
}

void Shader::ReadFile(const char* path)
{
    std::ifstream file;
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        file.open(path);
        std::stringstream stream;
        stream << file.rdbuf();
        file.close();
        m_code = stream.str();
    }
    catch (std::ifstream::failure& e) {}
}

void Shader::Compile(unsigned int type)
{
    m_id = glCreateShader(type);
    const char* source = m_code.c_str();
    glShaderSource(m_id, 1, &source, nullptr);
    glCompileShader(m_id);

    int success;
    char infoLog[512];
    glGetShaderiv(m_id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(m_id, 512, nullptr, infoLog);
        Bebr::System::Logln(infoLog);
    }
}

Bebr::GL::Program::Program(const std::string& vertexShaderPath,
                           const std::string& fragmentShaderPath) : Resource(glCreateProgram())
{
    Shader vertexShader(vertexShaderPath.c_str(), GL_VERTEX_SHADER);
    Shader fragmentShader(fragmentShaderPath.c_str(), GL_FRAGMENT_SHADER);
    LinkProgram(vertexShader.GetID(), fragmentShader.GetID());
}

void Bebr::GL::Program::Activate()
{
    glUseProgram(m_id);
}

void Bebr::GL::Program::Deactivate()
{
    glUseProgram(0);
}

void Bebr::GL::Program::LinkProgram(unsigned int vertexShader, unsigned int fragmentShader)
{
    glAttachShader(m_id, vertexShader);
    glAttachShader(m_id, fragmentShader);
    glLinkProgram(m_id);

    int success;
    char infoLog[512];
    glGetProgramiv(m_id, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(m_id, 512, nullptr, infoLog);
    }
}
