#include "RenderEngine.hpp"
#include <cstdlib>
#include <exception>


int main(int argc, char** args)
{
    RenderEngine rEngine;

    try {
    rEngine.StartUp();
    } catch (std::exception e) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}