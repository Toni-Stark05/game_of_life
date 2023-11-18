#include "src/core/Window.h"

int main() {
    Core::Window* window = Core::Window::GetWindow();

    window->exit();
    return 0;
}
