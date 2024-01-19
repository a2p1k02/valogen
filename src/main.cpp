#include "engine/valoengine.h"

#include <iostream>

int main()
{
    try {
        valoengine engine(1360, 768);
        engine.start();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
