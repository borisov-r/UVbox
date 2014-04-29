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
        |---/firmware - Arduino serial communication
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
 * [nodeclipse](http://www.nodeclipse.org/updates)
 * [LightTable](http://www.lighttable.com/)
 * [Java Script Styleguide](https://github.com/airbnb/javascript)
 * [Markdown-Cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)
 * [Minimal arduino library for processing serial commands](http://awtfy.com/2011/05/23/a-minimal-arduino-library-for-processing-serial-commands/)

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
