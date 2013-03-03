# filename : setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("qq56_tim",["qq56_tim.pyx"])]

setup(
name = 'qq56_tim app',
cmdclass = {'build_ext':build_ext},
ext_modules = ext_modules
)