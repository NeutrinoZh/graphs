#include "window-view.h"

namespace app {
    WindowView::WindowView(WindowModel* _model) {
        if (!_model)
            throw std::invalid_argument("window _model is null");
        m_model = _model;

        auto size = _model->gSize();
        m_window = new Fl_Window(
            size.x, size.y,
            _model->gTitle().c_str()
        );

        m_window->show();
    }

    WindowView::~WindowView() {
        delete m_window;
    }

    void WindowView::addWidget(Fl_Widget* _widget) {
        m_window->add(_widget);
    }
} 