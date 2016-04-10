#ifndef SPRITE_H 
#define SPRITE_H 
typedef struct _pixel_ {
	char node;
	int color;
	int index;
	struct _pixel * head;
	struct _pixel_ * next;
	struct _pixel_ * previous;

}pixel;

typedef struct _modifier_{
	int mode;//animation type
	int steps;//how many times do we do this action before stopping or repeting
	int repeat;//0 no 1 yes
	int index;
	cCoord movement;//x,y movement to be animated
	struct _modifier_ * next;
	struct _modifier_ * previous;
	

}modifier;

typedef struct _sprite_ {
	pixel * content[MAX_LINES];
	int orentation; //0 horizontal 1 vertical
	int height;
	int width;
	void (*draw)();
	void (*rotate)();
	void (*reset)();
	//void (*animate)();//will call the appropriate animation
	//modifier * movements;
	int color;
	cCoord offset;
}sprite;


void  _sprite(sprite *, int);
void sprite_(sprite *);
void _spritePushRow(sprite * , char []);
#endif
