# filename : setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("qq38_tim",["qq38_tim.pyx"])]

setup(
name = 'qq38_tim app',
cmdclass = {'build_ext':build_ext},
ext_modules = ext_modules
)