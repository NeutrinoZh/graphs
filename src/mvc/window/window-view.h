#include "window-model.h"

namespace app {
    class WindowView {
    private:
        WindowModel* m_model;
    private:
        Fl_Window* m_window = nullptr;
    public:
        WindowView(WindowModel*);
    };
}