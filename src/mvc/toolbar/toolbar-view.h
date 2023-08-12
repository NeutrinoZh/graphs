#include "toolbar-controller.h"

namespace app {
    class ToolbarView {
    private:
        ToolBarController* m_controller;
        Fl_Menu_Bar* m_widget;
    public:
        ~ToolbarView();
        explicit ToolbarView(
            int window_width,
            ToolBarController* controller
        );

        Fl_Widget* getWidget() const;
    private:
        inline void triangulation();
    };
}