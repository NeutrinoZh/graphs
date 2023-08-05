#include "canvas-view.h"

namespace app {
    
    CanvasView::CanvasView(ivec2 _pos, ivec2 _size, CanvasModel* _model): 
        Fl_Widget(_pos.x, _pos.y, _size.x, _size.y)  
    {
        m_model = _model;
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
            push(Fl::event_button());
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
                addNewPoint({
                    Fl::event_x() - x(),
                    Fl::event_y() - y()
                });
                break;  
            case FL_LEFT_MOUSE:
                selectPoint();
                break;
            case FL_MIDDLE_MOUSE:
                removePoint();
                break;
        }
    }

    void CanvasView::addNewPoint(ivec2 _point) {
        m_model->addPoint(_point);
    }

    void CanvasView::selectPoint() {
        if (m_select_point && m_hover_point) {
            m_model->setLine(m_select_point, m_hover_point);
            m_select_point = nullptr;
        } else {
            m_select_point = m_hover_point;
        }
    }

    void CanvasView::removePoint() {
        if (m_hover_point)
            m_model->removePoint(m_hover_point);
    }
}