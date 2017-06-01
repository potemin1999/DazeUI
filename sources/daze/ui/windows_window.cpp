#include "window.h"

//#ifdef _WIN32

#include "glad\glad.h"
#include "glfw\glfw3.h"
#include <iostream>

using namespace daze;

Window::Window(){
}

Window::~Window(){
}

int Window::resize(char pointer...){
    GLFWwindow* w = (GLFWwindow*) &pointer;
    int width = *(&pointer + sizeof(w));
    int height = *(&pointer + sizeof(w) + sizeof(int));

    return 0;
}

int Window::key(char pointer...){
    return 0;
}

void Window::onCreate(){
}

void Window::onDestroy(){
}

void Window::onPause(){
}

void Window::onResume(){
}

void Window::onDraw(){
}

int Window::internal_run(void* parameters){
    std::cout << "window runs\n";
    GLFWwindow* window;
    if (!glfwInit()) {
		return -1;
	}
	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);
	glfwWindowHint(GLFW_RED_BITS, 16);
	glfwWindowHint(GLFW_GREEN_BITS, 16);
	glfwWindowHint(GLFW_BLUE_BITS, 16);
	glfwWindowHint(GLFW_REFRESH_RATE, 200);
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* vidmode = glfwGetVideoMode(monitor);
	if (fullscreen) {
		size[0] = vidmode->width;
		size[1] = vidmode->height;
		position[0] = 0;
		position[1] = 0;
		window = glfwCreateWindow(size[0],size[1],name, monitor, 0);
	}else {
	    size[0] = size[0] > vidmode->width  ? vidmode->width  : size[0];
	    size[1] = size[1] > vidmode->height ? vidmode->height : size[1];
		window = glfwCreateWindow(size[0],size[1],name, 0, 0);
	}
	if (!window) {
		glfwTerminate();
	}
    glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return -1;
	}
    glfwSwapInterval(1);
	glfwSetWindowSizeCallback(window,(GLFWwindowsizefun) &resize);
	glfwSetKeyCallback(window, (GLFWkeyfun) &key);
	//glfwSetErrorCallback(error);
	glfwShowWindow(window);
	std::cout << "window shown\n";
	try {
	    onCreate();
		while (!glfwWindowShouldClose(window)) {

		/*dT = (cT = float(glfwGetTime())) - lT;
		lT = cT;
		glfwGetCursorPos(window, &xpos,&ypos);
		engine->camera->rotate_view_right(0.001f * (window_width / 2 - float(xpos)));
		engine->camera->rotate_view_up(0.001f*(window_height / 2 - float(ypos)));
		glfwSetCursorPos(window, window_width / 2, window_height / 2);

		engine->draw(dT);*/
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	onDestroy();
	}catch(int exception){

	}


	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

//#endif
