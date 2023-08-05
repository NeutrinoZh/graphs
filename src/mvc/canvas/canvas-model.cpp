#include "canvas-model.h"

namespace app {
    //==================================//
    //              setters

    void CanvasModel::addPoint(ivec2 _point) {;
        m_graph.insert(
            std::make_pair(
               _point,
                vector<ivec2*>()
            )
        );

        rc();
    }

    void CanvasModel::removePoint(ivec2* _point) {
        // delete point from map
        m_graph.erase(*_point); 

        // delete all point references in graph
        for (auto pair : m_graph) {
            auto vec = &m_graph[pair.first];
            auto it = std::find(vec->begin(), vec->end(), _point);

            if (it != vec->end())
                vec->erase(it);
        }

        rc();
    }
        
    void CanvasModel::setLine(ivec2* _from, ivec2* _to) {
        if (_from == _to)
            return;

        rc();
    }

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
}