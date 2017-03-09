//
// Created by lovejoy on 02/01/2017.
// Tutorial: http://xuhongxu.cn/old/index.php/tech/OpenGL1-Setup_Env.html
//

#include <iostream>
#include <GLFW/glfw3.h>

const int WIDTH = 2880;
const int HEIGHT = 1800;

void error_callback(int error, const char* description)
{
    std::cerr << description << std::endl;
}

void display() {
    static int r = 0;
    static int g = 128;
    static int b = 255;
    static int dr = 1;
    static int dg = 1;
    static int db = 1;
    glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
    srand(time(0));
    if(rand()%2==0)
        r += dr;
    else
        r-=dr;
    if(rand()%2==0)
        g += dg;
    else
        g-=dg;
    if(rand()%2==0)
        b += db;
    else
        b-=db;
    if (r > 255 || r < 0) dr = -dr;
    if (g > 255 || g < 0) dg = -dg;
    if (b > 255 || b < 0) db = -db;
    glClear(GL_COLOR_BUFFER_BIT);
}


int main(int argc, char **argv) {
    glfwInit();

    glfwSetErrorCallback(error_callback);

    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "ChangeColor", nullptr, nullptr);

    glViewport(0, 0, WIDTH, HEIGHT);

    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        display();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
