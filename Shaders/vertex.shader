#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
//layout (location = 1) in vec3 aColor;

//out vec3 ourColor;
out vec2 texCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	//ATTENZIONE ALL'ORDINE DELLA MOLTIPLICAZIONE DELLE MATRICI
	gl_Position = projection * view * model * vec4(aPos, 1.0);
	texCoord = aTexCoord;
	//ourColor = aColor;
}