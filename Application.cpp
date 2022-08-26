#include "Application.hpp"

SelectHelper Application::_select_helper;

Application::Application() {}

Application::~Application() {}

void Application::run() {
  _select_helper.initServer();

  while (true) {
    _select_helper.inspectFds();
  }
}
