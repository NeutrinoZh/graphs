#include "mvc/canvas/canvas-controller.h"

namespace app {
    class ToolBarController {
    private:
        CanvasModel* m_model_canvas; // readonly
        CanvasController* m_ctrl_canvas; // write
        
        void* m_view;
    public:
        explicit ToolBarController(int window_width, CanvasController* canvas_controller, CanvasModel* canvas_model);
        
        Fl_Widget* gWidget() const;

        void triangulation();
    };
}