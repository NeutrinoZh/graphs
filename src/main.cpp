#include "mvc/window/window-view.h"

using namespace app;

int main(int argc, char** argv) {
    logger()->info() << "Application launch";

    auto window_model = new app::WindowModel();
    window_model->sTitle("Triangulation");
    window_model->sSize({800, 600});

    auto window_view = new app::WindowView(window_model);
    
    return Fl::run();
}