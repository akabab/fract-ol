/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:52:18 by ycribier          #+#    #+#             */
/*   Updated: 2015/02/09 17:53:33 by ycribier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# define TREE_CONST_A		-2.1
# define TREE_CONST_BI		1.1
# define TREE_ORIGIN_A		0
# define TREE_ORIGIN_BI		2
# define TREE_ZOOM	1.09

typedef struct s_env	t_env;
typedef struct s_z		t_z;

void		tree(t_env *e);
void		branch(int deep, t_z start, t_z next, t_env *e);
void		init_tree(t_env *e);

#endif
