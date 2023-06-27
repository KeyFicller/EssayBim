#type vertex
#version 440 core
layout (location = 0) in vec3 aPos;

layout (std140, binding = 0) uniform Camera
{
    mat4 u_ViewProjection;
};

void main()
{
   gl_Position = u_ViewProjection * vec4(aPos.x, aPos.y, aPos.z, 1.0f); 
}

#type fragment
#version 440 core

layout (location = 0) out vec4 FragColor;

void main()
{
   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}