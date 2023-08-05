#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <bitset>
#include <optional>
#include <fstream>
#include <sstream>
#include <filesystem>

#include <glm/glm.hpp>
#include <glm/ext/scalar_constants.hpp>

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

constexpr float PI = glm::pi<float>();