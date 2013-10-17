#include <stdio.h>
#include <stdlib.h>
#include <cairo.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void
randomize_color(cairo_t *cr)
{
  double red, green, blue, alpha;

  red = (double)rand()/RAND_MAX;
  green = (double)rand()/RAND_MAX;
  blue = (double)rand()/RAND_MAX;
  alpha = (double)rand()/RAND_MAX;

  cairo_set_source_rgba (cr, red, green, blue, alpha);
}

int
main(int argc, char *argv[]) {
  int i;
  int loops = 128*1024;
  cairo_surface_t *surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 800, 80);
  cairo_t *cr = cairo_create (surface);

  srand(0xdeadbeef);

  while (loops--) {
    randomize_color (cr);
    cairo_paint (cr);
  }

  cairo_destroy (cr);
  cairo_surface_write_to_png (surface, "paint.png");
  cairo_surface_destroy (surface);
  return 0;
}

