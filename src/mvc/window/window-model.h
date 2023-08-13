#include "logger/Logger.h"

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
      }

      void sSize(ivec2 size) {
        m_size = size;
      }

    public:
    // getters
        string gTitle() { return m_title; }
        ivec2 gSize() { return m_size; };
  };
}