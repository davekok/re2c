DESCRIPTION
-----------

re2php (forked from re2c) is a free and open-source lexer generator for PHP.

Its main goal is generating fast lexers: at least as fast as their reasonably
optimized hand-coded counterparts. Instead of using traditional table-driven
approach, re2php encodes the generated finite state automata directly in the
form of conditional jumps and comparisons. The resulting programs are faster
and often smaller than their table-driven analogues, and they are much easier
to debug and understand. re2php applies quite a few optimizations in order to
speed up and compress the generated code.

Another distinctive feature is its flexible interface: instead of assuming a
fixed program template, re2php lets the programmer write most of the interface
code and adapt the generated lexer to any particular environment.


DOCKER
------

You can use the docker prebuild image to quickly use re2php.

## bash

```
docker run --rm -it -v $PWD:/src -w /src davekok/re2php file.y.php -o file.php
```

## Powershell

```
docker run --rm -it -v "${PWD}:/src" -w /src davekok/re2php file.y.php -o file.php
```

## Windows Command

```
docker run --rm -it -v "%CD%:/src" -w /src davekok/re2php file.y.php -o file.php
```

EXAMPLE
-------

A simple example

```
<?php

/*!re2c
    digit  = [0-9];
    number = digit+;
*/

function lex(string $YYBUFFER, int $YYCURSOR = 0): int
{
    $YYMARKER = 0;
    /*!re2c
    re2c:yyfill:enable  = 0;

    * { return 1; }

    number {
        printf("number\n");
        return 0;
    }

    */
}

lex("1024");
lex(";]");
```

BUGS
----
Please report any bugs and send feature requests to https://github.com/davekok/re2php/issues.


AUTHORS
-------
Re2c was originally written by Peter Bumbulis <peter@csg.uwaterloo.ca>.
Since then many people contributed to the project.
Re2c current maintainers are Ulya Trofimovich <skvadrik@gmail.com> and Dan Nuffer <nuffer@users.sourceforge.net>.
Re2php tries to remain as much a possible compatible with the upstream code base.
