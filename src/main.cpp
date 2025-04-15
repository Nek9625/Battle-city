#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(void)
{
    GLFWwindow* window;

    // Инициализация GLFW
    if (!glfwInit())
        return -1;

    // Создание окна
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Сделать контекст текущим
    glfwMakeContextCurrent(window);

    // Загрузка OpenGL-функций через GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Can't load GLAD" << std::endl;
        return -1;
    }

    // Получение и вывод версии OpenGL
    const GLubyte* version = glGetString(GL_VERSION);
    std::cout << "OpenGL Version: " << version << std::endl;

    // Установка цвета очистки экрана (зеленый фон)
    glClearColor(1.0f, 1.0f, 0.0f, 1.0f);

    // Главный цикл приложения
    while (!glfwWindowShouldClose(window))
    {
        // Очистка экрана
        glClear(GL_COLOR_BUFFER_BIT);

        // Обмен буферов (двойная буферизация)
        glfwSwapBuffers(window);

        // Обработка событий
        glfwPollEvents();
    }

    // Очистка ресурсов
    glfwTerminate();
    return 0;
}
