# filename : setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("Sample3",["Sample3.pyx"])]

setup(
name = 'Sample3 app',
cmdclass = {'build_ext':build_ext},
ext_modules = ext_modules
)