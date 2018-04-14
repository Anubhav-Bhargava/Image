from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext
from Cython.Build import cythonize

ext=Extension("ela",
            sources=["mywrapper.pyx"],
            include_dirs=[".","source" , "/usr/local/include/opencv", "/usr/local/include"],
            language="c++",
            library_dirs=['/usr/local/lib', 'source', '/usr/lib'],
            libraries=['opencv_core', 'opencv_highgui'])

setup(name = 'ela', ext_modules=cythonize([ext]), cmdclass = {'build_ext': build_ext},)
