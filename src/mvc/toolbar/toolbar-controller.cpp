#include "toolbar-view.h"

namespace app {
    //========================================================//

    ToolBarController::ToolBarController(int _win_width, CanvasController* _controller, CanvasModel* _model):
        m_model_canvas(_model), m_ctrl_canvas(_controller)
    {
        m_view = static_cast<void*>(
            new ToolbarView(_win_width, this)
        );
    }

    Fl_Widget* ToolBarController::gWidget() const {
        return static_cast<ToolbarView*>(m_view)
            ->getWidget();
    }

    //========================================================//

    void ToolBarController::triangulation() {
        logger()->info() << "Triangulation start...";

        //====================================================//

        if (m_model_canvas->size() == 0) {
            logger()->error() << "Triangulation requires a convex polygon!";
            return;
        }

        for (auto vertex : *m_model_canvas)
            if (vertex.second.size() != 2) {
                logger()->error() << "Triangulation requires a convex polygon, that is, each vertex must have two edges!";
                return;
            }

        //====================================================//
        // converted to new format:
        // array of points where adjacent elements
        // are adjacent points in the polygon

        vector<ivec2*> polygon; {
            auto start = m_model_canvas->begin()->first;
            do {
                polygon.push_back(start);

                auto left  = m_model_canvas->at(start)[0];
                auto right = m_model_canvas->at(start)[1];

                if (!containsElementInVector(polygon, left))
                    start = left;
                else if (!containsElementInVector(polygon, right))
                    start = right;
                else 
                    break;

            } while (true);

            assert(polygon.size() == m_model_canvas->size());
        }

        // function for getting polygon vertices
        //     after  last  - first 
        // and before first - last
        auto v = [](int i, vector<ivec2*>& polygon){
            if (i < 0)
                i = polygon.size() + i;
            i = i % polygon.size();
            return polygon[i];
        };

        //====================================================//
        // Convex check

        ivec2 *start, *prev, *next;

        for (int i = 0; i < polygon.size(); ++i) {
            prev  = v(i - 1, polygon);
            start = v(i,     polygon);
            next  = v(i + 1, polygon);

            vec2 a = *start - *prev;
            vec2 b = *next - *start;
            if (glm::dot(a, b) < 0) {
                logger()->error() << "polygon must be convex!";
                return;
            }
        }

        //====================================================//
        // Triangulation

        for (int i = 0; polygon.size() != 3; i += 2) {
            prev  = v(i - 1, polygon);
            start = v(i,     polygon);
            next  = v(i + 1, polygon);

            m_ctrl_canvas->setLine(prev, next);
            polygon.erase(std::find(polygon.begin(), polygon.end(), start));
        }

        //====================================================//
    }
}