#include <iostream>

#include <string>
#include <sstream>

#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <bitset>

#include <functional>
#include <algorithm>
#include <optional>

#include <fstream>
#include <filesystem>

#include <glm/glm.hpp>
#include <glm/ext/scalar_constants.hpp>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/hash.hpp>

#include <Fl/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Menu_Bar.H>
#include <Fl/fl_draw.H>

#ifdef _WIN32
    using uint = unsigned int;
#endif

namespace fs = std::filesystem;

using glm::vec2;
using glm::vec3;

using glm::ivec2;
using glm::ivec3;

using std::string;
using std::vector;
using std::map;
using std::unordered_map;

constexpr float PI = glm::pi<float>();

namespace app {
    class action {
    private:
        std::vector<std::function<void()>> m_funcs;
    public:
        void operator+=(std::function<void()> func) {
            m_funcs.push_back(func);
        }

        void operator()() {
            for (auto& f : m_funcs)
                f();
        }
    };

    template <typename Type>
    bool containsElementInVector(vector<Type> vec, Type value) {
        return std::find(vec.begin(), vec.end(), value) != vec.end();
    }
}