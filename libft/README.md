*Ce projet a été créé dans le cadre du cursus 42 par misasant.*

### Description
`libft` est une bibliothèque C personnelle qui ré-implémente une partie des fonctions standards de la libc, ainsi que des fonctions utilitaires supplémentaires.
Les objectifs principaux sont de mieux comprendre :
- la gestion de la mémoire (pointeurs, `malloc`/`free`)
- la manipulation des chaînes de caractères
- la gestion des cas limites et des erreurs
- les listes chaînées

### Instructions

#### Compilation
Compiler la bibliothèque :
- `make`

Cela génère :
- `libft.a`

Nettoyer les fichiers objets :
- `make clean`

Supprimer tous les fichiers compilés :
- `make fclean`

Recompiler complètement :
- `make re`


   Contenu de la bibliothèque (détaillé)
   
 Fonctions type libc
Tests de caractères : ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint
Chaînes : ft_strlen, ft_strchr, ft_strrchr, ft_strncmp, ft_strnstr, ft_strlcpy, ft_strlcat
Mémoire : ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp
Conversions / casse : ft_atoi, ft_toupper, ft_tolower
Aides d’allocation : ft_calloc, ft_strdup

  Fonctions additionnelles
Création/modification de chaînes : ft_substr, ft_strjoin, ft_strtrim, ft_split, ft_itoa
Fonctions avec callback : ft_strmapi, ft_striteri
Écriture sur un descripteur de fichier : ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd

 partie 3 (listes chaînées)
Si implémenté :

ft_lstnew, ft_lstadd_front, ft_lstsize, ft_lstlast, ft_lstadd_back
ft_lstdelone, ft_lstclear, ft_lstiter, ft_lstmap

 Ressources
Pages de manuel : man memcpy, man memmove, man strlcat, man strlcpy, man atoi, etc.
 Sujet PDF libft (consignes 42)
 
 
Utilisation de l’IA
J’ai utilisé une assistance IA pour :

relire mes implémentations (logique, cas limites, conformité au comportement attendu)
expliquer le comportement des fonctions de la partie 3 (listes chaînées)
