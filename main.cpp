#include "tgaimage.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);

int main(int argc, char** argv) {
	TGAImage image(100, 100, TGAImage::RGB);
	
	line(13, 20, 80, 40, image, white); 
	line(20, 13, 40, 80, image, red); 
	line(80, 40, 13, 20, image, red);
	line(40, 30, 90, 40, image, white);
	line(30, 40, 90, 40, image, white);
	line(80, 80, 80, 80, image, red);
	line(80, 40, 80, 60, image, red);

	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("line.tga");
	return 0;
}

// write a drawing line function
void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color){

	// By passing &image, we can modify the object : "image"

	// thinking of its efficiency
	// if you set dt as 0.1f, point line will be occured
	
	int y_len = y1 > y0 ? (y1 - y0) : (y0 - y1);
	int x_len = x1 > x0 ? (x1 - x0) : (x0 - x1);

	// Consider when line is stright
	float dy_dt = y_len == 0 ? 1 : 1.f / y_len;
	float dx_dt = x_len == 0 ? 1 : 1.f / x_len;

	if (dy_dt == 1 || dx_dt == 1){
		for (int i = 0; i < x_len + 1; i++){
			for (int j = 0; j < y_len + 1; j++){
				image.set(x0 + i, y0 + j, color);
			}
		}
		return;
	}

	// By checking whether dt as dy_dt or dx_dt, we can consider hole in lines
	float dt = dy_dt < dx_dt ? dy_dt : dx_dt;

	// We need to check if have same coordinate pair(no matter its order) then show same line position(drawings)
	// I set the order as small comes first!
	if (x0 > x1){
		for (float t = 0; t < 1.f; t += dt){ // thinking of dt (difference in time)
			int x = x0 + (x1 - x0) * t;
			int y = y0 + (y1 - y0) * t;
			image.set(x, y, color);
		}
	}
	else{
		for (float t = 0; t < 1.f; t += dt){ // thinking of dt (difference in time)
			int x = x1 + (x0 - x1) * t;
			int y = y1 + (y0 - y1) * t;
			image.set(x, y, color);
		}
	}
}