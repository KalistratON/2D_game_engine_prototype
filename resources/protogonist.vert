#version 400 core

layout (location = 0) in vec2 thePosition;
layout (location = 1) in vec2 theTexCoord;
layout (location = 2) in vec4 theColor;

out vec2 outTexCoord;
out vec4 outColor;

uniform mat3 ViewMatrix = mat3 (1.0f);

void main()
{
	vec3 aPosition = ViewMatrix * vec3 (thePosition, 1.0);
	gl_Position = vec4 (aPosition.xy, 0.0, 1.0);
	
	outTexCoord = theTexCoord;
	outColor    = theColor;
}