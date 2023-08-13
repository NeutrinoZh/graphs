#include "canvas-model.h"

namespace app {
    CanvasModel::~CanvasModel() {
        for (auto pair : m_graph)
            delete pair.first;
        m_graph.clear();
    }
}