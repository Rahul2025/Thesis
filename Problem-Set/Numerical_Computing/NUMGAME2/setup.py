# filename : setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("qq29_tim",["qq29_tim.pyx"])]

setup(
name = 'qq29_tim app',
cmdclass = {'build_ext':build_ext},
ext_modules = ext_modules
)