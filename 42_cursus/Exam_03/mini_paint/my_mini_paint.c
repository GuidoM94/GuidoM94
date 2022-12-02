#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct	s_zone
{
	int		width;
	int		height;
	char	background;
} 				t_zone;

typedef struct	s_shape
{
	char	type;
	float	x;
	float	y;
	float	radius;
	char	color;
	struct s_shape	*next;
}				t_shape;

int		str_error(void)
{
	write(1, "Error: Operation file corrupted\n", 32);
	return (1);
}

int		clear_all(FILE *file, char *drawing)
{
	fclose(file);
	if (drawing)
		free(drawing);
	return (1);
}

int		check_zone(t_zone *zone)
{
	return (zone->width > 0 && zone->width <= 300 && zone->height > 0 && zone->height <= 300);
}

int		check_shape(t_shape *shape)
{
	return (shape->radius > 0.00000000 && (shape->type == 'c' || shape->type == 'C'));
}

int		get_zone(FILE *file, t_zone *zone)
{
	int scan_ret;

	if ((scan_ret = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->background)) != 3)
		return (0);
	if (!check_zone(zone))
		return (0);
	if (scan_ret == -1)
		return (0);
	return (1);
}

char	*paint_background(t_zone *zone)
{
	char	*drawing;
	int		i = 0;

	if (!(drawing = malloc(sizeof(char *) * (zone->width * zone->height))))
		return (NULL);
	while (i < zone->width * zone->height)
		drawing[i++] = zone->background;
	return (drawing);
}

int	in_circle(float x, float y, t_shape *shape)
{
	float	distance;

	distance = sqrtf(powf(x - shape->x, 2.) + powf(y - shape->y, 2.));
	if (distance <= shape->radius)
	{
		if ((shape->radius - distance) < 1.00000000)
			return (2);
		return (1);
	}
	return (0);
}

void	draw_shape(char **drawing, t_shape *shape, t_zone *zone)
{
	int i = -1, j, ret;

	while (++i < zone->height)
	{
		j = -1;
		while (++j < zone->width)
		{
			ret = in_circle((float)j, (float)i, shape);
			if ((shape->type == 'c' && ret == 2) || (shape->type == 'C' && ret))
				(*drawing)[(i * zone->width) + j] = shape->color;
		}
	}
}

int		draw_shapes(FILE *file, char **drawing, t_zone *zone)
{
	t_shape	tmp;
	int		scan_ret;

	while ((scan_ret = fscanf(file, "%c %f %f %f %c\n", &tmp.type, &tmp.x, &tmp.y, &tmp.radius, &tmp.color)) == 5)
	{
		if (!check_shape(&tmp))
			return (0);
		draw_shape(drawing, &tmp, zone);
	}
	if (scan_ret != -1)
		return (0);
	return (1);
}

void	draw_drawing(char *drawing, t_zone *zone)
{
	int	i = -1;

	while (++i < zone->height)
	{
		write(1, drawing + (i * zone->width), zone->width);
		write(1, "\n", 1);
	}
}

int		main(int argc, char **argv)
{
	t_zone	zone;
	char	*drawing;
	FILE	*file;

	zone.width = 0;
	zone.height = 0;
	zone.background = 0;
	if (argc != 2){
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if (!(file = fopen(argv[1], "r")))
		return (str_error());
	if (!get_zone(file, &zone))
		return (clear_all(file, NULL) && str_error());
	if (!(drawing = paint_background(&zone)))
		return (clear_all(file, NULL) && str_error());
	if (!draw_shapes(file, &drawing, &zone))
		return (clear_all(file, drawing) && str_error());
	draw_drawing(drawing, &zone);
	clear_all(file, drawing);
	return (0);
}
