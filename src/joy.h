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

#ifndef __HHOP_JOY_H__
#define __HHOP_JOY_H__

#define SDL_CONTROLLER_AXIS_LEFTX 0
#define SDL_CONTROLLER_AXIS_LEFTY 1
#define SDL_CONTROLLER_AXIS_RIGHTX 2
#define SDL_CONTROLLER_AXIS_RIGHTY 3
#define SDL_CONTROLLER_BUTTON_CROSS 2
#define SDL_CONTROLLER_BUTTON_CIRCLE 1
#define SDL_CONTROLLER_BUTTON_SQUARE 3
#define SDL_CONTROLLER_BUTTON_TRIANGLE 0
#define SDL_CONTROLLER_BUTTON_BACK 10
#define SDL_CONTROLLER_BUTTON_START 11
#define SDL_CONTROLLER_BUTTON_LEFTSHOULDER 4
#define SDL_CONTROLLER_BUTTON_RIGHTSHOULDER 5
#define SDL_CONTROLLER_BUTTON_DPAD_UP 8
#define SDL_CONTROLLER_BUTTON_DPAD_DOWN 6
#define SDL_CONTROLLER_BUTTON_DPAD_LEFT 7
#define SDL_CONTROLLER_BUTTON_DPAD_RIGHT 9

void InitJoystick();
int MapJoyToScancode(int joyButton);

#endif