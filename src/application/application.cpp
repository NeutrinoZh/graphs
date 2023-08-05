#include "application.h"

namespace app {
    
    bool m_alive = true;

    bool Application::isAlive() {
        return m_alive;
    }

    void Application::quit() {
        logger()->info() << "Quit was invoked";
        m_alive = false;
    }
}