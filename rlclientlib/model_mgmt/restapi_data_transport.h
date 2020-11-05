#pragma once

#include <memory>

#include "model_mgmt.h"
#include "utility/http_client.h"

namespace reinforcement_learning {

class i_trace;

namespace model_management {

class restapi_data_transport : public i_data_transport {
 public:
  restapi_data_transport(std::unique_ptr<i_http_client> httpcli,
                         i_trace *trace);

  int get_data(model_data &data, api_status *status) override;

 private:
  int get_data_info(std::string &last_modified, uint64_t &sz,
                    api_status *status);

  std::unique_ptr<i_http_client> _httpcli;
  std::string _last_modified;
  uint64_t _datasz;
  i_trace *_trace;
};

}  // namespace model_management
}  // namespace reinforcement_learning
