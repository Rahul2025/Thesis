# filename : setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("qq137_tim",["qq137_tim.pyx"])]

setup(
name = 'qq137_tim app',
cmdclass = {'build_ext':build_ext},
ext_modules = ext_modules
)