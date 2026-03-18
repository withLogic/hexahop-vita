/*
    Copyright (C) 2005-2007 Tom Beaumont

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#include <SDL2/SDL.h>
#include "joy.h"

void InitJoystick()
{
#ifndef DISABLE_JOYSTICK
	SDL_InitSubSystem(SDL_INIT_JOYSTICK);

    if (SDL_NumJoysticks() > 0) {
        SDL_JoystickOpen(0);
    }
    

#endif
}

int MapJoyToScancode(int joyButton) {
    switch(joyButton) {
        case SDL_CONTROLLER_BUTTON_DPAD_UP:    return SDLK_UP;
        case SDL_CONTROLLER_BUTTON_DPAD_DOWN:  return SDLK_DOWN;
        case SDL_CONTROLLER_BUTTON_DPAD_LEFT:  return SDLK_LEFT;   
        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT: return SDLK_RIGHT;
        case SDL_CONTROLLER_BUTTON_CROSS:      return SDLK_RETURN; 
        case SDL_CONTROLLER_BUTTON_TRIANGLE:     return SDLK_ESCAPE;
        case SDL_CONTROLLER_BUTTON_CIRCLE: return SDLK_u;
        default: return SDLK_UNKNOWN;
    }
}