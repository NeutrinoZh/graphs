#pragma once
#include "application/application.h"

namespace app {
    class CanvasModel {
    public:
        using graph = unordered_map<ivec2, vector<ivec2*>>;
    private:
    // data
        graph m_graph;
    public:
    // setters
        void addPoint(ivec2);
        void removePoint(ivec2*);
        
        void setLine(ivec2* from, ivec2* to);
    public:
    // getters
        graph::iterator begin();
        graph::iterator end();
    public:
    // reactions
        action rc;
    };
}