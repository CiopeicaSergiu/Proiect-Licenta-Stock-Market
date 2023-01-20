#include <cstdlib>
#include <memory>
#include <restbed>

using namespace std;
using namespace restbed;

void post_method_handler(const shared_ptr<Session> session) {
  const auto request = session->get_request();
  session->close(OK, "Hello, World!", {{"Content-Length", "13"}});
}

int main(const int, const char **) {
  auto resource = make_shared<Resource>();
  resource->set_path("/resource");
  resource->set_method_handler("GET", post_method_handler);

  auto settings = make_shared<Settings>();
  settings->set_port(1984);
  settings->set_default_header("Connection", "close");

  Service service;
  service.publish(resource);
  service.start(settings);

  return EXIT_SUCCESS;
}