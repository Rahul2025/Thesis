# filename : setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("qq90_mem",["qq90_mem.pyx"])]

setup(
name = 'qq90_mem app',
cmdclass = {'build_ext':build_ext},
ext_modules = ext_modules
)