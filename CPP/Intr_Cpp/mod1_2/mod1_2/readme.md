#Instruction for Modularity code, Version 1.2

Author: Pan Zhang (panzhang@itp.ac.cn)
        [weighted part by Cheng Shi (shicheng1995@hotmail.com)]

Companion paper: "Scalable detection of statistically significant communities and hierarchies: message-passing for modularity" by Pan Zhang and Cristopher Moore

"Robust Data Clustering Using Message Passing" by Cheng Shi,Yanchen Liu and Pan Zhang


Release time 13/04/2017
Website for updates: http://panzhang.net


##Copyright notice
Copyright 2017 Pan Zhang (panzhang@itp.ac.cn). mod is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.
SBM is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

## Contents and Compiling
###contents of the file "mod.zip" are:
bm.cpp
bm.h
Makefile
mod1_2.cpp
zrg.cpp
zeg.h
README.md
networks

### OSX & *Nix
Simply use 'make' inside 'src' dir.
Compiling and running has been tested under g++ version 4.4 and 4.2.

##Function:
* Find retrieval state from Botltzmann distribution with Modularity as Hamiltonian in the graph(available for weighted and directed networks in version 1.2). 
* Determine number of groups by maximizing retrieval modularity.
* Hierarchical clustering
* Detected partition can be written into a data file using --confi option.


##Running examples:
Some network files are in folder "networks/"

1.)Modular detection on "network of Zakary's Karate club", file karate.gml, 
using two groups (q=2). The obtained partition will be recorded into "result.dat".
The partition is the list of label for each node, labeling starts from 0:

```bash	
./mod1_2 retrieval -l networks/karate.gml -q2  --confi result.dat
```

2.) Select number of groups on "network of political books", file polbooks.gml,
and record the result into result.dat:
```bash	
./mod1_2 select -l networks/polbooks.gml -D1 --confi result.dat
```

3.) Select number of groups on network generated by Stochastic Block Model with 
q*=4 groups, q4sbm.gml, and record result into result.dat:
```bash	
./mod1_2 select -l networks/sq4sbm.gml --confi result.dat
```

4.) Find hierarchical structure of network file polblogs.gml, and write the final 
devision (bottom level in the dendrogram) into result.dat.
```bash	
./mod1_2 hiera -l networks/polblogs.gml --confi result.dat
```
Output are number of nodes in subgroups of dendogram.
If "*" is displayed, it means the subgraph has no internal structure, acts like a random graph.
If "(x)" is displayed, with x denoting a number, it means the subgraph will be divided into 
x sub-sub-groups in the next level of dendogram.

5.) Modular detection on unweighted network q2sbm.gml, using specified beta value 1.5, with verbose 2:
```bash
./mod1_2 infer -l networks/q2sbm.gml -q2 -b 1.5 -v2
```

6.)Modular detection on weighted network q3sbm.gml which has 3 groups, and the beta is automatically balanced
```bash
./mod1_2 infer -l networks/q2sbm.gml -q3 -k1
```

6.)Find hierarchical structure of weighted network on LFR module, and the beta is automatically balanced
```bash
./mod1_2 hiera -L networks/wLFR.dat -k1
```

-------------------------------------------------------------
Note that different seeds of random number generator could give slightly different result.
The lastest version of this program is at http://panzhang.net.
