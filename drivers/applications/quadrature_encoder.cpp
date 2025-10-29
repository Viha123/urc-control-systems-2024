
#include "../hardware_map.hpp"
#include <libhal-util/serial.hpp>
#include <libhal-util/steady_clock.hpp>
#include <libhal/units.hpp>
#include <libhal-armcortex/dwt_counter.hpp>
#include <libhal-armcortex/startup.hpp>
#include <libhal-armcortex/system_control.hpp>

using namespace hal::literals;
using namespace std::chrono_literals;

namespace sjsu::drivers {
void application()
{
  auto encoder = resources::encoder();
  auto console = resources::console();
  auto clock = resources::clock();

  while (true) {
    auto reading = encoder->read().angle;

    hal::print<128>(*console, "Reading: %f\n", reading );
    hal::delay(*clock, 500ms);
  }
}
}
