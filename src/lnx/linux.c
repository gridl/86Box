#include <stdint.h>
#include <wchar.h>
#include <stdlib.h>
#include "../video/video.h"
#include "../platform/platform.h"

uint64_t timer_freq = 0;
int scale = 0;
HWND            ghwnd;
int             recv_key[272];

int main(int argc, char** argv) {
	return 0;
}

void hline(BITMAP *b, int x1, int y, int x2, uint32_t col)
{
        if (y < 0 || y >= buffer32->h)
           return;

        for (; x1 < x2; x1++)
                ((uint32_t *)b->line[y])[x1] = col;
}

void destroy_bitmap(BITMAP *b)
{
        free(b);
}

BITMAP *create_bitmap(int x, int y)
{
        BITMAP *b = malloc(sizeof(BITMAP) + (y * sizeof(uint8_t *)));
        int c;
        b->dat = malloc(x * y * 4);
        for (c = 0; c < y; c++)
        {
                b->line[c] = b->dat + (c * x * 4);
        }
        b->w = x;
        b->h = y;
        return b;
}

void updatewindowsize(int x, int y)
{

}

void startblit()
{
//        SDL_LockMutex(ghMutex);
}

void endblit()
{
//        SDL_UnlockMutex(ghMutex);
}

uint64_t timer_read()
{
        return 0;
}

unsigned int get_ticks()
{
        return 0;
}

void delay_ms(unsigned int ms)
{
}

void get_executable_name(wchar_t *s, int size)
{

}

wchar_t *plat_get_string_from_id(int i)
{
//        return (wchar_t *) win_language_get_string_from_id(i);
        return NULL;
}

void set_window_title(wchar_t *s)
{

}

void msgbox_error(HWND hwndParent, int i)
{

}

void plat_msgbox_error(int i)
{
        msgbox_error(ghwnd, i);
}


void status_settext(char *str)
{
}

void update_status_bar_icon(int tag, int active)
{

}

void update_status_bar_icon_state(int tag, int state)
{

}

void cdrom_eject(uint8_t id)
{
}

void cdrom_reload(uint8_t id)
{

}

void removable_disk_unload(uint8_t id)
{
}

void removable_disk_eject(uint8_t id)
{
}

void removable_disk_reload(uint8_t id)
{
}

void *dynld_module(const char *name, dllimp_t *table)
{
        return 0;
}


void dynld_close(void *handle)
{
}
