#include "lemin.h"

static void		delete_troom(void *data, size_t size)
{
	t_node	*tmp;
	t_room	*r;

	(void)size;
	tmp = (t_node*)data;
	ft_memdel((void**)&tmp->key);
	r = (t_room*)tmp->data;
	ft_lstdel(&r->links, delete_tlist_node);
	ft_memdel((void**)&r->name);
	ft_memdel((void**)&r);
	ft_memdel((void**)&tmp);
}

static void		delete_way(void *data, size_t size)
{
	t_node	*tmp;
	void	*r;

	(void)size;
	tmp = (t_node*)data;
	ft_memdel((void**)&tmp->key);
	r = tmp->data;
	ft_memdel((void**)&r);
	ft_memdel((void**)&tmp);
}

void			clean_up(t_s *s, t_list **arr)
{
	int		i;

	i = -1;
	while (++i < s->map.num_links)
		ft_lstdel(&arr[i], delete_tlist_node);
	ft_memdel((void**)&arr);
	ft_lstdel(&s->rooms_names, delete_tlist_node);
	ft_lstdel(&s->map.file, delete_tlist_node);
	ft_memdel((void**)&(s->map.start->name));
	ft_memdel((void**)&(s->map.start));
	ft_memdel((void**)&(s->map.end->name));
	ft_memdel((void**)&(s->map.end));
	free_hash_map(s->all_rooms, delete_troom);
	free_hash_map(s->way_to_end, delete_way);
}
