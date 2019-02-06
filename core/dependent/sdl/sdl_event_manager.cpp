#include "pav_pch.h"
#include "sdl_event_manager.h"

void pav::SDLEventManager::Initialize()
{
	// Convert SDL keycode to our engine's keycode
	sdl_key_map_[SDLK_a] = KEY_A;
	sdl_key_map_[SDLK_b] = KEY_B;
	sdl_key_map_[SDLK_c] = KEY_C;
	sdl_key_map_[SDLK_d] = KEY_D;
	sdl_key_map_[SDLK_e] = KEY_E;
	sdl_key_map_[SDLK_f] = KEY_F;
	sdl_key_map_[SDLK_g] = KEY_G;
	sdl_key_map_[SDLK_h] = KEY_H;
	sdl_key_map_[SDLK_i] = KEY_I;
	sdl_key_map_[SDLK_j] = KEY_J;
	sdl_key_map_[SDLK_k] = KEY_K;
	sdl_key_map_[SDLK_l] = KEY_L;
	sdl_key_map_[SDLK_m] = KEY_M;
	sdl_key_map_[SDLK_n] = KEY_N;
	sdl_key_map_[SDLK_o] = KEY_O;
	sdl_key_map_[SDLK_p] = KEY_P;
	sdl_key_map_[SDLK_q] = KEY_Q;
	sdl_key_map_[SDLK_r] = KEY_R;
	sdl_key_map_[SDLK_s] = KEY_S;
	sdl_key_map_[SDLK_t] = KEY_T;
	sdl_key_map_[SDLK_u] = KEY_U;
	sdl_key_map_[SDLK_v] = KEY_V;
	sdl_key_map_[SDLK_w] = KEY_W;
	sdl_key_map_[SDLK_x] = KEY_X;
	sdl_key_map_[SDLK_y] = KEY_Y;
	sdl_key_map_[SDLK_z] = KEY_Z;
	// TODO: Someone fill in the rest of the keys thanks
}

void pav::SDLEventManager::End()
{
}

void pav::SDLEventManager::Update(const float delta_time)
{
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
		{
			// Convert keycode
			KeyCode keycode = sdl_key_map_.at(event.key.keysym.sym);

			if (event.key.repeat == 0) // Key down event
			{
				on_key_down.EmitAll(std::move(keycode));

				// Input event
				on_input.EmitAll(InputEventType::DOWN);
			}
			else // Key hold event
			{
				on_key_hold.EmitAll(std::move(keycode));

				// Input event
				on_input.EmitAll(InputEventType::HOLD);
			}
			break;
		}
		case SDL_KEYUP:
		{
			// Convert keycode
			KeyCode keycode = sdl_key_map_.at(event.key.keysym.sym);

			on_key_up.EmitAll(std::move(keycode));

			// Input event
			on_input.EmitAll(InputEventType::UP);
			break;
		}
		case SDL_MOUSEBUTTONDOWN:
		{
			if (event.button.button == SDL_BUTTON_LEFT) // Left button
			{
				on_mouse_button_down.EmitAll(MouseButtonCode::LEFT, static_cast<unsigned short>(event.button.clicks));
			}
			else if (event.button.button == SDL_BUTTON_MIDDLE) // Middle button
			{
				on_mouse_button_down.EmitAll(MouseButtonCode::MIDDLE, static_cast<unsigned short>(event.button.clicks));
			}
			else if (event.button.button == SDL_BUTTON_LEFT) // Right button
			{
				on_mouse_button_down.EmitAll(MouseButtonCode::RIGHT, static_cast<unsigned short>(event.button.clicks));
			}
			
			// Input event
			on_input.EmitAll(InputEventType::DOWN);
			break;
		}
		case SDL_MOUSEBUTTONUP:
		{
			if (event.button.button == SDL_BUTTON_LEFT) // Left button
			{
				on_mouse_button_down.EmitAll(MouseButtonCode::LEFT, static_cast<unsigned short>(event.button.clicks));
			}
			else if (event.button.button == SDL_BUTTON_MIDDLE) // Middle button
			{
				on_mouse_button_down.EmitAll(MouseButtonCode::MIDDLE, static_cast<unsigned short>(event.button.clicks));
			}
			else if (event.button.button == SDL_BUTTON_LEFT) // Right button
			{
				on_mouse_button_down.EmitAll(MouseButtonCode::RIGHT, static_cast<unsigned short>(event.button.clicks));
			}

			// Input event
			on_input.EmitAll(InputEventType::UP);
			break;
		}
		}
	}
}
