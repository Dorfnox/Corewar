# Corewar

A 42 School Silicon Valley algorithms project.

![Corewar](https://imgflip.com/gif/2drtfn)

## Getting Started

### Downloading

```
git clone https://github.com/Dorfnox/Corewar.git corewar
```
### Installing

Running 'make' in the directory will install all dependencies and create two executables.
- asm (for the assembler, which compiles .s files into .cor files)
- dsm (for the disassembler, which de-compules .cor files into .s files)
- corewar (for the virtual machine, which runs the main program)

```
make
```

### Running

#### Assembler

First, compile some champions using the assembler.
Champions are written in a psuedo-assembly language, and are followed with a ".s".
Champions are located in the 'assembler/tests/champs/' folder.

```
./asm assembler/tests/champs/Gagnant.s
```

Assembled files can now be used with the main executable, corewar, but for bonus we also made a...

#### Disassembler

```
./dsm assembler/tests/champs/Gagnant.cor
```

It will de-compile the .cor byte-code back into its .s formatted file.
Some information will be lost in the de-compile process, such as 'labels'.

#### Corewar

The main executable. It handles up to four champions.
To see how the actual corewar operates, please reference the corewar.pdf as it is quite a lot of information to copy here.

```
./corewar assembler/tests/champs/Gagnant.cor
```

To access the visualizer, run:

```
./corewar -viz assembler/tests/champs/Gagnant.cor
```

There are many options, including:

```
-dump number		To dump memory after 'number' of cycles.
-s			To set the optional speed of the game (1 is fast, 100 is slow)
-viz			To display the visualizer.
-n playernum champion	To set the player number of the Champion.
-a / -activity		To show an activity monitor, which displays the number of processes being executed in the current cycle.
-r / -rainbow [1 - 10]	To enable rainbow mode, with optional speed of 1 to 10.
```

An example of a complex corewar request.
It will:

Run corewar.

Enable the vizualizer.

Turn on the activity monitor.

Run three different champions with the given champion number for Gagnant (4) and 42 (2), but helltrain will take the next available champion number (in this case because 4 and 2 were taken, it will take 1).

Enable rainbow mode.

Dump after 10000 cycles.

Set the game speed to 10, which is somewhat fast (The fastest would be to just not set a speed).

```
./corear -viz -a -n 3 assembler/tests/champs/Gagnant.cor assembler/tests/champs/helltrain.cor -n 2 assember/tests/champs/42.cor -rainbow -dump 10000 -s 10
```

## Resources / External Links

* [Minilibx](https://github.com/qst0/ft_libgfx) - 42's own custom, minimal graphics library
* [Wikipedia](https://en.wikipedia.org/wiki/Core_War) - Wikipedia entry for Corewar

## Authors

* **Dago Montoya** - *Instruction Expert* - [Dago Montoya](https://github.com/dmontoyain/)
* **Rafael Zarate** - *Assembler Visionary* - [Rafael Zarate](https://github.com/RafaelZarate)
* **Kyle Mckee** - *Lead Supervisor* - [Kyle Mckee](https://github.com/KyleAMcKee)
* **Brendan Pierce** - *Program creator* - [Brendan Pierce](https://github.com/Dorfnox/)

## License

MIT License.

## Acknowledgments

* Fellow coders at 42, especially including:
* **Isamar Hodge** - *Lead Consultant* - [Isamar Hodge](https://github.com/isahodge)

