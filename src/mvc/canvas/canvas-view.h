#include "mvc/canvas/canvas-model.h"

namespace app {
    class CanvasView : public Fl_Widget {
    private:
        CanvasModel* m_model = nullptr;
    public:
        CanvasView(ivec2 position, ivec2 size, CanvasModel*);
    protected:
        void draw();
        int handle(int);
        
    private:
        ivec2* m_hover_point = nullptr;
        ivec2* m_select_point = nullptr;

    private:
        static constexpr int R = 5;

        void push(int);
        
        void addNewPoint(ivec2);
        void removePoint();
        void selectPoint();
    };
}