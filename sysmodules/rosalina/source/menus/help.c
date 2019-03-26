/*
*   This file is part of Luma3DS
*   Copyright (C) 2016-2019 Aurora Wright, TuxSH
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
*       * Requiring preservation of specified reasonable legal notices or
*         author attributions in that material or in the Appropriate Legal
*         Notices displayed by works containing it.
*       * Prohibiting misrepresentation of the origin of that material,
*         or requiring that modified versions of such material be marked in
*         reasonable ways as different from the original version.
*/

#include <3ds.h>
#include "menu.h"
#include "menus/help.h"
#include "memory.h"
#include "draw.h"
 
 
Menu helpMenu = {
    "Help menu",
    .nbItems = 2,
    {
        { "im real dumb", METHOD, .method = &helpMenu_imrealdumb },
        { "im dumb", METHOD, .method = &helpMenu_imdumb },
    }

 
 while(!(waitInput() & BUTTON_B) && !terminationRequest);

};


void helpMenu_imrealdumb(void)
{
    Draw_Lock();
    Draw_ClearFramebuffer();
    Draw_FlushFramebuffer();
    Draw_Unlock();

    do
    {
        Draw_Lock();
        posY = Draw_DrawString(10, posY + SPACING_Y, COLOR_WHITE, "thats right");

        Draw_FlushFramebuffer();
        Draw_Unlock();
    }
    while(!(waitInput() & BUTTON_B) && !terminationRequest);
}


void helpMenu_imdumb(void)
{
    Draw_Lock();
    Draw_ClearFramebuffer();
    Draw_FlushFramebuffer();
    Draw_Unlock();

    do
    {
        Draw_Lock();
        posY = Draw_DrawString(10, posY + SPACING_Y, COLOR_WHITE, "wrong");

        Draw_FlushFramebuffer();
        Draw_Unlock();
    }
    while(!(waitInput() & BUTTON_B) && !terminationRequest);
}
