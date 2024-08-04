#include "Program.hpp"
#include <System/Log.hpp>
#include <GL/glew.h>
#include <fstream>
#include <sstream>

class Shader : public Bebr::GL::Resource
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
    catch (std::ifstream::failure&) {}
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
    #ifdef DEBUG
    glUseProgram(0);
    #endif
}

void Bebr::GL::Program::SetUniform(const std::string& name, float value)
{
    glUniform1f(GetUniformLocation(name), value);
}

void Bebr::GL::Program::SetUniform(const std::string& name, std::int32_t value)
{
    glUniform1i(GetUniformLocation(name), value);
}

void Bebr::GL::Program::SetUniform(const std::string& name, std::uint32_t value)
{
    glUniform1ui(GetUniformLocation(name), value);
}

void Bebr::GL::Program::SetUniform(const std::string& name, float x, float y)
{
    glUniform2f(GetUniformLocation(name), x, y);
}

void Bebr::GL::Program::SetUniform(const std::string& name, std::int32_t x, std::int32_t y)
{
    glUniform2i(GetUniformLocation(name), x, y);
}

void Bebr::GL::Program::SetUniform(const std::string& name, std::uint32_t x, std::uint32_t y)
{
    glUniform2ui(GetUniformLocation(name), x, y);
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Vector2F_t& value)
{
    glUniform2f(GetUniformLocation(name), value.x, value.y);
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Vector2I_t & value)
{
    glUniform2i(GetUniformLocation(name), value.x, value.y);
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Vector2U_t & value)
{
    glUniform2ui(GetUniformLocation(name), value.x, value.y);
}

void Bebr::GL::Program::SetUniform(const std::string& name, float x, float y, float z)
{
    glUniform3f(GetUniformLocation(name), x, y, z);
}

void Bebr::GL::Program::SetUniform(const std::string& name, std::int32_t x, std::int32_t y, std::int32_t z)
{
    glUniform3i(GetUniformLocation(name), x, y, z);
}

void Bebr::GL::Program::SetUniform(const std::string& name, std::uint32_t x, std::uint32_t y, std::uint32_t z)
{
    glUniform3ui(GetUniformLocation(name), x, y, z);
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Vector3F_t& value)
{
    glUniform3f(GetUniformLocation(name), value.x, value.y, value.z);
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Vector3I_t & value)
{
    glUniform3i(GetUniformLocation(name), value.x, value.y, value.z);
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Vector3U_t & value)
{
    glUniform3ui(GetUniformLocation(name), value.x, value.y, value.z);
}

void Bebr::GL::Program::SetUniform(const std::string& name, float x, float y, float z, float w)
{
    glUniform4f(GetUniformLocation(name), x, y, z, w);
}

void Bebr::GL::Program::SetUniform(const std::string& name, std::int32_t x, std::int32_t y, std::int32_t z, std::int32_t w)
{
    glUniform4i(GetUniformLocation(name), x, y, z, w);
}

void Bebr::GL::Program::SetUniform(const std::string& name, std::uint32_t x, std::uint32_t y, std::uint32_t z, std::uint32_t w)
{
    glUniform4ui(GetUniformLocation(name), x, y, z, w);
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix2_t<float>& matrix)
{
    glUniformMatrix2fv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix2x3_t<float>& matrix)
{
    glUniformMatrix2x3fv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix2x4_t<float>& matrix)
{
    glUniformMatrix2x4fv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix2_t<double>& matrix)
{
    glUniformMatrix2dv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix2x3_t<double>& matrix)
{
    glUniformMatrix2x3dv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix2x4_t<double>& matrix)
{
    glUniformMatrix2x4dv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix3_t<float>& matrix)
{
    glUniformMatrix3fv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix3x2_t<float>& matrix)
{
    glUniformMatrix3x2fv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix3x4_t<float>& matrix)
{
    glUniformMatrix3x4fv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix3_t<double>& matrix)
{
    glUniformMatrix3dv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix3x2_t<double>& matrix)
{
    glUniformMatrix3x2dv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix3x4_t<double>& matrix)
{
    glUniformMatrix3x4dv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix4_t<float>& matrix)
{
    glUniformMatrix4fv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix4x2_t<float>& matrix)
{
    glUniformMatrix4x2fv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix4x3_t<float>& matrix)
{
    glUniformMatrix4x3fv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix4_t<double>& matrix)
{
    glUniformMatrix4dv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix4x2_t<double>& matrix)
{
    glUniformMatrix4x2dv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
}

void Bebr::GL::Program::SetUniform(const std::string& name, const System::Matrix4x3_t<double>& matrix)
{
    glUniformMatrix4x3dv(GetUniformLocation(name), 1, GL_TRUE, matrix.GetData());
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

std::int32_t Bebr::GL::Program::GetUniformLocation(const std::string& name) const
{
    return glGetUniformLocation(m_id, name.c_str());
}
