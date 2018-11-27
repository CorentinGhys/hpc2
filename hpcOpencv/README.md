# TP de HPC sur OpenCV en Python

- si besoin de compiler opencv + cuda :

```
$ nix-shell --cores 8 --run ""
```


- exécuter un script :

```
$ nix-shell --run "hpcOpencvFake.py parrots.jpg out_parrots.png"
```


- exécuter interactivement :

```
$ nix-shell 

[nix-shell]$ ./scripts/hpcOpencvFake.py parrots.jpg out_parrots.png
```


