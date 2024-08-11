import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import select, fluval_ble_led
from esphome.const import CONF_ID
from .. import fluval_ble_led_ns

FluvalBleLedSelect = fluval_ble_led_ns.class_(
    "FluvalBleLedSelect", select.Select, cg.Component
)

CONFIG_SCHEMA = (
    select.select_schema(FluvalBleLedSelect)
    .extend(cv.COMPONENT_SCHEMA)
    .extend(fluval_ble_led.FLUVAL_CLIENT_SCHEMA)
)

async def to_code(config):
    var = await select.new_select(config)
    await cg.register_component(var, config)
    parent = await cg.get_variable(config[fluval_ble_led.CONF_FLUVAL_BLE_LED_ID])
    cg.add(var.set_parent(parent))