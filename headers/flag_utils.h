#ifndef FLAG_UTILS_H
# define FLAG_UTILS_H

# ifndef FLAG_STORE
#  define FLAG_STORE int
# endif

void	set_f(FLAG_STORE *f_store, FLAG_STORE flag, int value);
int		is_f(FLAG_STORE *f_store, FLAG_STORE flag);

#endif
