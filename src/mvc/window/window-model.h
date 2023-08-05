#include "application/application.h"

namespace app {
    class WindowModel {
    private:
    // data
        string m_title;
        ivec2 m_size;

    public:
    // setters
      void sTitle(string title) {
        m_title = title;
        rc_title();
      }

      void sSize(ivec2 size) {
        m_size = size;
        rc_size();
      }

    public:
    // getters
        string gTitle() { return m_title; }
        ivec2 gSize() { return m_size; };

    public:
    // reactions
        action rc_title;
        action rc_size;
    };
}