#include "fluval_ble_led_select.h"
#include "esphome/core/log.h"

namespace esphome {
namespace fluval_ble_led {

static const char *const TAG = "fluval_ble_led.select";

void FluvalBleLedSelect::setup() {
  traits.set_options({"Manual", "Auto", "Pro"});
  this->state = "Manual";
}

void FluvalBleLedSelect::control(const std::string &value) {
  this->state = value;
  this->parent_->set_mode(value);
}

void FluvalBleLedSelect::dump_config() {
  ESP_LOGCONFIG(TAG, "Fluval BLE LED Select:");
  LOG_SELECT("  ", "Mode", this);
}

}  // namespace fluval_ble_led
}  // namespace esphome