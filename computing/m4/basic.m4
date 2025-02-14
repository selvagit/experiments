
m4_dnl https://web.mit.edu/gnu/doc/html/m4_4.html

m4_dnl create a macro 
m4_define(`foo', `Hello world. ')
foo

m4_dnl argument list 
m4_define(`exch', `$2, $1')
exch(arg1,arg2)

m4_dnl zero argument 
m4_dnl m4_define(`test', "Macro name: $0")
m4_dnl test

m4_dnl number of arguments 
m4_define(`nargs', `$#')
nargs()
nargs(arg1, arg2, arg3)

m4_dnl special arguments
m4_define(`echo', `$*')
echo(arg1,    arg2, arg3 , arg4)

m4_define(`echo', `$@')
echo(arg1,    arg2, arg3 , arg4)

m4_define(`echo1', `$*')
m4_define(`echo2', `$@')
m4_define(`foo', `This is macro `foo'.')
echo1(foo)
echo2(foo)

m4_dnl deleting a macro 
m4_define('foo','expansion text')
foo
m4_undefine('foo')
foo


