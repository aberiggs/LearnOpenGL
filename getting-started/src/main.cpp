#include <glad/glad.h>
#include <iostream>

#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // MacOS

  GLFWwindow *window = glfwCreateWindow(800, 600, "Learn OpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window\n";
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD\n";
    return -1;
  }

  glViewport(0, 0, 800, 600);

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // Render loop
  while (!glfwWindowShouldClose(window)) {
    // Input
    processInput(window);

    // Render commands here
    glClearColor(0.16f, 0.16f, 0.16f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Check, call events, and swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
