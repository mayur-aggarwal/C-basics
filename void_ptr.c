#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _dummy
{
	int i;
	char c;
	float f;
}dummy_t;

typedef enum _type{
	TYPE_INT = 1,
	TYPE_CHAR = 2,
	TYPE_FLOAT = 3,
}type_e;

//Method 1
void func(void *value, type_e type)
{
    int i;
    float f;
    switch(type)
    {
        case TYPE_INT:
        	i = 12345;
        	*((int *)value) = i;
    	break;
    	case TYPE_FLOAT:
    	    f = 0.896;
    	    *((float *)value) = f;
    	break;
    	default:
    	    printf("Not valid input\n");
    	break;
    }
}

int main()
{
	dummy_t *s = (dummy_t *)malloc(sizeof(dummy_t));
	if(s == '\0')
	{
		printf("Memory allocation is failed\n");
		return 0;
	}
	func(&s->i, TYPE_INT);
	printf("s->i = %d\n", s->i);
	func(&s->f, TYPE_FLOAT);
	printf("s->f = %f\n", s->f);
	return 0;
}

