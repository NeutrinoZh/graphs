#pragma once
#include "canvas-controlller.h"

namespace app {
    CanvasController::CanvasController(CanvasModel* _model) {
        m_model = _model;
    }

    void CanvasController::addNewPoint(ivec2 _point) {
        m_model->addPoint(_point);
    }

    void CanvasController::setLine(ivec2* _from, ivec2* _to) {
        m_model->setLine(_from, _to);
    }

    void CanvasController::removePoint(ivec2* _point) {
        m_model->removePoint(_point);
    }   
}