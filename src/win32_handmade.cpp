//#define GLFW_INCLUDE_NONE // To make sure there will be no header conflicts
#include <GLFW/glfw3.h>

#include <cstdlib>
#include <iostream>

void ErrorCallback(int error, const char* description);
static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void OnWindowClose(GLFWwindow* window);
static void OnWindowClose(GLFWwindow* window);
static void OnWindowResize(GLFWwindow* window, int width, int height);
static void OnWindowChangePosition(GLFWwindow* window, int xpos, int ypos);
static void OnWindowFocus(GLFWwindow* window, int focused);

int
main(void)
{
#ifdef DEBUG_MODE
    std::cout << "Hello from debug mode\n";
#endif

    glfwSetErrorCallback(ErrorCallback);

    if (!glfwInit()) exit(EXIT_FAILURE);

    GLFWwindow* window = glfwCreateWindow(640, 480, "Handmade Hero", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Setup window callbacks
    glfwSetKeyCallback(window, KeyCallback);
    glfwSetWindowCloseCallback(window, OnWindowClose);
    glfwSetWindowSizeCallback(window, OnWindowResize);
    glfwSetWindowPosCallback(window, OnWindowChangePosition);
    glfwSetWindowFocusCallback(window, OnWindowFocus);

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Render here
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

void
ErrorCallback(int error, const char* description)
{
    fprintf(stderr, "Error[%d]: %s\n", error, description);
}

static void
KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        OnWindowClose(window);
}

static void
OnWindowClose(GLFWwindow* window)
{
    std::cout << "[OnWindowClose] Closing the window\n";
    glfwSetWindowShouldClose(window, GL_TRUE);
}

static void
OnWindowResize(GLFWwindow* window, int width, int height)
{
    std::cout << "[OnWindowResize] Resizing the window\n";
}

static void
OnWindowChangePosition(GLFWwindow* window, int xpos, int ypos)
{
    std::cout << "[OnWindowPosition] Change window position\n";
}

static void
OnWindowFocus(GLFWwindow* window, int focused)
{
    std::cout << "[OnWindowFocus] Window gained focus\n";
}
