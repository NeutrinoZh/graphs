#include "canvas-view.h"

namespace app {
    
    CanvasView::CanvasView(ivec2 _pos, ivec2 _size, CanvasModel* _model, CanvasController* _controller): 
        Fl_Widget(_pos.x, _pos.y, _size.x, _size.y)  
    {
        m_model = _model;
        m_controller = _controller;
    }

    void CanvasView::draw() {
        // draw canvas
        fl_rectf(x(), y(), w(), h(), FL_WHITE);

        // draw points
        for (auto pair : *m_model) {
            auto point = pair.first;
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

        // draw lines
        fl_color(FL_BLACK);
        for (auto node : *m_model)
            for (uint i = 0; i < node.second.size(); ++i)
                fl_line(
                    x() + node.first->x + R,
                    y() + node.first->y + R, 
                    x() + node.second[i]->x + R, 
                    y() + node.second[i]->y + R
                );
        
        // draw line to cursor
        if (m_select_point)
            fl_line(
                x() + m_select_point->x + R,
                y() + m_select_point->y + R,
                Fl::event_x(), Fl::event_y()
            );
    }

    int CanvasView::handle(int _event) {
        switch (_event) {
        case FL_PUSH:
            push(Fl::event_button());
            return 1;
        case FL_MOVE:
            move({
                Fl::event_x() - x(),
                Fl::event_y() - y()
            });
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

                redraw();
                break;  

            case FL_LEFT_MOUSE:
                if (m_select_point && m_hover_point) {
                    m_controller->setLine(m_select_point, m_hover_point);
                    m_select_point = nullptr;
                } else {
                    m_select_point = m_hover_point;
                }

                redraw();
                break;

            case FL_MIDDLE_MOUSE:
                m_controller->removePoint(m_hover_point);

                redraw();
                break;
        }
    }

    void CanvasView::move(ivec2 _pos) {
        auto old_hover_point = m_hover_point;

        //================================================//
        //              m_hover_point

        ivec2* near_point = nullptr;
        float min_distance = __FLT_MAX__;

        for (auto pair : *m_model) {
            auto point = pair.first;

            float distance = glm::distance(
                (vec2)*point,
                (vec2)_pos
            );

            if (distance < min_distance) {
                min_distance = distance;
                near_point = (ivec2*)point;
            }
        }

        if (min_distance < HOVER_R)
            m_hover_point = near_point;
        else 
            m_hover_point = nullptr;

        //================================================//

        if (
            m_hover_point != old_hover_point ||
            m_select_point
        )
            redraw();
    }
}