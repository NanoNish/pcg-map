DUNGEON Generator

Intro

It is a pseudorandom procedural generaator for generating rooms and corridors. It is a barebones project to learn and explore procedural generation. This right now is being generated in 2D but with increase in variables a complex generation can be easily made. One simple example would be to add a third variable say Temperature for each room and then based on that temperature we can place the map of that room corresponding to that Temperature. Things to keep in mind is that even though procedural generation seems simple with less variables, it gets more and more complicated wih each parameter addition and there has to be that many more set of rules to be added.

The idea behind this simple model is a generating a path for a player playing a roguelike game in which a dungeon is being generated with rooms of certain types connected through corridors. Right now there is just a single path but we can generate a tree like structure of rooms which right now are in form of an array. What this means is that we can have a variety of geometries for generating very different worlds.

Running

Simply make an exe and run it using the GNU C++ compiler
Or run it on https://www.onlinegdb.com/online_c++_compiler online :)
