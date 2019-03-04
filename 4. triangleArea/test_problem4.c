
#include "problem4.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char* argv[])
{
	Triangle t1;
	Triangle t2;

	t1.a.x = 0;
	t1.a.y = 0;
	t1.b.x = 1;
	t1.b.y = 0;
	t1.c.x = 0;
	t1.c.y = 1;

	t2.a.x = 0;
	t2.a.y = 0;
	t2.b.x = -2;
	t2.b.y = 0;
	t2.c.x = 0;
	t2.c.y = -2;

	assert(getLarger(t1, t2).c.y ==-2);

  // Put anything here that you think is appropriate to test your function
  // You can define triangles here, since the struct is declared in the header
  

  return(0);
}

