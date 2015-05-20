/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:52:18 by ycribier          #+#    #+#             */
/*   Updated: 2015/05/19 18:50:09 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include "structs.h"

// # define KEY_UP			65362
// # define KEY_DOWN		65364
// # define KEY_LEFT		65361
// # define KEY_RIGHT		65363
// # define KEY_ESC		65307
// # define KEY_SHIFT_L	65505
// # define KEY_SHIFT_R	65505
// # define KEY_MORE		65451
// # define KEY_LESS		65453
// # define KEY_SPACE		32
// # define KEY_W			119
// # define KEY_A			97
// # define KEY_S			115
// # define KEY_D			100
// # define KEY_C			99
// # define KEY_T			116
// # define KEY_RESET		114
// # define KEY_1			49
// # define KEY_2			50
// # define KEY_3			51
// # define KEY_4			52
// # define KEY_5			53

# define SCROLL_UP		4
# define SCROLL_DOWN	5

enum {
	KEY_A                    = 0X00,
	KEY_S                    = 0X01,
	KEY_D                    = 0X02,
	KEY_F                    = 0X03,
	KEY_H                    = 0X04,
	KEY_G                    = 0X05,
	KEY_Z                    = 0X06,
	KEY_X                    = 0X07,
	KEY_C                    = 0X08,
	KEY_V                    = 0X09,
	KEY_B                    = 0X0B,
	KEY_Q                    = 0X0C,
	KEY_W                    = 0X0D,
	KEY_E                    = 0X0E,
	KEY_R                    = 0X0F,
	KEY_Y                    = 0X10,
	KEY_T                    = 0X11,
	KEY_1                    = 0X12,
	KEY_2                    = 0X13,
	KEY_3                    = 0X14,
	KEY_4                    = 0X15,
	KEY_6                    = 0X16,
	KEY_5                    = 0X17,
	KEY_EQUAL                = 0X18,
	KEY_PLUS                 = 0X18,
	KEY_9                    = 0X19,
	KEY_7                    = 0X1A,
	KEY_MINUS                = 0X1B,
	KEY_8                    = 0X1C,
	KEY_0                    = 0X1D,
	KEY_RIGHTBRACKET         = 0X1E,
	KEY_O                    = 0X1F,
	KEY_U                    = 0X20,
	KEY_LEFTBRACKET          = 0X21,
	KEY_I                    = 0X22,
	KEY_P                    = 0X23,
	KEY_L                    = 0X25,
	KEY_J                    = 0X26,
	KEY_QUOTE                = 0X27,
	KEY_K                    = 0X28,
	KEY_SEMICOLON            = 0X29,
	KEY_BACKSLASH            = 0X2A,
	KEY_COMMA                = 0X2B,
	KEY_SLASH                = 0X2C,
	KEY_N                    = 0X2D,
	KEY_M                    = 0X2E,
	KEY_PERIOD               = 0X2F,
	KEY_GRAVE                = 0X32,
	KEY_KEYPADDECIMAL        = 0X41,
	KEY_KEYPADMULTIPLY       = 0X43,
	KEY_KEYPADPLUS           = 0X45,
	KEY_KEYPADCLEAR          = 0X47,
	KEY_KEYPADDIVIDE         = 0X4B,
	KEY_KEYPADENTER          = 0X4C,
	KEY_KEYPADMINUS          = 0X4E,
	KEY_KEYPADEQUALS         = 0X51,
	KEY_KEYPAD0              = 0X52,
	KEY_KEYPAD1              = 0X53,
	KEY_KEYPAD2              = 0X54,
	KEY_KEYPAD3              = 0X55,
	KEY_KEYPAD4              = 0X56,
	KEY_KEYPAD5              = 0X57,
	KEY_KEYPAD6              = 0X58,
	KEY_KEYPAD7              = 0X59,
	KEY_KEYPAD8              = 0X5B,
	KEY_KEYPAD9              = 0X5C
};

/*
** keycodes for keys that are independent of keyboard layout
*/
enum {
	KEY_RETURN                    = 0X24,
	KEY_TAB                       = 0X30,
	KEY_SPACE                     = 0X31,
	KEY_DELETE                    = 0X33,
	KEY_ESCAPE                    = 0X35,
	KEY_COMMAND                   = 0X37,
	KEY_SHIFT                     = 0X38,
	KEY_CAPSLOCK                  = 0X39,
	KEY_OPTION                    = 0X3A,
	KEY_CONTROL                   = 0X3B,
	KEY_RIGHTSHIFT                = 0X3C,
	KEY_RIGHTOPTION               = 0X3D,
	KEY_RIGHTCONTROL              = 0X3E,
	KEY_FUNCTION                  = 0X3F,
	KEY_F17                       = 0X40,
	KEY_VOLUMEUP                  = 0X48,
	KEY_VOLUMEDOWN                = 0X49,
	KEY_MUTE                      = 0X4A,
	KEY_F18                       = 0X4F,
	KEY_F19                       = 0X50,
	KEY_F20                       = 0X5A,
	KEY_F5                        = 0X60,
	KEY_F6                        = 0X61,
	KEY_F7                        = 0X62,
	KEY_F3                        = 0X63,
	KEY_F8                        = 0X64,
	KEY_F9                        = 0X65,
	KEY_F11                       = 0X67,
	KEY_F13                       = 0X69,
	KEY_F16                       = 0X6A,
	KEY_F14                       = 0X6B,
	KEY_F10                       = 0X6D,
	KEY_F12                       = 0X6F,
	KEY_F15                       = 0X71,
	KEY_HELP                      = 0X72,
	KEY_HOME                      = 0X73,
	KEY_PAGEUP                    = 0X74,
	KEY_FORWARDDELETE             = 0X75,
	KEY_F4                        = 0X76,
	KEY_END                       = 0X77,
	KEY_F2                        = 0X78,
	KEY_PAGEDOWN                  = 0X79,
	KEY_F1                        = 0X7A,
	KEY_LEFT                      = 0X7B,
	KEY_RIGHT                     = 0X7C,
	KEY_DOWN                      = 0X7D,
	KEY_UP                        = 0X7E
};

/*
** ISO keyboards only
*/
enum {
	KEY_ISO_SECTION               = 0x0A
};

/*
** JIS keyboards only
*/
enum {
	KEY_JIS_YEN                   = 0X5D,
	KEY_JIS_UNDERSCORE            = 0X5E,
	KEY_JIS_KEYPADCOMMA           = 0X5F,
	KEY_JIS_EISU                  = 0X66,
	KEY_JIS_KANA                  = 0x68
};

/*
**		keys.c
*/
int						key_press(int keycode, t_env *e);
int						key_release(int keycode, t_env *e);
void					manage_keys(t_env *e);
t_keys					*init_keys(void);

/*
**		keys_handlers.c
*/
void					keys_power_handler(int keycode, t_env *e);
void					keys_zoom_handler(int keycode, t_env *e);
void					keys_arrows_handler(int keycode, t_env *e);
void					keys_color_handler(int keycode, t_env *e);

#endif
