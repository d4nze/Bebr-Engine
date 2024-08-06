#pragma once
#include <System/Matrix.hpp>

class Camera
{
public:
    Camera(float x, float y, float width, float height)
        : m_position(Bebr::System::CreateIdentityMatrix<float, 4>())
        , m_descale(Bebr::System::CreateIdentityMatrix<float, 4>())
    {
        m_position[3][0] = x;
        m_position[3][1] = y;
        m_descale[0][0] = 2.f / width;
        m_descale[1][1] = 2.f / height;
    }

public:
    Bebr::System::Matrix4_t<float> GetMatrix() const
    {
        return m_descale * m_position;
    }

private:
    Bebr::System::Matrix4_t<float> m_position;
    Bebr::System::Matrix4_t<float> m_descale;
};
