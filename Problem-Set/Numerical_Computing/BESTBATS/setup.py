# filename : setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("qq22_tim",["qq22_tim.pyx"])]

setup(
name = 'qq22_tim app',
cmdclass = {'build_ext':build_ext},
ext_modules = ext_modules
)