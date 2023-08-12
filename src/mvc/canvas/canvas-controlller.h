#pragma once
#include "mvc/canvas/canvas-model.h"

namespace app {
    class CanvasController {
    private:
        CanvasModel* m_model;
        CanvasView* m_view;
    public:
        explicit CanvasController(ivec2 win_size);
        ~CanvasController();
        
        Fl_Widget* gWidget() const;
    public:
        void addNewPoint(ivec2);
        void removePoint(ivec2*);
        void setLine(ivec2* from, ivec2* to);
    };
}