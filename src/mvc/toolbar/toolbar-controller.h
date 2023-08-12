#include "application/application.h"

namespace app {
    class ToolBarController {
    private:
        void* m_view;
    public:
        explicit ToolBarController(int window_width);
        
        Fl_Widget* gWidget() const;

        void triangulation();
    };
}