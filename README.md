# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de les copiers dans le repertoire `build` avec l'application `bibliotheque`

# Nouvelles fonctionnalités ajoutées
. Confirmation avant suppression d'un livre (Interface utilisateur)
. Tri des livres par titre ou par auteur (Gestion des données)

# Vieille Technologie
## Question 1
Dans ce projet, j'ai utilisé les lambdas et les pointeurs intelligents, et si je me rappelle bien, on n'a pas beaucoup vu ça en classe.
Les lambdas permettent de définir directement une petite fonction à l'intérieur d'un appel, par exemple dans std::sort ou find_if. Ça 
rend le code plus clair et évite de créer une fonction séparée juste pour comparaison.

## Question 2
Si la bibliothèque devra contenir des millions de livres, le C++ ne sera plus aussi idéal tout seul.
Pour aider le C++, je pourrais utiliser une base de données come PostgreSQL (Je l'ai trouvé en ligne en recherchant des technologies 
qu'on utilise avec le C++, honnêtement j'en ai jamais fait ou utilisé) pour stocker tous les livres et utilisateurs, et une API REST (Faite en python
avec Flask (trouvé en ligne aussi) ou en Node.js) pour gérer les accès à ces données.
Si on veut utiliser le C++, c'est mieux de l'utiliser pour la partie LOCALE, puisque le C++ est vraiment rapide et puisqu'elle pourrait communiquer avec l'API via des requêtes HTTP en JSON