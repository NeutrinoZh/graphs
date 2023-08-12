#include "canvas-view.h"

namespace app {

    //==================================================//
    
    CanvasController::CanvasController(ivec2 _w_size) {
        logger()->info() << "Creating canvas object";

        m_model = new CanvasModel();

        const int offset = 25;
        m_view = new CanvasView(
            { 0, offset },
            { _w_size.x, _w_size.y - offset },
            m_model, this
        );
    }

    CanvasController::~CanvasController() {
        logger()->info() << "Deleting canvas object";

        delete m_model;
        delete m_view;
    }

    Fl_Widget* CanvasController::gWidget() const {
        return static_cast<Fl_Widget*>(m_view);
    }

    //==================================================//

    void CanvasController::addNewPoint(ivec2 _point) {
        logger()->debug() << "add new point:" << _point;

        m_model->m_graph.insert(
            std::make_pair(
               new ivec2(_point),
                vector<ivec2*>()
            )
        );
    }

    void CanvasController::setLine(ivec2* _from, ivec2* _to) {
        if (!_from || !_to)
            return;
        
        if (_from == _to)
            return;

        logger()->debug() << "set line from " 
            << *_from << " to " << *_to;

        auto graph = &m_model->m_graph;

        if (!containsElementInVector((*graph)[_from], _to))
            (*graph)[_from].push_back(_to);

        if (!containsElementInVector((*graph)[_to], _from))
            (*graph)[_to].push_back(_from);
    }

    void CanvasController::removePoint(ivec2* _point) {
        if (!_point)
            return;

        logger()->debug() << "remove point " << *_point;

        // delete point from map
        m_model->m_graph.erase(_point); 

        // delete all point references in graph
        for (auto pair : *m_model) {
            auto vec = &m_model->m_graph[pair.first];
            auto it = std::find(vec->begin(), vec->end(), _point);

            if (it != vec->end())
                vec->erase(it);
        }
    }   
}