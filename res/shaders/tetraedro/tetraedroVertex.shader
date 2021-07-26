#version 330 core

layout (location = 0) in vec3 position;

layout (location = 1) in vec3 aColor;

out vec3 color;

uniform mat4 camMatrix;
uniform mat4 transform;

void main()
{
	gl_Position = (camMatrix * transform) * vec4(position, 1.0);
	color = aColor;
}