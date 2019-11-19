# social_network_graph
This project aims to compute some known algorithms on maximum cliques, widely used in graph theory to identify communities, groups... We will implement Barabàsi-Albert's algorithm, Bron Kerbosch's algorithm and more

# COMMENT EXECUTER NOTRE PROGRAMME 
Notre programme s'exécute sur un terminal Linux. Le programme livré est déja compilé. 
Il peut être exécuté de 3 manières en fonction du code que l'on souhaite tester


 # 1ère METHODE: Tester l'ALGO 1 (une probabilité et un nombre de sommets fixé)
-----------------------------------------------------------------------------------
Pour tester l'algo 1, il faut se trouver dans le repertoire du projet (social_network_graph)
ensuite taper par exemple:

 ./app 18 0.5

cette commande permet de créer un graphe de 18 sommets dans lequel la probablité d'avoir une arête entre une paire
de sommet est 0.5

# 2ème METHODE: Tester l'ALGO 2 (Barabasi-Albert)
-----------------------------------------------------------------------------------
il faut se trouver dans le repertoire du projet (social_network_graph)
ensuite taper par exemple:

./app 7

Pour créer un graphe de 7 sommets dont la probabilité d'avoir une arête entre une paire de sommet et donnée par l'algorithme 
de Barabasi-Albert.


# 3ème METHODE: ALGO 3 Tester L'énumération des cliques et calcul de l'ordre de degenerescence
--------------------------------------------------------------------------------------
il faut se trouver dans le repertoire du projet (social_network_graph)
ensuite taper:

./app

Le resultat de la clique sera affiché et vous pourrez appuyer sur une touche pour calculer l'ordre de degenerescence