#include "application/application.h"

namespace app {
    class ToolbarView {
    private:
        Fl_Menu_Bar* m_widget;
    public:
        explicit ToolbarView(int _win_width) {
            m_widget = new Fl_Menu_Bar(0, 0, _win_width, 25);
            m_widget->box(FL_BORDER_BOX);
            m_widget->add("Edit/Triangulation");
        }

        ~ToolbarView() {
            delete m_widget;
        }

        Fl_Widget* getWidget() const {
            return m_widget;
        }
    };
}