# filename : setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext

ext_modules = [Extension("Sample2",["Sample2.pyx"])]

setup(
name = 'Sample2 app',
cmdclass = {'build_ext':build_ext},
ext_modules = ext_modules
)