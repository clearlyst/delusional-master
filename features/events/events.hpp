#pragma once
#include "../../sdk/sdk.hpp"

class hooked_events : public i_game_event_listener2 {
public:
	void fire_game_event(i_game_event* event) noexcept;
	void setup() noexcept;
	void release() noexcept;
	int get_event_debug_id(void) noexcept;
};

extern hooked_events events;