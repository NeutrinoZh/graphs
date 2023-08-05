#include "window-model.h"

namespace app {
    class WindowView {
    private:
        WindowModel* m_model;
        Fl_Window* m_window = nullptr;
    public:
        WindowView(WindowModel*);
        ~WindowView();

        void addWidget(Fl_Widget*);
    };
}