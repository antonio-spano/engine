#include "UpdateList.hpp"
#include "SpriteList.hpp"
#include "utils.hpp"

const int WIDTH = 800;
const int HEIGHT = 600;

void FramebufferSizeCallback(GLFWwindow* window, int width, int heigth)
{
	glViewport(0, 0, width, heigth);
}

void ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE))
	{
		glfwSetWindowShouldClose(window, true);
	}
}

int main()
{
	if (glfwInit() != GL_TRUE) { return -1; };
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "ERROR: Failed to create GLFW window." << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	//gladInit
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, WIDTH, HEIGHT);
	glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

	shader.Init("Shaders/vertex.shader", "Shaders/fragment.shader");

	//VAO
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	//bind VAO temporarily to store calls (and use it later)
	glBindVertexArray(VAO);

	//texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);

	glm::mat4 view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -2.5f));

	glm::mat4 projection;
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

	glEnable(GL_DEPTH_TEST);

	float lastTick = 0;
	dt = 0;

	UpdateList();
	SpriteList();

	list.StartAll();

	while (!glfwWindowShouldClose(window))
	{
		lastTick = glfwGetTime();

		glClearColor(0, 0.2, 0.2, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ProcessInput(window);

		shader.SetMatrix4("view", view);
		shader.SetMatrix4("projection", projection);

		list.DrawAll();

		glfwPollEvents();
		glfwSwapBuffers(window);

		dt = (glfwGetTime() - lastTick);

		list.UpdateAll(dt);
	}
	glfwTerminate();
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
