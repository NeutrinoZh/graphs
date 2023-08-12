#include "mvc/window/window-view.h"
#include "mvc/canvas/canvas-object.h"
#include "mvc/toolbar/toolbar-controller.h"

namespace app {
    struct WindowObject {
    private:
        WindowModel* m_model;
        WindowView* m_view;

        CanvasObject* m_canvas;
        ToolBarController* m_toolbar;
    public:
        WindowObject() {
            logger()->info() << "Creating window object";

            //===========================================//
            // model

            m_model = new app::WindowModel();
            m_model->sTitle("Triangulation");
            m_model->sSize({800, 600});

            // view
            m_view = new app::WindowView(m_model); 

            m_canvas = new CanvasObject(m_model->gSize());
            m_view->addWidget(
                m_canvas->gWidget()
            );

            m_toolbar = new ToolBarController(m_model->gSize().x);
            m_view->addWidget(
                m_toolbar->gWidget()
            );

            //=========================================//
        };

        ~WindowObject() {
            logger()->info() << "Deleting window object";

            delete m_toolbar;
            delete m_canvas;

            delete m_view;
            delete m_model;
        }
    };
}