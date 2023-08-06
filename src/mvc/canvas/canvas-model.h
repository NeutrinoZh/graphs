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
        graph::iterator begin();
        graph::iterator end();
    public:
    // reactions
        action rc;
    };
}