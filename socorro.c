#include <stdio.h>

struct a{
	char *c;
};
int main(){
	struct a b;

	b.c = "MM\nMM";
	printf("%s\n", b.c);
}
