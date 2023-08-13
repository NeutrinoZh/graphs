#include "toolbar-view.h"

namespace app {
    ToolbarView::ToolbarView(int _win_width, ToolBarController* _controller):
        m_controller(_controller)
    {
        m_widget = new Fl_Menu_Bar(0, 0, _win_width, 25);
        m_widget->box(FL_BORDER_BOX);

        m_widget->add("Edit/Triangulation Convex Polygon", 0, (Fl_Callback*)[](Fl_Widget*, void* _view){
            static_cast<ToolbarView*>(_view)->triangulation();
        }, (void*)this);
    }

    ToolbarView::~ToolbarView() {
        delete m_widget;
    }
    
    Fl_Widget* ToolbarView::getWidget() const {
        return m_widget;
    }

    inline void ToolbarView::triangulation() {
        m_controller->triangulation();
    }
}