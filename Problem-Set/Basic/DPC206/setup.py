# filename : setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("qq4_tim",["qq4_tim.pyx"])]

setup(
name = 'qq4_tim app',
cmdclass = {'build_ext':build_ext},
ext_modules = ext_modules
)