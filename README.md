# Get_next_line
# Résumé :
Ce projet a pour but de vous faire coder une fonction qui renvoit une ligne
terminée par un retour à la ligne lue depuis un descripteur de fichier.
# Partie Obligatoire
- Des appels successifs à votre fonction get_next_line doivent vous permettre de
lire l’entièreté du texte disponible sur le file descriptor, une ligne à la fois, jusqu’au
EOF.
- Votre programme doit compiler avec le flag -D BUFFER_SIZE=xx Ce define doit
être utilisé dans vos appels de read du get_next_line, pour définir la taille du
buffer. Cette valeur sera modifiée lors de l’évaluation et par la moulinette.
- Compilation : gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c
get_next_line_utils.c
- Votre read DOIT utiliser le BUFFER_SIZE pour lire depuis un fichier ou depuis
le stdin.
- Nous considérons que get_next_line a un comportement indeterminé si, entre
deux appels, le file descriptor change de fichier alors qu’EOF n’a pas été atteint
sur le premier fichier.
