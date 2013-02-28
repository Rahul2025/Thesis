# filename : setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("qq34_tim",["qq34_tim.pyx"])]

setup(
name = 'qq34_tim app',
cmdclass = {'build_ext':build_ext},
ext_modules = ext_modules
)