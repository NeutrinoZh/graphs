#include "window/window.h"

using namespace app;

int main(int argc, char** argv) {
    logger()->info() << "Application launch";
    app::Window* window = new app::Window();
    return Fl::run();
}