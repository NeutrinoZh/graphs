#include "canvas-view.h"

namespace app {
    
    CanvasView::CanvasView(ivec2 _pos, ivec2 _size, CanvasModel* _model, CanvasController* _controller): 
        Fl_Widget(_pos.x, _pos.y, _size.x, _size.y)  
    {
        m_model = _model;
        m_controller = _controller;
    }

    void CanvasView::draw() {
        fl_rectf(x(), y(), w(), h(), FL_WHITE);

        for (auto pair : *m_model) {
            auto point = &pair.first;
            if (m_hover_point == point)
                fl_color(FL_BLUE);
            else 
                fl_color(FL_BLACK);
            
            fl_pie(
                x() + (*point).x,
                y() + (*point).y,
                R*2, R*2, 0, 360
            );
        }
    }

    int CanvasView::handle(int _event) {
        switch (_event) {
        case FL_PUSH:
            redraw();
            return 1;
        case FL_ENTER:
            return 1;
        default:
            return 0;
        }
    }

    void CanvasView::push(int _button) {
        switch (_button) {
            case FL_RIGHT_MOUSE:
                m_controller->addNewPoint({
                    Fl::event_x() - x(),
                    Fl::event_y() - y()
                });
                break;  

            case FL_LEFT_MOUSE:
                if (m_select_point && m_hover_point) {
                    m_controller->setLine(m_select_point, m_hover_point);
                    m_select_point = nullptr;
                } else {
                    m_select_point = m_hover_point;
                }
                break;

            case FL_MIDDLE_MOUSE:
                m_controller->removePoint(m_hover_point);
                break;
        }
    }
}