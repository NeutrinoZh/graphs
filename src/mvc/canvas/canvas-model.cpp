#include "canvas-model.h"

namespace app {
    //==================================//
    //              getters
    using graph = CanvasModel::graph;

    graph::iterator CanvasModel::begin() {
        return m_graph.begin();
    }

    graph::iterator CanvasModel::end() {
        return m_graph.end();
    }
    //==================================//

    CanvasModel::~CanvasModel() {
        for (auto pair : m_graph)
            delete pair.first;
        m_graph.clear();
    }
}