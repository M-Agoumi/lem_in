/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melalj <melalj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:07:41 by melalj            #+#    #+#             */
/*   Updated: 2020/01/17 20:33:08 by melalj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	parser_free(t_parse *p)
{
	t_parse *walk;
	t_parse *hold;

	walk = p;
	while (walk)
	{
		hold = walk;
		walk = walk->next;
		free(hold->line);
		free(hold);
	}
}

// void	paths_log(t_paths *paths)
// {
// 	size_t i;
// 	size_t j;

// 	ft_printf("n_paths : %d\n", paths->n_paths);
// 	i = -1;
// 	while (++i < paths->n_paths)
// 	{
// 		ft_printf("path n : %d | path_size %d\n", i, paths->flow[i].size);
// 		j = -1;
// 		while (++j < paths->flow[i].size)
// 		{
// 			ft_printf("%s ", paths->flow[i].edge[j]->node_src->name);
// 		}
// 		ft_printf("%s\n", paths->flow[i].edge[j - 1]->node_dst->name);
// 	}
// }

// void	paths_sort(t_graph *graph)
// {
// 	size_t i;
// 	t_paths *paths;

// 	paths = graph->flows;
// 	ft_printf("n_paths : %d\n", paths->n_paths);
// 	i = -1;
// 	while (++i < paths->n_paths)
// 	{
// 		ft_printf("path n : %d | path_size %d\n", i, paths->flow[i].size);
// 		if (i && paths->flow[i].size < paths->flow[i - 1].size)
// 			ft_printf("need to be sorted\n");
// 	}
// }

int		main(void)
{
	t_parse		*pp;
	t_node		**nodes;
	int			nodes_c;
	int			i;
	t_graph		*g;
	t_node		**refs;
	size_t		n_ants;


	i = 0;
	pp = get_lines(&nodes_c);

	n_ants = (size_t)ft_atoi(pp->line);
	refs = (t_node **)malloc(sizeof(t_node *) * nodes_c);
	nodes = h_table(refs, pp, nodes_c);
	edges_fill(nodes, pp, nodes_c);
	parser_free(pp);

	g = graph_init(refs, nodes, nodes_c, 0);
	ft_printf("\n\nstarting solving process\n\n");
	bfs(g);

	// graph_draw(g);

	return (0);
}
