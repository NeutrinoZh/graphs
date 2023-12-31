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
using std::unique_ptr;

constexpr float PI = glm::pi<float>();

namespace app {
    template <typename Type>
    inline bool containsElementInVector(vector<Type> vec, Type value) {
        return std::find(vec.begin(), vec.end(), value) != vec.end();
    }
}