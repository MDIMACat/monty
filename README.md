# The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty byte code files

files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line.

## Compilation

gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

## Output
 - Any output must be printed on stdout
 - Any error message must be printed on stderr

## AUTHORS
Siduduzile SNenhlanhla Mdima
Tshepiso Moilwe
