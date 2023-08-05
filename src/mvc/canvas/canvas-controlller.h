#pragma once
#include "mvc/canvas/canvas-model.h"

namespace app {
    class CanvasController {
    private:
        CanvasModel* m_model;
    public:
        CanvasController(CanvasModel*);

        void addNewPoint(ivec2);
        void removePoint(ivec2*);

        void setLine(ivec2* from, ivec2* to);
    };
}