#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
  glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
  glfwInit();

  GLFWwindow* window = glfwCreateWindow(800,600,"Ashborn Engine", nullptr, nullptr);
  if(!window){
    return -1;
  }
  glfwMakeContextCurrent(window);
  
  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    return -1;    
  }

  glClearColor(0,1.0f,0,1.0f);
  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT); 
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  glfwDestroyWindow(window);
  glfwTerminate();


  return 0;
}
