#ifndef __BLEND__H__
#define __BLEND__H__

#define MODE_MULTIPLY 1
#define MODE_SCREEN 2

#define CALC_COLOR(color, alpha) ((1.0 - (alpha / MAX_RGB_DOUBLE)) * (double) color)

#define ALPHA_COMPOSITE_COLOR_CHANNEL2(method, color1, alpha1, color2, alpha2) COMPOSITE_ ## method(CALC_COLOR(color1, alpha1), CALC_COLOR(color2, alpha2) * (alpha1 / MAX_RGB_DOUBLE))

#define BLEND_NORMAL(c1, c2) ((c1) + (c2))
#define BLEND_MULTIPLY(c1, c2, a1, a2) (((c1) * (c2)) + (c2) * ((a1 / MAX_RGB_DOUBLE)) + (c1) * ((a2 / MAX_RGB_DOUBLE)))
#define BLEND_SCREEN(c1, c2) (255 - ((255 - (c1)) * (255 - (c2)) / 255.0 ))
#endif
