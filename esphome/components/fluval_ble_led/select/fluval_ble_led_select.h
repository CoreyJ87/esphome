#pragma once

#include "esphome/core/component.h"
#include "esphome/components/select/select.h"
#include "esphome/components/fluval_ble_led/fluval_ble_led.h"

namespace esphome {
namespace fluval_ble_led {

class FluvalBleLedSelect : public select::Select, public Component {
 public:
  void set_parent(FluvalBleLed *parent) { parent_ = parent; }
  void setup() override;
  void dump_config() override;

 protected:
  void control(const std::string &value) override;

  FluvalBleLed *parent_;
};

}  // namespace fluval_ble_led
}  // namespace esphome