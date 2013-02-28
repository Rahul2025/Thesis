# filename : setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("qq46_tim",["qq46_tim.pyx"])]

setup(
name = 'qq46_tim app',
cmdclass = {'build_ext':build_ext},
ext_modules = ext_modules
)