#pragma once
#include "application/application.h"

namespace app {
    class CanvasModel {
    public:
        using graph = unordered_map<ivec2*, vector<ivec2*>>;
    
        ~CanvasModel();
    private:
    // data
        graph m_graph;

        friend class CanvasController;
    public:
    // getters
        inline graph::iterator begin() {
            return m_graph.begin(); 
        }

        inline graph::iterator end() {
            return m_graph.end();
        }

        inline vector<ivec2*> at(ivec2* _point) const {
            return m_graph.at(_point);
        }

        inline size_t size() const {
            return m_graph.size();
        }
    };
}