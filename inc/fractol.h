/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamberger12 <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:52:55 by bamberger12       #+#    #+#             */
/*   Updated: 2025/10/29 11:52:56 by bamberger12      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "Libft/libft.h"
# include <math.h>

# define MANDELBROT 0
# define JULIA 1
# define KEY_ESC 65307
# define ZOOM_IN 65451
# define ZOOM_OUT 65453
# define KEY_UP 65362
# define KEY_DOWN 65364
# define ON_DESTROY 17
# define WHITE 0xFFFFFFFF
# define BLACK 0x00000000
# define BLUE 0x000000FF
# define WIDTH 800
# define HEIGHT 800

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}	t_point;

typedef struct s_view
{
	t_complex	min;
	t_complex	max;
}	t_view;

typedef struct s_mlx
{
	int			size_x;
	int			size_y;
	void		*main;
	void		*win;
	void		*img;
	void		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			max_iter;
	int			fractal_type;
	t_complex	c;
	t_complex	scale;
	t_view		v;
}	t_mlx;

//MINILIBX
void		start_mlx(t_mlx *mlx);
void		*freedom(t_mlx	*mlx);
void		main_hooks(t_mlx *mlx);
int			close_win(int keycode, t_mlx *mlx);
void		put_pixel(t_mlx *mlx, int x, int y, int color);
t_complex	scale_complex(t_view *v);
int			create_color(int function);
void		draw_it(t_mlx *mlx, t_view *v, int fractal);

//MANDELBROT
int			mandelbrot(t_complex constant, size_t max_iter);

//JULIA
int			julia(t_complex z, size_t max_iter, t_complex julia_const);
t_complex	map_pxl(int x, int y, t_complex scale, t_view v);

// COMPLEX NUMBERS
t_complex	new_complex(double re, double im);
t_complex	add_complex(t_complex a, t_complex b);
t_complex	sustract_complex(t_complex a, t_complex b);
t_complex	mult_complex(t_complex a, t_complex b);
t_complex	power_complex(t_complex z, int power);
double		complex_mod(t_complex z);
double		ft_atof(char *s);
void		pls_exit(void);

#endif
