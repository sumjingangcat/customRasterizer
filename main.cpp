#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void line(int x0, int x1, int y0, int y1, TGAImage image, TGAColor color);

int main(int argc, char** argv) {
	TGAImage image(100, 100, TGAImage::RGB);
	
	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image

	line(50, 60, 20, 30, image, red);

	image.write_tga_file("line2.tga");
	return 0;
}

// write a drawing line function
void line(int x0, int x1, int y0, int y1, TGAImage image, TGAColor color){
	int x_len = x1 > x0 ? x1 - x0 : x0 - x1;
	int yDelta_per_x = (y1 - y0) / x_len;

	int xDelta_per_t = 10;
	
	for (int xDelta = 0; xDelta < x_len; xDelta++){
		float txDelta = xDelta / xDelta_per_t;
		float tyDelta = yDelta_per_x / xDelta_per_t;
		for (int tIndex = 0; tIndex < xDelta_per_t; tIndex++){
			image.set(x0 + xDelta + tIndex * txDelta, y0 + yDelta_per_x + tIndex * tyDelta, color);
		}
	}
	
}