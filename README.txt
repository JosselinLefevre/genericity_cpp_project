
Niveau 7 :

Pour résoudre le problème du labyrinthe, on utilise d'abord les fonctions utilisées précédemment pour obtenir une carte de distance, sous forme d'une image partielle : 

0  1  2  3    
         4    
   7  6  5    
   8     6    
10 9          
   10 11 12 13

Le but étant d'obtenir une image partielle de ce type : 

1  1  1  1    
         1    
   1  1  1    
   1          
   1          
   1  1  1  1 

Afin d'obtenir le chemin le plus court jusqu'à un point d'arrivée donné (obtenu grâce à une fonction qui retourne le point dont la valeur est 3 sur l'image d'entrée), une méthode efficace consiste à partir du point d'arrivée et de progresser sur le chemin dans l'ordre décroissant des valeurs. Cela permet de ne pas avoir à prendre en compte les chemins qui n'aboutissent pas vers le point d'arrivée.


Il suffit de faire une boucle similaire à la dernière boucle de l'algorithme de calcul de distance : on initialise les valeurs de la matrice de sortie à 0, on met le point d'arrivée dans une queue de points, puis on effectue une boucle tant que la queue n'est pas vide.

A chaque itération de la boucle, on récupère le premier point de la queue et on met sa valeur à 1 dans l'image de sortie. Si le point voisin est valide et que sa valeur est inférieure à celle du point courant, c'est alors le point suivant du plus court chemin, et on peut l'ajouter dans la queue.

Une fois la boucle terminée, on obtient une image avec des 1 sur le plus court chemin et des 0 à tous les autres points. On peut alors la reconvertir en image partielle.