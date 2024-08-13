#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec4 aColor;
layout(location = 2) in vec2 aTexCoords;

out vec4 ourColor;
out vec2 ourTexCoords;

uniform mat4 uModel;
uniform mat4 uCamera;

void main()
{
    gl_Position = vec4(aPos, 1.0) * uModel * uCamera;
    ourColor = aColor;
    ourTexCoords = aTexCoords;
}