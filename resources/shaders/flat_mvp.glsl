#type vertex
#version 440 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in float aAlpha;
layout (location = 3) in vec3 aNormal;
layout (location = 4) in vec2 aTexCoord;
layout (location = 5) in int aObjectId;
layout (location = 6) in int aTexId;

layout (std140, binding = 0) uniform Camera
{
    mat4 u_ViewProjection;
};

layout (location = 0) out vec3 vColor;
layout (location = 1) out float vAlpha;
layout (location = 2) out vec3 vNormal;
layout (location = 3) out vec2 vTexCoord;
layout (location = 4) out flat int vObjectId;
layout (location = 5) out flat int vTexId;

void main()
{
   gl_Position = u_ViewProjection * vec4(aPos.x, aPos.y, aPos.z, 1.0f);
   
   vColor = aColor;
   vAlpha = aAlpha;
   vNormal = aNormal;
   vTexCoord = aTexCoord;
   vObjectId = aObjectId;
   vTexId = aTexId;
}

#type fragment
#version 440 core

layout (location = 0) in vec3 vColor;
layout (location = 1) in float vAlpha;
layout (location = 2) in vec3 vNormal;
layout (location = 3) in vec2 vTexCoord;
layout (location = 4) in flat int vObjectId;
layout (location = 5) in flat int vTexId;

uniform sampler2D uTextures[32];

layout (location = 0) out vec4 FragColor;
layout (location = 1) out int ObjectId;

void main()
{
   FragColor = texture(uTextures[vTexId], vTexCoord) * vec4(vColor, vAlpha);
   ObjectId = vObjectId;
}