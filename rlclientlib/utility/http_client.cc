#include "http_client.h"

namespace reinforcement_learning {

  int create_http_client(const char* url, const utility::configuration& cfg, i_http_client** client, api_status* status) {
    int result = error_code::success;
    try {
      // TODO: create http_client based on cfg options
      *client = new http_client(url, cfg);
    } catch (const std::exception& e) {
      result = error_code::http_client_init_error;
      api_status::try_update(status, result, e.what());
    } catch (...) {
      result = error_code::http_client_init_error;
      api_status::try_update(status, result, error_code::http_client_init_error_s);
    }
    return result;
  }
}
