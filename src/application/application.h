#include "../logger/Logger.h"

namespace app {
    class Application {
    public:
        static bool isAlive();
        static void quit();
    };
}