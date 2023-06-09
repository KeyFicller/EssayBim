#type vertex
#version 440 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in float aAlpha;

layout (location = 3) in int aObjectId;

layout (std140, binding = 0) uniform Camera
{
    mat4 u_ViewProjection;
};

layout (location = 0) out vec3 vColor;
layout (location = 1) out float vAlpha;

layout (location = 2) out flat int vObjectId;

void main()
{
   gl_Position = u_ViewProjection * vec4(aPos.x, aPos.y, aPos.z, 1.0f);

   vColor = aColor;
   vAlpha = aAlpha;
   vObjectId = aObjectId;
}

#type fragment
#version 440 core

layout (location = 0) in vec3 vColor;
layout (location = 1) in float vAlpha;

layout (location = 2) in flat int vObjectId;

layout (location = 0) out vec4 FragColor;
layout (location = 1) out int ObjectId;

void main()
{
   FragColor = vec4(vColor, vAlpha);
   ObjectId = vObjectId;
}