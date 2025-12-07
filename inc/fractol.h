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

# define KEY_ESC 65307
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
	int		size_x;
	int		size_y;
	void	*main;
	void	*win;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		max_iter;
	t_view	v;
}	t_mlx;


//MINILIBX
void		start_mlx(t_mlx *mlx);
void		*freedom(t_mlx	*mlx);
void		main_hooks(t_mlx *mlx);
int			close_win(int keycode, t_mlx *mlx);
void		put_pixel(t_mlx *mlx, int x, int y, int color);
t_complex	map_pxl_to_complex(int x, int y, t_view *view);
int			create_color(int function);


//MANDELBROT
int			mandelbrot(t_complex constant, size_t max_iter);
void		draw_mandelbrot(t_mlx *mlx, t_view *v);

//JULIA
void	draw_julia(t_mlx *mlx, t_view *v);

// COMPLEX NUMBERS
t_complex	new_complex(double re, double im);
t_complex	add_complex(t_complex a, t_complex b);
t_complex	sustract_complex(t_complex a, t_complex b);
t_complex	mult_complex(t_complex a, t_complex b);
t_complex	power_complex(t_complex z, int power);
double		complex_mod(t_complex z);

#endif
