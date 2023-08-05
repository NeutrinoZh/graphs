#include "application/application.h"

namespace app {
    class Window {
    public:
        static Window* s_instance;
    private:
        Fl_Window* m_window = nullptr;
    public:
        Window();
    };
}