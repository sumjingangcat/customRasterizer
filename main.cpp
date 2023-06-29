#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void line(int x0, int x1, int y0, int y1, TGAImage &image, TGAColor color);

int main(int argc, char** argv) {
	TGAImage image(100, 100, TGAImage::RGB);
	
	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image

	line(50, 60, 20, 60, image, red);

	image.write_tga_file("line5.tga");
	return 0;
}

// write a drawing line function
void line(int x0, int x1, int y0, int y1, TGAImage &image, TGAColor color){
	for (float t = 0; t < 1.f; t += 0.01f){ // thinking of dt (difference in time)
		int x = x0 + (x1 - x0) * t;
		int y = y0 + (y1 - y0) * t;
		image.set(x, y, color);
	}
}