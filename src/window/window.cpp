#include "window/window.h"

namespace app {
    Window* Window::s_instance = nullptr;
    
    Window::Window() {
        if (s_instance) {
            logger()->error() << 
                "You are trying to create a second window instance!";
            return;
        }

        logger()->info() << "Creating window...";
        
        m_window = new Fl_Window(800, 600);
        m_window->show();

        s_instance = this;
    }
} 