#include "mvc/window/window-view.h"
#include "mvc/canvas/canvas-object.h"

namespace app {
    // RAII
    struct WindowObject {
    private:
        WindowModel* m_model;
        WindowView* m_view;

        CanvasObject* m_canvas;
    public:
        WindowObject() {
            logger()->info() << "Creating window object";

            m_model = new app::WindowModel();
            m_model->sTitle("Triangulation");
            m_model->sSize({800, 600});

            m_view = new app::WindowView(m_model); 

            m_canvas = new CanvasObject(m_model->gSize());
            m_view->addWidget(
                m_canvas->gWidget()
            );
        };

        ~WindowObject() {
            logger()->info() << "Deleting window object";

            delete m_canvas;

            delete m_view;
            delete m_model;
        }
    };
}