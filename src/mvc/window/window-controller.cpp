#include "window-controller.h"

namespace app {
    WindowController::WindowController() {
        logger()->info() << "Creating window";

            //===========================================//
            // model

            m_model = new app::WindowModel();
            m_model->sTitle("Triangulation");
            m_model->sSize({800, 600});

            // view
            m_view = new app::WindowView(m_model); 

            m_canvas = new CanvasController(m_model->gSize());
            m_view->addWidget(
                m_canvas->gWidget()
            );

            m_toolbar = new ToolBarController(m_model->gSize().x);
            m_view->addWidget(
                m_toolbar->gWidget()
            );

            //=========================================//
    }

    WindowController::~WindowController() {
        logger()->info() << "Deleting window object";

        delete m_toolbar;
        delete m_canvas;

        delete m_view;
        delete m_model;
    }
}