#pragma once

namespace app {
    class CanvasView;
}

#include "mvc/canvas/canvas-controlller.h"

namespace app {
    class CanvasView : public Fl_Widget {
    private:
        CanvasModel* m_model = nullptr;
        CanvasController* m_controller = nullptr;
    public:
        explicit CanvasView(ivec2 position, ivec2 size, CanvasModel*, CanvasController*);
    protected:
        void draw();
        int handle(int);
    private:
        static constexpr int R = 5;
        static constexpr float HOVER_R = 20.f;

        ivec2* m_hover_point  = nullptr;
        ivec2* m_select_point = nullptr;

        void push(int);
        void move(ivec2);
    };
}