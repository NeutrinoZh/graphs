#include "mvc/canvas/canvas-model.h"
#include "mvc/canvas/canvas-controlller.h"

namespace app {
    class CanvasView : public Fl_Widget {
    private:
        CanvasModel* m_model = nullptr;
        CanvasController* m_controller = nullptr;
    public:
        CanvasView(ivec2 position, ivec2 size, CanvasModel*, CanvasController*);
    protected:
        void draw();
        int handle(int);
    private:
        static constexpr int R = 5;

        ivec2* m_hover_point  = nullptr;
        ivec2* m_select_point = nullptr;

        void push(int);
    };
}