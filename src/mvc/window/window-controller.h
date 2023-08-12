#include "mvc/window/window-view.h"
#include "mvc/canvas/canvas-controller.h"
#include "mvc/toolbar/toolbar-controller.h"

namespace app {
    struct WindowController {
    private:
        WindowModel* m_model;
        WindowView* m_view;

        CanvasController* m_canvas;
        ToolBarController* m_toolbar;
    public:
        explicit WindowController();
        ~WindowController();
    };
}