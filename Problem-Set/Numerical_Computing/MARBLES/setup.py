# filename : setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("qq16_tim",["qq16_tim.pyx"])]

setup(
name = 'qq16_tim app',
cmdclass = {'build_ext':build_ext},
ext_modules = ext_modules
)