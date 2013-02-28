# filename : setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("qq57_tim",["qq57_tim.pyx"])]

setup(
name = 'qq57_tim app',
cmdclass = {'build_ext':build_ext},
ext_modules = ext_modules
)