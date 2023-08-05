#include "window-view.h"

namespace app {
    WindowView::WindowView(WindowModel* _model) {
        logger()->info() << "Creating window...";

        if (!_model)
            throw std::invalid_argument("window _model is null");
        m_model = _model;

        auto size = _model->gSize();
        m_window = new Fl_Window(size.x, size.y);
        
        m_window->label(_model->gTitle().c_str());

        m_window->show();
    }
} 