from distutils.core import setup, Extension

#the c module
hello_mod = Extension("hello", ["hello_py.c", "c-sources/hello.c"])

setup(name = "hello", ext_modules=[hello_mod])
