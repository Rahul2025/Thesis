# filename : setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("qq6_tim",["qq6_tim.pyx"])]

setup(
name = 'qq6_tim app',
cmdclass = {'build_ext':build_ext},
ext_modules = ext_modules
)