//practice code, not working
int safe_log(char *message)
{
	log_mutex a();
	if ( message == NULL )
  	return -1
  
  log_message(message);
  return 0;
}
/*
Mutex ref here - RAII
Since we are using Mutex the resoursce allocated to a() will autoamtically get
freed after the code goes out of scope.

if the if condition is false, the code will break out of function and resource
will be freed from the memory, only beacuse we are using RAII
*/


int logger_safe_log(char *message)
{
	mutex_take(&a);

	if (message == NULL)
  	return -1;

	log_message(message);
  
  mutex_give(&a);
  return 0;
}

/*
This won't work as we are using give and take, we are assigning memory using that
The memory will only be freed once we have the give() work.

If the message is null we will be thrown out of the scope and the resource will still 
be allocated
*/

#include <stdio.h>

static char * COOKIE = "the cookie string";

void get_cookie(char *cookie)
{
  cookie = COOKIE;
}

int main()
{
  char *my_cookie;
  
  get_cookie(my_cookie);

  printf("%s", my_cookie);
  return 0;
}


#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

struct values {
    uint8_t  u8;
    uint32_t u32;
    uint16_t u16;
};

/*
answer is 12 bytes
u8 takes 1 byte space - 0 index
u32 takes 4 bytes space -  4 index requires 3 offset
u16 takes 2 bytes space - index 8 0 offset, 2 alignment

Largest alignment = 4 (from u32)

Final size must be multiple of 4

Next multiple of 4 after 10 = 12
*/

struct X {
    uint16_t a;
    uint32_t b;
    uint8_t  c;
    uint64_t d;
};

/*
a = 2 bytes
b = 4 bytes
c = 1 byte
d = 8 byte

total = 24 
*/
void main() {

    printf("sample1:\n");

    struct values v;
    printf("u8 %zu\n", sizeof(v.u8));//1
    printf("u16 %zu\n", sizeof(v.u16));//2
    printf("u32 %zu\n", sizeof(v.u32));//4
    printf("struct %zu\n", sizeof(v));//12

    printf("\n");
}