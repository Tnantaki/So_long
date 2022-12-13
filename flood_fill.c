#include "solong.h"

void  flood_fill(char **tab, t_point size, t_point begin)
{

}

int main(void)
{
	t_point size = {20, 7};
	char *zone[] =
	{
	"00000000110000000011",
	"00000000111111111111",
	"00000111111111111111",
	"11111111111111110000",
	"00000000000000000000",
	"11111111111111111111",
	"11100000000000000000",
	"11110000111000000000",
	};
	printf("x:%d , y:%d\n", size.x, size.y);
	for (int j=0; j<size.y; j++)
	{
		for (int i=0; i<size.x; i++)
			printf("%c", zone[j][i]);
		printf("\n");
	}
}
