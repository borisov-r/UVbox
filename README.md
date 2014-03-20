## UVbox

UV box for PCB manufacturing

### Architecture

```
UVbox ~
        \
        |---/structure - 3D models of the mechanical parts
            |
            |--- /parts - parts to build the box
        |
        |---/software  - software for control and measurement
            |
            |--- /bin - compiled libraries (if needed)
            |--- /src - main source code
                    |
                    |--- /js    - all java script code here
                    |--- /css   - look better with css
                    |--- /db    - reddis is ok probably
            |--- /test - unit tests
            |
        \--- hardware  - all the schematics and layouts eventually
            |
            |--- /gerbers
            |--- /kicad
            |--- /documentation
            |
```

### Usefull links

 * [node-webkit](https://github.com/rogerwang/node-webkit)
 * [LightTable](http://www.lighttable.com/)

### Authors
 * Radoslav Borisov
 * [Georgi Kyuchukov](mailto:gkyuchukov86@gmail.com)
 * [Martin](mailto:martin@libtec.org)


### [License](http://en.wikipedia.org/wiki/Beerware)

```
/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <phk@FreeBSD.ORG> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */
```
