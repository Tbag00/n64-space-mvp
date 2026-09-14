// per iniziare facciamo un cerchio bianco come framebuffer
#include "display.h"
#include "dragonfs.h"
#include "rdpq.h"
#include "rdpq_font.h"
#include "rdpq_mode.h"
#include "rdpq_sprite.h"
#include "rdpq_text.h"
#include "sprite.h"
#include <libdragon.h>
#include <math.h>

typedef struct {
  int x;
  int y;
} point_t;

/*display variables*/
static display_context_t display;
static resolution_t res = RESOLUTION_256x240;
static bitdepth_t bit = DEPTH_32_BPP;
static uint32_t num_buffers = 2;
static filter_options_t filters = FILTERS_RESAMPLE;

int main(void) {

  display_init(res, bit, num_buffers, GAMMA_NONE, filters);
  rdpq_init();
  joypad_init();
  dfs_init(DFS_DEFAULT_LOCATION);

  joypad_inputs_t inputs;

  /*ship*/
  point_t ship_position = {0, 0};
  sprite_t* ship = sprite_load("rom:/ship.sprite");
  int speed = 10;

  /*testo per debug temporaneo*/
  rdpq_font_t *pfont = rdpq_font_load_builtin(FONT_BUILTIN_DEBUG_MONO);
  rdpq_text_register_font(1, pfont);

  while (1) {
    display = display_get();

    rdpq_attach_clear(display, NULL);
    rdpq_set_scissor(0, 0, 256, 200); // dedico parte dello schermo al debug

    joypad_poll();
    inputs = joypad_get_inputs(JOYPAD_PORT_1);
    ship_position.x += inputs.stick_x / speed;
    ship_position.y -= inputs.stick_y / speed;
    ship_position.x = (ship_position.x % 256 + 256) % 256;
    ship_position.y = (ship_position.y % 240 + 240) % 240;

    rdpq_sprite_blit(ship, ship_position.x, ship_position.y,NULL);

    // test
    // disegno un rettangolo ciano per test
    // rdpq_set_mode_fill(RGBA32(0, 206, 209, 255));
    // rdpq_fill_rectangle(ship_position.x, ship_position.y, ship_position.x + 20,
    //                     ship_position.y + 20);

    // Debug rectangle
    rdpq_set_scissor(0, 200, 256, 240);

    rdpq_set_mode_fill(RGBA32(30, 30, 30, 255));
    rdpq_fill_rectangle(0, 200, 256, 240);
    rdpq_text_printf(NULL, 1, 10, 215, "X: %d, Y: %d", ship_position.x,
                     ship_position.y);

    rdpq_detach_show();
  }
}