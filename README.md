# Un-hinged

Repository for Unhinged, a dating app I built using C++ for CS 32 during Winter 2022 at UCLA.

## Overview

The NachenSmall Software Corporation, which has traditionally only built software for running senior-citizen bingo games, has decided to pivot into a new area. They’ve decided to disrupt the online matchmaking market and build a new text-based dating app called Unhinged.

This command-line program reads data from a text file (members.txt) and returns the most compatible partners that pass a certain numeric threshold. Compatibility is determined according to translators.txt which maps attributes to other compatible attributes based on their similarity. The program then performs the match-making via a RadixTree data structure and suggests partners. It supports up to 100,000 member profiles in the daatabase.

## Language Used

C++

## Building (MacOS)

First, clone the repository and change into the appropriate directory:

```
$ git clone https://github.com/snigdha-kansal/Un-hinged.git
$ cd Un-hinged
```

Next, build the executable:

```
$ make
```

Finally, run the app using:

```
$ ./main
```

Follow the terminal prompt to enter the user's email address and indicate the desired number of shared attributes.

Press the `Return` key to exit the app.
