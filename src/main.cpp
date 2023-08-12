#include "mvc/window/window-controller.h"

using namespace app;

int main(int argc, char** argv) {
    logger()->info() << "Application launch";
    WindowController window = WindowController();
    return Fl::run();
}