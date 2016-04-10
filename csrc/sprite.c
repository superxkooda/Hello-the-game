#include "common.h"
typedef struct _pixel {
	char node;
	int color;
	int index;
	//int (*length)();
	struct _pixel * head;
	struct _pixel * next;
	struct _pixel * previous;

}pixel;

typedef struct _sprite {
	pixel* content[MAX_LINES];
	int orentation; //0 horizontal 1 vertical
	int height;
	int width;
	void (*draw)();
	void (*rotate)();
	void (*reset)();
	int color;
	cCoord offset;
}sprite;

void _reset(sprite * this)
{
	int i =0;
	while(this->content[i]->index!=-1)
	{
		this->content[i]=this->content[i]->head;
		i++;
	}
	
}
static pixel * _rotateNext(pixel * head, int speed)
{
	pixel * current = head;
	int i;
	for(i=0;i<speed;i++)
	{
		current=current->next;
	}
	return current;
}
static pixel * _rotatePrevious(pixel * head, int speed)
{
	pixel * current = head;
	int i;
	for(i=0;i<speed;i++)
	{
		current=current->previous;
	}
	return current;
}
static void _rotate(sprite * this,int speed)
{	
	int i =0;
	while(this->content[i]->index!=-1)
	{
		if(speed > 0)
		{
			this->content[i]=_rotateNext(this->content[i], speed);
		}	
		else
		{
			speed=speed*-1;
			this->content[i]=_rotatePrevious(this->content[i], speed);
			
		}
		i++;
	}
}
//change color before draw if set
static void _colorOn(sprite* this)
{
	if(this->color!=-1)
	attron(COLOR_PAIR(this->color));
}
static void _colorOff(sprite* this)
{
	if(this->color!=-1)
	attroff(COLOR_PAIR(this->color));
}
//draw functions. one for virtical and one for horizontal
static void _drawRow(int x, int y,int X, int Y, pixel * head)
{
	//loop through pixel list of a row and print out each node. 
	//our pixel list is a cirular list with the last node pointing at the first.
	pixel * current = head;
	int start = head->index, i=0;
	do
	{
		char a = current->node;
		mvprintw((y+(i*Y)),(x+(i*X)),"%c",a);
		current=current->next;
		i++;
	}while(current->index!=start);
}

static void _drawH(sprite * this)
{
	_colorOn(this);
	int i =0;
	while(this->content[i]->index!=-1)
	{
		_drawRow(this->offset.x, (this->offset.y+i),1,0, this->content[i]);
		i++;
	}
	_colorOff(this);
}

static void _drawV(sprite * this)
{
	_colorOn(this);
	int i;
	for(i=0; i<this->height;i++)
	{
		_drawRow(this->offset.x+(this->height-i), (this->offset.y),0,1, this->content[i]);
	}
	_colorOff(this);
}

void _spritePushRow(sprite * this, char row[])
{
	pixel * target;
	int i =0;
	while(this->content[i]->index !=-1) //only add to empty rows
		i++;
	target=this->content[i];
	this->height=(i+1);

	pixel *current=target, *head= target;
	i =0;
	while(row[i])
	{	
		if(i!=0)
		{
			current->next=malloc(sizeof(pixel));
			current->next->previous=current;
			current=current->next;
		}
		current->index=i;
		current->node=row[i];
		current->color=0;
		current->head=head;
		i++;
	}
	
	if(this->width<(i+1))
		this->width=1;
	
	current->next=head;
	head->previous=current;
}
//----------------------------------------------------------
//constructor
void  _sprite(sprite * target, int orentation){
	target->width=
	target->height=0;
	target->color=-1;
	target->offset.x=0;
	target->offset.y=0;
	int i;
	for ( i =0; i < MAX_LINES; i++ )
	{
		target->content[i]=malloc(sizeof(pixel));
		target->content[i]->index=-1;
		target->content[i]->node='\0';
		target->content[i]->next=target->content[i];
		target->content[i]->previous=target->content[i];
	}
	target->orentation=orentation;
	if(orentation == 0)
		{
			target->draw=_drawH;
		}
	else if( orentation ==1)
		{
			target->draw=_drawV;
		}

	target->rotate=_rotate;
	target->reset=_reset;
}

//destructors
void static spriteDelete(pixel * head)
{
	pixel *next=head->next;
	int start=head->index;
	while(next->index!=start)
	{
		head->next=next->next;
		free(next);
		next=head->next;
	}
	free(head);

}
void sprite_(sprite * target)
{
	int i;
	for(i=0;i<MAX_LINES;i++)
	{
		if(target->content[i]->index!=-1)
			spriteDelete(target->content[i]);
		else
			free(target->content[i]);
	}
}
