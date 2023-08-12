#include "toolbar-view.h"

namespace app {
    ToolBarController::ToolBarController(int _win_width) {
        m_view = static_cast<void*>(
            new ToolbarView(_win_width, this)
        );
    }

    Fl_Widget* ToolBarController::gWidget() const {
        return static_cast<ToolbarView*>(m_view)
            ->getWidget();
    }

    void ToolBarController::triangulation() {
        logger()->debug() << "Triangulation";
    }
}