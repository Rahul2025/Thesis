# filename : setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("qq23_tim",["qq23_tim.pyx"])]

setup(
name = 'qq23_tim app',
cmdclass = {'build_ext':build_ext},
ext_modules = ext_modules
)