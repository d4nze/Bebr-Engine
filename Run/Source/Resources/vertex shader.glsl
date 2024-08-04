#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec4 aColor;

out vec4 ourColor;

uniform mat4 uModel;
uniform mat4 uCamera;

void main()
{
    gl_Position = vec4(aPos, 1.0) * uModel * uCamera;
    ourColor = aColor;
}