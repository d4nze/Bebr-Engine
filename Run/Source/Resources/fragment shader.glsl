#version 330 core

in vec4 ourColor;
in vec2 ourTexCoords;

uniform sampler2D uTexture;

out vec4 FragColor;

void main()
{
    vec4 texColor = texture(uTexture, ourTexCoords);
    FragColor = ourColor * texColor;
}