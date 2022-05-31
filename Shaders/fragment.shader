#version 330 core
out vec4 FragColor;

//in vec3 ourColor;
in vec2 texCoord;

uniform sampler2D texture0;

void main()
{
	//vec4(vec3(1.0f, 0.0f, 0.0f), 1.0f);
	FragColor = texture(texture0, texCoord);
}