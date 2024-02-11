#include <iostream>

void printVersion() {
    std::cout << "LWM 1.0.0" << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc > 1 && std::string(argv[1]) == "--version") {
        printVersion();
        return 0;
    } else {
        // Código para iniciar la GUI aquí
        return 0;
    }
}
