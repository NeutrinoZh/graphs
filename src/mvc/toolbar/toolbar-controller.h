#include "toolbar-view.h"

namespace app {
    class ToolBarController {
    private:
        unique_ptr<ToolbarView> m_view;
    public:
        explicit ToolBarController(int _win_width) {
            m_view = unique_ptr<ToolbarView>(
                new ToolbarView(_win_width)
            );
        }

        Fl_Widget* gWidget() const {
            return m_view->getWidget();
        }
    };
}