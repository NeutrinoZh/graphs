#include "mvc/canvas/canvas-view.h"

namespace app {
    // RAII
    class CanvasObject {
    private:
        CanvasModel* m_model;
        CanvasView* m_view;
    public:
        CanvasObject(ivec2 w_size) {
            logger()->info() << "Creating canvas object";

            m_model = new CanvasModel();

            const int offset = 25;
            m_view = new CanvasView(
                { 0, offset },
                { w_size.x, w_size.y - offset },
                m_model
            );
        }

        ~CanvasObject() {
            logger()->info() << "Deleting canvas object";

            delete m_model;
            delete m_view;
        }

        Fl_Widget* gWidget() {
            return (Fl_Widget*)m_view;
        };
    };
}