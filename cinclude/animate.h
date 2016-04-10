#ifndef ANIMATE_H 
#define ANIMATE_H
//this structure will be used to keep track
//of the current animation and the future 
//animations
typedef struct _animation {
	int index;
	int steps;
	int loop;`
	void (*animate)();
	struct _animation * next;
	shtruct _animation * previous;
}animation;
void endCheck(sprite*)
void slide(sprite*);
#endif
