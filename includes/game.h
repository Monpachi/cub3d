/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchan <vchan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:44:43 by vchan             #+#    #+#             */
/*   Updated: 2023/03/29 15:44:44 by vchan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define INTRO "./textures/intro.xpm"
# define CREDIT "./textures/credit.xpm"
# define GAMEOVER "./textures/game_over.xpm"

# ifdef __linux__
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_UP 65362
#  define KEY_LEFT 65361
#  define KEY_DOWN 65364
#  define KEY_RIGHT 65363
#  define KEY_SHIFT 65505
#  define ESC 65307
#  define ESP 32
# else
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_Q 12
#  define KEY_E 14
#  define KEY_UP 126
#  define KEY_LEFT 123
#  define KEY_DOWN 125
#  define KEY_RIGHT 124
#  define ESC 53
# endif

void	img_pix_put(t_img *img, int x, int y, int color);
int		game_start(t_data *data);

/*			INTRODUCTION.C		*/

void	introduction_of_game(t_data *data, t_game *game);
void	credit_of_game(t_data *data, t_game *game);

/*          KEYS.C          */
int		keys_main(int key_code, t_data *data);
int		key_release_main(int keysym, void *data);
int		angle_manager(int keysim, t_player *p1);
int		key_press(int key, t_data *data);

/*			CAMERA.C		*/

void	right_key(t_data *data);
void	left_key(t_data *data);

/*			MOVE.C			*/

void	w_key(t_data *data);
void	s_key(t_data *data);
void	a_key(t_data *data);
void	d_key(t_data *data);
void	right_key(t_data *data);
void	left_key(t_data *data);

#endif
