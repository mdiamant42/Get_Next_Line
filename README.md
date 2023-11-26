Get Next Line
Ce projet, réalisé dans le cadre de l'école 42, a pour objectif de créer une fonction capable de lire une ligne depuis un descripteur de fichier, jusqu'à la prochaine occurrence d'un caractère de fin de ligne ('\n').

Description
La fonction get_next_line a pour but de parcourir un fichier ligne par ligne et de retourner cette ligne à chaque appel de la fonction.

Utilisation
Le programme peut être utilisé comme suit :

Inclure le fichier get_next_line.h dans votre programme.
Appeler la fonction get_next_line en lui passant un descripteur de fichier valide en premier argument.
La fonction renvoie 1 lorsqu'une ligne a été lue, 0 lorsqu'il n'y a plus de lignes à lire, et -1 en cas d'erreur.
Compilation
Compiler votre programme avec les fichiers sources de get_next_line.

Exemple de compilation : gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c your_file.c

Ressources
Pour plus d'informations sur le projet Get Next Line, consultez le sujet fourni par l'école 42.
