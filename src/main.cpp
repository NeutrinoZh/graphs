#include "mvc/window/window-object.h"

using namespace app;

int main(int argc, char** argv) {
    logger()->info() << "Application launch";
    WindowObject window = WindowObject();
    return Fl::run();
}