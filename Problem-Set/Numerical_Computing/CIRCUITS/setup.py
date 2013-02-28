# filename : setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("qq73_tim",["qq73_tim.pyx"])]

setup(
name = 'qq73_tim app',
cmdclass = {'build_ext':build_ext},
ext_modules = ext_modules
)